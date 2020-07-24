/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Dsm_PBcfg.h Diagnostic State Management
Author: Steven
******************************************************************************/
#ifndef DSM_PBCFG_H
#define DSM_PBCFG_H

#include "Dsm_Types.h"

typedef struct
{
    void(*SesTimeoverCbk)(void);  /* Sesseion timeover callback */
    uint16 S3ServerTime;  /* SessionTime */
    Dsm_SessionStatusType SessionStatus;  /* Default session */
    Dsm_SecurityLevelType SecurityLevel;  /* Default level */
    uint16 SecAccEnTime0;  /* Security access enable time(ms) */
    uint16 SecAccEnTime1;  /* Security access reenable time(ms) */
    uint8 SecAccRetry;  /* Security access retry times */
} Dsm_ConfigType;

#endif

