/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Fls.h For Nxp S32K14x
Author: Steven
******************************************************************************/
#ifndef FLS_H
#define FLS_H
#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"

#define FLS_MAJOR_VERSION   (0x00)
#define FLS_MINOR_VERSION   (0x02)
#define FLS_PATCH_VERSION   (0x00)

#define FLS_START_ADDR      (0x00000000)
#define FLS_TOTAL_SIZE      (0x00080000)
#define FLS_SECTOR_SIZE     (0x00001000)

extern void Fls_Init(void);
extern Std_ReturnType Fls_Erase(uint32 Addr, uint32 Length);
extern Std_ReturnType Fls_Read(uint32 Addr, uint8* Dst, uint32 Length);
extern Std_ReturnType Fls_Write(uint32 Addr, const uint8* Src, uint32 Length);
extern Std_ReturnType Fls_Compare(uint32 Addr, const uint8* Src, uint32 Length);
extern Std_ReturnType Fls_Command(uint8 Cmd, const uint8* Param, uint8 Length);

#ifdef __cplusplus
}
#endif
#endif

