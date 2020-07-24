/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Dsm_Types.h Diagnostic State Management
Author: Steven
******************************************************************************/
#ifndef DSM_TYPES_H
#define DSM_TYPES_H

#include "Std_Types.h"

typedef enum
{
    DSM_SEC_LEV_LOCKED,
    DSM_SEC_LEV_L1,
    DSM_SEC_LEV_L2,
    DSM_SEC_LEV_L3,
} Dsm_SecurityLevelType;

typedef enum
{
    DSM_SESSION_IDLE,
    DSM_SESSION_DEFAULT,
    DSM_SESSION_PROGRAM,
    DSM_SESSION_EXTDIAG,
    DSM_SESSION_USER,
} Dsm_SessionStatusType;

typedef enum
{
    DSM_SEC_ACC_DENIED,
    DSM_SEC_ACC_READY,
    DSM_SEC_ACC_ENOA,  /* ExeceedNumberOfAttempts */
} Dsm_SecAccStatusType;


#endif

