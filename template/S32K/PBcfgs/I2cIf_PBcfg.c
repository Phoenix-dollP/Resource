/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : I2cIf_PBcfg.c I2c Master driver interface
Author: Steven
******************************************************************************/
#include "Std_Types.h"
#include "I2cIf_Define.h"

#define I2CIF_E_OK         0x00  /* 通讯OK */
#define I2CIF_E_BUSY       0x01  /* 总线忙错误 */
#define I2CIF_E_NO_ACK     0x02  /* 从机无应答 */
#define I2CIF_E_ARB_LOST   0x03  /* 仲裁错误 */
#define I2CIF_E_BUS_ERROR  0x04  /* 总线错误 */
#define I2CIF_E_INT_ERROR  0x05  /* 内部错误 */

/******************************************************************************
函数名称: void I2cIf_EndCallback(uint8 UChId, uint8 Error)
函数说明: 
最后修改: Steven
******************************************************************************/
void I2cIf_EndCallback(uint8 UChId, uint8 Error)
{
    ;
}

