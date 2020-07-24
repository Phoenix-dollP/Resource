/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : I2c.h I2c Master driver For Nxp S32K14x Series LPI2C
Author: Steven 
******************************************************************************/
#ifndef I2C_H
#define I2C_H
#ifdef __cplusplus
extern "C" {
#endif

#include "I2c_Types.h"
#include "I2c_Define.h"

#define I2C_MAJOR_VERSION       (0x00)
#define I2C_MINOR_VERSION       (0x01)
#define I2C_PATCH_VERSION       (0x00)

#define I2C_MAX_CH_NUM          (2)

extern void I2c_Init(void);
extern void I2c_DeInit(void);

extern Std_ReturnType I2c_Read(uint8 Ch, uint8 Slave, void* RxDst, uint16 Length);
extern Std_ReturnType I2c_Write(uint8 Ch, uint8 Slave, const void* TxSrc, uint16 Length);
extern void I2c_Stop(uint8 Ch);
extern I2c_StatusType I2c_GetStatus(uint8 Ch);

#ifdef __cplusplus
}
#endif
#endif

