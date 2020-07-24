/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Uart.h Nxp S32K14x LPUART driver
Author: Steven <markul@163.com>
******************************************************************************/
#ifndef UART_H
#define UART_H
#ifdef __cplusplus 
extern "C" { 
#endif

#include "Std_Types.h"
#include "Uart_Define.h"

#define UART_MAJOR_VERSION      (0x00)
#define UART_MINOR_VERSION      (0x01)
#define UART_PATCH_VERSION      (0x00)

extern void Uart_Init(void);
extern void Uart_DeInit(void);

extern Std_ReturnType Uart_Write(uint8 Ch, uint16 TxByte);

extern void Uart_SetRxFun(uint8 Ch, Std_StatusType Status);  /* 打开或关闭接收功能 */
extern void Uart_SetTxFun(uint8 Ch, Std_StatusType Status);  /* 打开或关闭发送功能 */

extern void Uart_SetRxIrq(uint8 Ch, Std_StatusType Status);  /* 打开或关闭接收&错误中断 */
extern void Uart_SetTxIrq(uint8 Ch, Std_StatusType Status);  /* 打开或关闭发送中断 */

#ifdef __cplusplus
}
#endif

#endif

