/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Eep.h Nxp S32K14x Series Eeprom driver
Author: Steven 
******************************************************************************/
#ifndef EEP_H
#define EEP_H

#include "Std_Types.h"

#define EEP_MAJOR_VERSION       (0x00)
#define EEP_MINOR_VERSION       (0x01)
#define EEP_PATCH_VERSION       (0x00)

#define EEP_BASE_ADDR           0x14000000  /* FlexRamAddr */
#define EEP_TOTAL_SIZE          (0x1000)

extern void Eep_Init(void);
extern Std_ReturnType Eep_Read(uint16 Addr, void* Dst, uint16 Length);
extern Std_ReturnType Eep_Write(uint16 Addr, const void* Src, uint16 Length);
extern Std_ReturnType Eep_Compare(uint16 Addr, const void* Src, uint16 Length);
extern void Fls_format(void);
#endif

