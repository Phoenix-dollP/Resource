/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Sdk.h
Author: Steven 
******************************************************************************/
#ifndef SDK_H
#define SDK_H
#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"

#define SDK_MAJOR_VERSION       (0x03)
#define SDK_MINOR_VERSION       (0x04)
#define SDK_PATCH_VERSION       (0x00)

extern void Sdk_Init(void);
extern void Sdk_PollFunction(void);
extern void Sdk_GetVersion(Std_VersionType* Version);

#ifdef __cplusplus
}
#endif
#endif

