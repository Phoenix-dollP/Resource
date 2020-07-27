/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Crc.h  Crc calculate service
Author: Steven
******************************************************************************/
#ifndef CRC_H
#define CRC_H
#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"

#define CRC_MAJOR_VERSION       (0x00)
#define CRC_MINOR_VERSION       (0x01)
#define CRC_PATCH_VERSION       (0x00)

extern uint8 Crc_CalcCRC8(uint8 Start, const uint8* DataPtr, uint16 Length);
extern uint8 Crc_CalcCRC8H2F(uint8 Start, const uint8* DataPtr, uint16 Length);
extern uint16 Crc_CalcCRC16(uint16 Start, const uint8* DataPtr, uint16 Length);
extern uint32 Crc_CalcCRC32(uint32 Start, const uint8* DataPtr, uint16 Length);

#ifdef __cplusplus
}
#endif
#endif

