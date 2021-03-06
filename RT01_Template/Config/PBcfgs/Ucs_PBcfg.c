/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Ucs_PBcfg.c Uart Communication Service
Author: Steven
******************************************************************************/
#include "Ucs_PBcfg.h"
#include "Uart_Define.h"
#include "GdcIf_Cbk.h"
#include "DbgIf_Cbk.h"

static uint8 UcsCh0RxBuf[200];
static uint8 UcsCh0TxBuf[200];
static uint8 UcsCh1RxBuf[64];
static uint8 UcsCh1TxBuf[200];

static const Ucs_ChCfgType UcsChCfg[] = 
{
    {   /* Ch0: FPGAͨѶ */
    GdcIf_UartRxCallback,  /* RxCallback */
    GdcIf_UartTxCallback,  /* TxCallback */
    UART_CH_GDCIF,  /* UartCh */
    0,  /* URxCh */
    0,  /* UTxCh */
    0,  /* Reserved */
    1,  /* MinRecLen */
    1000, /* RxOverTime */
    UcsCh0RxBuf,  /* RxBuffer */
    UcsCh0TxBuf,  /* TxBuffer */
    sizeof(UcsCh0RxBuf),  /* RxBufSize */
    sizeof(UcsCh0TxBuf),  /* TxBufSize */
    },

    {   /* Ch1: DEBUG */
    DbgIf_UartRxCallback,  /* RxCallback */
    DbgIf_UartTxCallback,  /* TxCallback */
    UART_CH_DEBUG,  /* UartCh */
    0,  /* URxCh */
    0,  /* UTxCh */
    0,  /* Reserved */
    1,  /* MinRecLen */
    1000, /* RxOverTime */
    UcsCh1RxBuf,  /* RxBuffer */
    UcsCh1TxBuf,  /* TxBuffer */
    sizeof(UcsCh1RxBuf),  /* RxBufSize */
    sizeof(UcsCh1TxBuf),  /* TxBufSize */
    },
};

static const Ucs_ConfigType UcsConfig = 
{
    UcsChCfg,  /* ChCfg */
    sizeof(UcsChCfg)/sizeof(Ucs_ChCfgType),  /* ChNum */
};

const Ucs_ConfigType* const UcsCfgPtr = &UcsConfig;

