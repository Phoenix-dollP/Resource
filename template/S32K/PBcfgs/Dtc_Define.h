/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Dtc_Define.h Diagnostic Trouble Codes
Author: Steven
******************************************************************************/
#ifndef DTC_DEFINE_H
#define DTC_DEFINE_H

/* OperationCycleDefine */
#define DTC_OPCYC_PWR             (0x00)  /* Power ON/OFF OperationCycle */
#define DTC_OPCYC_ACC             (0x01)  /* ACC ON/OFF OperationCycle */
#define DTC_OPCYC_IGN             (0x02)  /* IGN ON/OFF OperationCycle */
#define DTC_OPCYC_TIME            (0x03)  /* TimeBasedOperationCycle */

/* DtcId */
//#define Vehicle_voltage_too_high_DtcId				(0)  /* KL30电压过高 */
//#define Vehicle_voltage_too_low_DtcId				(1)  /* KL30电压过低 */

#define DtcId_NUM									(5)  /* DtcId总数 */

#define BUS_OFF_DtcId								(0)  /* BUS OFF */
#define CAN_Communication_miss_for_VCU_DtcId		(1)  /* CAN Communication miss for VCU */
#define CAN_Communication_miss_for_BCM_DtcId		(2)  /* CAN Communication miss for BCM */
#define CAN_Communication_miss_for_ICM_DtcId		(3)  /* CAN Communication miss for ICM */
#define CAN_Communication_miss_for_FCM_DtcId		(4)  /* CAN Communication miss for FCM */

//#define CAN_Communication_miss_for_Cluster_DtcId	(1)  /* CAN Communication miss for Cluster */
//#define CAN_Communication_miss_for_GW_DtcId		(2)  /* CAN Communication miss for GW */
//#define CAN_Communication_miss_for_IVI_DtcId		(3)  /* CAN Communication miss for IVI */
//#define CAN_Communication_miss_for_BCM_DtcId		(4)  /* CAN Communication miss for BCM */
//#define Watch_dog_reset_DtcId						(7)  /* 看门狗复位 */

#endif

