/*
 * Smart_Home_Application_master.c
 *
 * Created: 13/12/2020 19:04:00
 *  Author: 20114
 */ 

#include "UART.h"
#include "SPI.h"
#include "LCD.h"

#define F_CPU 8000000
#include <util/delay.h>

int main(void)
{
    uint8 RX_data=0;
	uint8 Ret_data=0;
	UART_init();
	LCD_init();
	
	SPI_master_init();
	SPI_master_init_trans();
	_delay_ms(1000);
	
	/*UART_TX_string("Hello\r");
	UART_TX_string("please chose a or A led1 \r");
	UART_TX_string("please chose b or B led2 \r");
	UART_TX_string("please chose C or c led3 \r");
	UART_TX_string("please chose d or D led4 \r");*/
	
    while(1)
    {
		RX_data=UART_RX();
		if(RX_data)
		{
			Ret_data=SPI_master_transiver(RX_data);
			LCD_clear();
			LCD_writeChar(RX_data);
			RX_data=0;
		}
		
    }
}