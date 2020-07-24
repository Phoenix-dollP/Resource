/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Spi.h SPI Master driver For Nxp S32K14x Series LPSPI
Author: Steven 
******************************************************************************/
#ifndef SPI_H
#define SPI_H
#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "Spi_Define.h"

#define SPI_MAJOR_VERSION       (0x00)
#define SPI_MINOR_VERSION       (0x01)
#define SPI_PATCH_VERSION       (0x00)

#define SPI_MAX_CH_NUM          2

typedef enum
{
    SPI_IDLE,
    SPI_BUSY,
} Spi_StatusType;

extern void Spi_Init(void);
extern void Spi_DeInit(void);

extern Std_ReturnType Spi_Transmit(uint8 Ch, void* RxDst, const void* TxSrc, uint16 Length);
extern Std_StatusType Spi_GetStatus(uint8 Ch);
extern Std_ReturnType Spi_ChipSelect(uint8 Ch, uint8 Chip);
extern void Spi_Cancel(uint8 Ch);

#ifdef __cplusplus
}
#endif
#endif

