/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Dsm.h Diagnostic State Management
Author: Steven
******************************************************************************/
#ifndef DSM_H
#define DSM_H
#ifdef __cplusplus
extern "C" {
#endif

#include "Dsm_Types.h"

#define DSM_MAJOR_VERSION   (0x00)
#define DSM_MINOR_VERSION   (0x01)
#define DSM_PATCH_VERSION   (0x00)

extern void Dsm_Init(void);
extern void Dsm_PollFunction(void);

extern Dsm_SessionStatusType Dsm_GetSessionStatus(void);
extern void Dsm_SetSessionStatus(Dsm_SessionStatusType SessionStatus);

extern Dsm_SecurityLevelType Dsm_GetSecurityLevel(void);
extern Std_ReturnType Dsm_SetSecurityLevel(Dsm_SecurityLevelType SecurityLevel);

extern void Dsm_SetSecAccFault(void);
extern Dsm_SecAccStatusType Dsm_GetSecAccStatus(void);

extern void Dsm_ResetSessionTime(void);

#ifdef __cplusplus
}
#endif
#endif

