/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Dcm_PBcfg.h Diagnostic Communication Management
Author: Steven
******************************************************************************/
#ifndef DCM_PBCFG_H
#define DCM_PBCFG_H

#include "Dcm_Types.h"

typedef struct
{
    uint8* RxBuffer;
    uint16 RxBufSize;
    uint16 RxOverTime;  /* ms */
    uint8* TxBuffer;
    uint16 TxBufSize;
    uint16 TxOverTime;  /* ms */
    uint16 Reserved;
    uint8 URxChId;
    uint8 LTxChId;
    void(*RxCallback)(const Dcm_MsgContextType* MsgContext);
    Std_ReturnType(*TpTransmit)(uint8 LTxChId, const uint8* Data, uint16 Length);
} Dcm_ChCfgType;

typedef struct
{
    const Dcm_ChCfgType* ChCfg;
    uint8 ChNum;
} Dcm_ConfigType;

#endif

