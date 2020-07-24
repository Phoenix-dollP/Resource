/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Dtc.h Diagnostic Trouble Codes
Author: Steven
******************************************************************************/
#ifndef DTC_H
#define DTC_H
#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "Dtc_Define.h"

#define DTC_MAJOR_VERSION       (0x00)
#define DTC_MINOR_VERSION       (0x02)
#define DTC_PATCH_VERSION       (0x00)

#define DTC_MAX_DTCS_NUM        (40)
#define DTC_OPCYCLE_NUM         (4)

typedef uint8 Dtc_StatusType;
#define DTC_STATUS_TF           (0x01)  /* TestFailed */
#define DTC_STATUS_TFTOC        (0x02)  /* TestFailedThisOpCycle */
#define DTC_STATUS_PDTC         (0x04)  /* PendingDTC */
#define DTC_STATUS_CDTC         (0x08)  /* ConfirmedDTC */
#define DTC_STATUS_TNCSLC       (0x10)  /* TestNotCompletedSinceLastClr */
#define DTC_STATUS_TFSLC        (0x20)  /* TestFailedSinceLastClear */
#define DTC_STATUS_TNCTOC       (0x40)  /* TestNotCompletedThisOpCycle */
#define DTC_STATUS_WIR          (0x80)  /* WarningIndicatorRequested */

extern void Dtc_Init(void);

extern void Dtc_StopOpCycle(uint8 CycleId);
extern void Dtc_StartOpCycle(uint8 CycleId);

extern void Dtc_SetStatus(uint16 DtcId, boolean Failed);
extern Dtc_StatusType Dtc_GetStatus(uint16 DtcId);
extern Std_ReturnType Dtc_ClearStatus(uint16 DtcId);
extern Std_ReturnType Dtc_ClearAllStatus(void);
extern uint32 Dtc_GetUdsCode(uint16 DtcId);
extern uint16 Dtc_SeekUdsCode(uint32 UdsCode);
extern uint8 Dtc_GetFailedCount(uint16 DtcId);

extern uint16 Dtc_SetStatusFilter(uint8 StatusMask);
extern uint16 Dtc_GetFilteredNum(void);
extern uint16 Dtc_GetFilteredDTC(void);

#ifdef __cplusplus
}
#endif
#endif

