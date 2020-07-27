/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Uart.PBcfg Nxp S32K14x LPUART driver
Author: Steven
******************************************************************************/
#include "Uart_PBcfg.h"
#include "Ucs_Cbk.h"

static const Uart_ChCfgType UartChCfg[] = 
{
    /* Ch0: FPGA Buadrate:115200bps */
    {
        UART1,  /* UartHw */
        0x002C0000UL,  /* CTRL: RIE=1 TE=1 RE=1 */
        0x00000000UL,  /* STAT: MSBF=0 RXINV=0 BKDE=0 */
        0x0F00002BUL,  /* BAUD: OSR=16 SBR=43 bps=SPLLDIV2/((OSR+1)*SBR) */
        0,  /* Reserved */
        UCS_CH_GDCIF,  /* URxCh */
        UCS_CH_GDCIF,  /* UTxCh */
        Ucs_UartRxCbk, /* RxCallback */
        Ucs_UartTxCbk, /* TxCallback */
    },

    /* Ch1: DEBUG Buadrate:115200bps */
    {
        UART2,  /* UartHw */
        0x002C0000UL,  /* CTRL: RIE=1 TE=1 RE=1 */
        0x00000000UL,  /* STAT: MSBF=0 RXINV=0 BKDE=0 */
        0x0F00002BUL,  /* BAUD: OSR=16 SBR=43 bps=SPLLDIV2/((OSR+1)*SBR) */
        0,  /* Reserved */
        UCS_CH_DEBUG,  /* URxCh */
        UCS_CH_DEBUG,  /* UTxCh */
        Ucs_UartRxCbk, /* RxCallback */
        Ucs_UartTxCbk, /* TxCallback */
    },
};

static const Uart_ConfigType UartConfig = 
{
    UartChCfg,  /* ChCfg */
    sizeof(UartChCfg)/sizeof(Uart_ChCfgType),  /* ChNum */
};

const Uart_ConfigType* const UartCfgPtr = &UartConfig;

