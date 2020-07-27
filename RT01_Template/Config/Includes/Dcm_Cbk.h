/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Dcm_Cbk.h Diagnostic Communication Management
Author: Steven
******************************************************************************/
#ifndef DCM_CBK_H
#define DCM_CBK_H
#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "Dcm_Define.h"

extern void Dcm_TpRxCallback(uint8 Ch, uint8 Error);
extern Std_ReturnType Dcm_TpRxStartCbk(uint8 Ch, uint16 Length);
extern Std_ReturnType Dcm_TpCopyRxData(uint8 Ch, uint16 Offset, const uint8* Data, uint16 Length);

extern void Dcm_TpTxCallback(uint8 Ch, uint8 Error);
extern Std_ReturnType Dcm_TpCopyTxData(uint8 Ch, uint16 Offset, uint8* Data, uint16 Length);

#ifdef __cplusplus
}
#endif
#endif

