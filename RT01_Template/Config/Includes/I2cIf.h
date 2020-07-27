/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : I2cIf.h I2c Master driver interface
Author: Steven
******************************************************************************/
#ifndef I2CIF_H
#define I2CIF_H

#include "Std_Types.h"
#include "I2cIf_Define.h"

typedef enum
{
    I2CIF_STOPPED,
    I2CIF_BUSIDLE,
    I2CIF_READING,
    I2CIF_WRITING,
} I2cIf_StatusType;

extern void I2cIf_Init(void);
extern Std_ReturnType I2cIf_Read(uint8 Ch, uint8 Slave, void* RxDst, uint16 Length);
extern Std_ReturnType I2cIf_Write(uint8 Ch, uint8 Slave, const void* TxSrc, uint16 Length);
extern void I2cIf_Stop(uint8 Ch);
extern I2cIf_StatusType I2cIf_GetStatus(uint8 Ch);

#endif

