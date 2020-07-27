/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Dtc_PBcfg.c Diagnostic Trouble Codes
Author: Steven

故障码定义相关内容请参考ISO15031-6
B0xxx-B3xxx --> 8xxx-Bxxx     Body
C0xxx-C3xxx --> 4xxx-7xxx     Chassis
P0xxx-P3xxx --> 0xxx-3xxx     Powertrain
U0xxx-U3xxx --> Cxxx-Fxxx     Network
******************************************************************************/
#include "Dtc_PBcfg.h"
#include "Dtc_Define.h"
#include "Eep.h"
#include "Mcu.h"

static Std_ReturnType Dtc_NvRead(uint16 DtcId, uint8* DataPtr)
{
    Mcu_FeedWdg();
    return Eep_Read(DtcId*2 + 0x0300, DataPtr, 2);
}

static Std_ReturnType Dtc_NvWrite(uint16 DtcId, const uint8* DataPtr)
{
    Mcu_FeedWdg();
    return Eep_Write(DtcId*2 + 0x0300, DataPtr, 2);
}

static const Dtc_DTCsCfgType DtcDTCsCfg[] = 
{
    /* UdsCode   OpCycle         FCnt Aging */
//    {0xC1000100, DTC_OPCYC_ACC,  30,   10},  /* ABS掉线 */
//    {0xC1000200, DTC_OPCYC_ACC,  30,   10},  /* ECU掉线 */
//    {0xC1000300, DTC_OPCYC_ACC,  30,   10},  /* TCU掉线 */
//    {0xC1000400, DTC_OPCYC_ACC,  30,   10},  /* ECAS掉线 */
//    {0xC1000500, DTC_OPCYC_ACC,  30,   10},  /* TPMS掉线 */
//    {0xC1000600, DTC_OPCYC_ACC,  30,   10},  /* LDWS掉线 */
//    {0x81001200, DTC_OPCYC_ACC,  30,   10},  /* 油量信号开路 */
//    {0x81001300, DTC_OPCYC_ACC,  30,   10},  /* 油量信号短路 */
//    {0x81001500, DTC_OPCYC_ACC,  30,   10},  /* 水温信号开路 */
//    {0x81001600, DTC_OPCYC_ACC,  30,   10},  /* 转速信号丢失 */
//    {0x18001700, DTC_OPCYC_ACC,  100,   40},  /* KL30电压过高 */
//	{0x18001800, DTC_OPCYC_ACC,  100,   40},  /* KL30电压过低 */
//	{0x18001900, DTC_OPCYC_ACC,  30,   10},  /* BUS OFF */
//	{0x18002000, DTC_OPCYC_ACC,  5,   40},  /* CAN Communication miss for Cluster */
//	{0x18002100, DTC_OPCYC_ACC,  5,   40},  /* CAN Communication miss for GW */
//	{0x18002200, DTC_OPCYC_ACC,  5,   40},  /* CAN Communication miss for IVI */
//	{0x18002300, DTC_OPCYC_ACC,  5,   40},  /* CAN Communication miss for BCM */
//	{0x92720000, DTC_OPCYC_PWR,  1,   40},  /* 看门狗复位 */
	
	{0x00ED0088, DTC_OPCYC_ACC,  30,  50},  /* BUS OFF */
	{0x00ED1087, DTC_OPCYC_ACC,  5,   50},  /* CAN Communication miss for VCU */
	{0x00ED1187, DTC_OPCYC_ACC,  5,   50},  /* CAN Communication miss for BCM */
	{0x00ED1287, DTC_OPCYC_ACC,  5,   50},  /* CAN Communication miss for ICM */
	{0x00ED1387, DTC_OPCYC_ACC,  5,   50},  /* CAN Communication miss for FCM */
};

static const Dtc_ConfigType DtcConfig = 
{
    Dtc_NvRead,
    Dtc_NvWrite,
    {STD_ON, STD_OFF, STD_OFF, STD_OFF}, /* OpCycleCfg */
    DtcDTCsCfg,  /* DtcCfg */
    sizeof(DtcDTCsCfg) / sizeof(Dtc_DTCsCfgType),  /* DtcNum */
};

const Dtc_ConfigType* const DtcCfgPtr = &DtcConfig;

