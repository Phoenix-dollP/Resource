/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Spi_PBcfg.h SPI Master driver For Nxp S32K14x Series LPSPI
Author: Steven 
******************************************************************************/
#ifndef SPI_PBCFG_H
#define SPI_PBCFG_H

#include "Std_Types.h"

#define SPI0    (0)
#define SPI1    (1)
#define SPI2    (2)

typedef struct
{
    uint8 SpiId;
    uint8 UChId;
    uint16 RES;
    uint32 CCRv;  /* VaildBits:FFFFFFFF */
    uint32 TCRv;  /* VaildBits:FBC30FFF */
    uint32 CFGR1v; /* ValidBits:0F000F00 */
    void(*EndCallback)(uint8 UChId, uint8 Error);
} Spi_ChCfgType;

typedef struct
{
    const Spi_ChCfgType* ChCfg;
    uint8 ChNum;
} Spi_ConfigType;

#endif

