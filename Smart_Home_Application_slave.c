/*
 * Smart_Home_Application_slave.c
 *
 * Created: 13/12/2020 20:25:01
 *  Author: 20114
 */ 

#include "SPI.h"
#include "LCD.h"

#define F_CPU 8000000
#include <util/delay.h>


int main(void)
{
	uint8 rec_data=0;
	uint8 tra_data=0;
	
	LCD_init();
	
	DIO_SET_BIN_DIR(DIO_PORTC,DIO_PIN0,DIO_BIN_OUTPUT);
	DIO_SET_BIN_DIR(DIO_PORTC,DIO_PIN1,DIO_BIN_OUTPUT);
	DIO_SET_BIN_DIR(DIO_PORTC,DIO_PIN2,DIO_BIN_OUTPUT);
	DIO_SET_BIN_DIR(DIO_PORTC,DIO_PIN3,DIO_BIN_OUTPUT);
	
	/*DIO_SET_BIN_DIR(DIO_PORTA,DIO_PIN0,DIO_BIN_OUTPUT);*/
	
	SPI_sleve_init();
    _delay_ms(1000);	
    while(1)
    {
          rec_data=SPI_master_transiver(tra_data);
		  //if(rec_data)
		   // DIO_TOGGLE_BIN(DIO_PORTA,DIO_PIN0);
		  if(rec_data)
		  {
			  LCD_clear();
			  LCD_writeChar(rec_data);
			  if(rec_data=='A'||rec_data=='a')
			  {
				  DIO_TOGGLE_BIN(DIO_PORTC,DIO_PIN0);
			  }
			  else if(rec_data=='B'||rec_data=='b')
			  {
				  DIO_TOGGLE_BIN(DIO_PORTC,DIO_PIN1);
			  }		
			  else if(rec_data=='C'||rec_data=='c')
			  {
		     	  DIO_TOGGLE_BIN(DIO_PORTC,DIO_PIN2);
			  }
			  else if(rec_data=='D'||rec_data=='d')
			  {
				  DIO_TOGGLE_BIN(DIO_PORTC,DIO_PIN3);
			  }
			  else
			  {
				  LCD_clear();
				  LCD_writeString("worng order !");
			  }
			  rec_data=0;		  				  
		  }		  
    }
}