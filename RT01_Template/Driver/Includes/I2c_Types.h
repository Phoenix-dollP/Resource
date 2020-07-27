/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : I2c_Types.h I2c Master driver For Nxp S32K14x Series LPI2C
Author: Steven 
******************************************************************************/
#ifndef I2C_TYPES_H
#define I2C_TYPES_H

#include "Std_Types.h"

/* Error Definition */
#define I2C_E_OK            (0x00)  /* 通讯完成 */
#define I2C_E_BUS_ERROR     (0x01)  /* 总线电平错误 */
#define I2C_E_ARB_LOST      (0x02)  /* 总线仲裁错误 */
#define I2C_E_CALL_NACK     (0x04)  /* 呼叫从机无应答 */
#define I2C_E_DATA_NACK     (0x08)  /* 发送数据无应答 */
#define I2C_E_INTERNAL      (0x10)  /* 其它错误 */

typedef enum
{
    I2C_STOPPED,
    I2C_BUSIDLE,
    I2C_READING,
    I2C_WRITING,
} I2c_StatusType;

#endif

