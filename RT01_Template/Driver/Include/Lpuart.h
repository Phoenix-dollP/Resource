/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Port.h For Nxp S32K14x Series
Author: Steven 
******************************************************************************/

#ifndef LPUART_H
#define LPUART_H

#include <stdint.h>

extern void Lpuart2_init(void);
extern void Lpuart2_transmit_char(char send);
extern void Lpuart2_transmit_string(char data_string[]);
extern void Lpuart2_transmit_n_size(char data_string[], uint16_t size);
extern char Lpuart2_receive_char(void);
extern void Lpuart2_receive_and_echo_char(void);


#endif
