/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Spi_PBcfg.c SPI Master driver For Nxp S32K14x Series LPSPI
Author: Steven 
******************************************************************************/
#include "Spi_PBcfg.h"
//#include "GdcIf_Cbk.h"

static const Spi_ChCfgType SpiChCfg[] = 
{
    /* SPI UCh RES CCRv          TCRv          CFGR1v  EndCallback */
    {SPI1, 0,  0,  0x04090808UL, 0x18400000UL, 0x00UL, GdcIf_SpiEndCallback}, /* FPGA 20M */
    {SPI2, 0,  0,  0x04090808UL, 0x18400000UL, 0x00UL, NULL}, /* FLASH 20M */
};

static const Spi_ConfigType SpiConfig = 
{
    SpiChCfg,
    sizeof(SpiChCfg)/sizeof(SpiChCfg[0]),
};

const Spi_ConfigType* const SpiCfgPtr = &SpiConfig;

