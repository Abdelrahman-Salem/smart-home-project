/*
 * SPI.h
 *
 * Created: 13/12/2020 15:32:52
 *  Author: 20114
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "DIO.h"

void SPI_master_init(void);

void SPI_sleve_init(void);

void SPI_master_init_trans(void);

void SPI_master_ter_trans(void);

uint8 SPI_master_transiver(uint8 data);

#endif /* SPI_H_ */