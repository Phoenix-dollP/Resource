/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Dsm_PBcfg.c Diagnostic State Management
Author: Steven
******************************************************************************/
#include "Dsm_PBcfg.h"

static const Dsm_ConfigType DsmConfig = 
{
    NULL,  /* SesTimeoverCbk */
    50000,  /* S3ServerTime */
    DSM_SESSION_PROGRAM, /* Default SessionStatus */
    DSM_SEC_LEV_LOCKED,  /* SecurityLevel */
    0,     /* SecAccEnTime0 ms */
    10000, /* SecAccEnTime1 ms */
    3,     /* SecAccRetry */
};

const Dsm_ConfigType* const DsmCfgPtr = &DsmConfig;

