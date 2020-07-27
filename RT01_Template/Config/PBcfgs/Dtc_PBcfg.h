/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Dtc_PBcfg.h Diagnostic Trouble Codes
Author: Steven
******************************************************************************/
#ifndef DTC_PBCFG_H
#define DTC_PBCFG_H

#include "Std_Types.h"

typedef struct
{
    uint32 UdsCode;
    uint8 OpCycleId;
    uint8 FailsCntThr;  /* Failure Counter Threshold */
    uint8 AgingCntThr;  /* Aging Counter Threshold */
} Dtc_DTCsCfgType;

typedef struct
{
    Std_ReturnType(*NvRead)(uint16 DtcId, uint8* DataPtr);  /* 数据长度2字节 */
    Std_ReturnType(*NvWrite)(uint16 DtcId, const uint8* DataPtr);   /* 数据长度2字节 */
    const Std_StatusType OpCycleCfg[4];  /* OpCycle默认状态 */
    const Dtc_DTCsCfgType* DTCsCfg;
    uint16 DTCsNum;
} Dtc_ConfigType;

#endif

