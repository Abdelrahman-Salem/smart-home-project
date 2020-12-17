/*
 * SPI.c
 *
 * Created: 13/12/2020 15:32:15
 *  Author: 20114
 */ 
#include "SPI.h"

void SPI_master_init(void)
{
	DIO_SET_BIN_DIR(DIO_PORTB,DIO_PIN4,DIO_BIN_OUTPUT);   /* ss */
	DIO_SET_BIN_DIR(DIO_PORTB,DIO_PIN5,DIO_BIN_OUTPUT);   /* mosi */
	DIO_SET_BIN_DIR(DIO_PORTB,DIO_PIN6,DIO_BIN_INPUT);   /* miso */
	DIO_SET_BIN_DIR(DIO_PORTB,DIO_PIN7,DIO_BIN_OUTPUT);   /* clu */
	
	SPI->SPCR=0x53;
	
}

void SPI_sleve_init(void)
{
	DIO_SET_BIN_DIR(DIO_PORTB,DIO_PIN4,DIO_BIN_INPUT);   /* ss */
	DIO_SET_BIN_DIR(DIO_PORTB,DIO_PIN5,DIO_BIN_INPUT);   /* mosi */
	DIO_SET_BIN_DIR(DIO_PORTB,DIO_PIN6,DIO_BIN_OUTPUT);   /* miso */
	DIO_SET_BIN_DIR(DIO_PORTB,DIO_PIN7,DIO_BIN_INPUT);   /* clu */
	
	SPI->SPCR=0x40;
}

void SPI_master_init_trans(void)
{
	DIO_SET_BIN_VAL(DIO_PORTB,DIO_PIN4,DIO_BIN_LOW);
}

void SPI_master_ter_trans(void)
{
	DIO_SET_BIN_VAL(DIO_PORTB,DIO_PIN4,DIO_BIN_HIGT);
}

uint8 SPI_master_transiver(uint8 data)
{
	uint8 rec_data;
	SPI->SPDR=data;
	while (GET_BIT(SPI->SPSR,7)==0);
	
	rec_data=SPI->SPDR;
	return rec_data;
}