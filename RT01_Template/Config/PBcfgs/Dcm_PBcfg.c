/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Dcm_PBcfg.c Diagnostic Communication Management
Author: Steven
******************************************************************************/
#include "Dcm_PBcfg.h"
//#include "Uds_Cbk.h"
#include "CanTp.h"

static uint8 DcmCh0RxBuf[136];
static uint8 DcmCh0TxBuf[200];
static uint8 DcmCh1RxBuf[20];
static uint8 DcmCh1TxBuf[20];

static const Dcm_ChCfgType DcmChCfg[] = 
{
    /* Ch0: Diagnostic Physical Addressing for CAN */
    {
        DcmCh0RxBuf, /* RxBuffer */
        sizeof(DcmCh0RxBuf), /* RxBufSize */
        5000, /* RxOverTime ms */
        DcmCh0TxBuf, /* TxBuffer */
        sizeof(DcmCh0TxBuf), /* TxBufSize */
        5000, /* TxOverTime ms */
        0,    /* Reserved */
        UDS_CH_CANTP_PHY,  /* URxChId */
        CANTP_CH_UDS_PHY,  /* LTxChId */
        Uds_RxCallback, /* RxCallback */
        CanTp_Transmit, /* Transmit */
    },

    /* Ch1: Diagnostic Functional Addressing for CAN */
    {
        DcmCh1RxBuf, /* RxBuffer */
        sizeof(DcmCh1RxBuf), /* RxBufSize */
        5000, /* RxOverTime ms */
        DcmCh1TxBuf, /* TxBuffer */
        sizeof(DcmCh1TxBuf), /* TxBufSize */
        5000, /* TxOverTime ms */
        0,    /* Reserved */
        UDS_CH_CANTP_FUN, /* URxChId */
        CANTP_CH_UDS_FUN, /* LTxChId */
        Uds_RxCallback, /* RxCallback */
        CanTp_Transmit, /* Transmit */
    },
};

static const Dcm_ConfigType DcmConfig = 
{
    DcmChCfg, /* ChCfg */
    sizeof(DcmChCfg)/sizeof(Dcm_ChCfgType),  /* ChNum */
};

const Dcm_ConfigType* const DcmCfgPtr = &DcmConfig;

