/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Uart_PBcfg.h Nxp S32K14x LPUART driver
Author: Steven
******************************************************************************/
#ifndef UART_PBCFG_H
#define UART_PBCFG_H

#include "Std_Types.h"
#include "Uart_Define.h"

#define UART0           (0x4006A000UL)
#define UART1           (0x4006B000UL)
#define UART2           (0x4006C000UL)

#define UART_RX_LBKD    0x1FFF /* Lin Break Detected */
#define UART_ERR_FE     0x8001 /* Framing Error */
#define UART_ERR_ORE    0x8002 /* Receiver Overrun Error */
#define UART_ERR_PE     0x8004 /* Parity Error */

typedef struct
{
    uint32 UartHw;
    uint32 CTRL;  /* ValidBits:1F2C0003 */
    uint32 STAT;  /* ValidBits:32000000 */
    uint32 BAUD;  /* ValidBits:1F001FFF */
    uint16 Reserved;
    uint8 URxCh;
    uint8 UTxCh;
    void(*URxCallback)(uint8 URxCh, uint16 RxByte);
    void(*UTxCallback)(uint8 UTxCh, boolean TxIdle);
} Uart_ChCfgType;

typedef struct
{
    const Uart_ChCfgType* ChCfg;
    uint8 ChNum;
} Uart_ConfigType;

#endif

