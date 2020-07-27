/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Dcm.h Diagnostic Communication Management
Author: Steven
******************************************************************************/
#ifndef DCM_H
#define DCM_H
#ifdef __cplusplus
extern "C" {
#endif

#include "Dcm_Types.h"
#include "Dcm_Define.h"

#define DCM_MAJOR_VERSION   0x00
#define DCM_MINOR_VERSION   0x01
#define DCM_PATCH_VERSION   0x00

#define DCM_MAX_COMCH_NUM   4

extern void Dcm_Init(void);
extern void Dcm_PollFunction(void);

extern Std_ReturnType Dcm_NegResponse(uint8 Ch, uint8 SID, uint8 NRC);
extern Std_ReturnType Dcm_PosResponse(uint8 Ch, uint8 SID, void* Data, uint16 Length);

#ifdef __cplusplus
}
#endif
#endif

