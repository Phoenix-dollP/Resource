/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Dcm_PBcfg.h Diagnostic Communication Management
Author: Steven
******************************************************************************/
#ifndef DCM_TYPES_H
#define DCM_TYPES_H

#include "Std_Types.h"

/* 消积应答定义 */
#define DCM_NRC_PR          (0x00)  /* PositiveResponse */
#define DCM_NRC_GR          (0x10)  /* GeneralReject */
#define DCM_NRC_SNS         (0x11)  /* ServiceNotSupported */
#define DCM_NRC_SFNS        (0x12)  /* SubfunctionNotSupported */
#define DCM_NRC_IMLOIF      (0x13)  /* IncorrectMsgLengthOrInvalidFormat */
#define DCM_NRC_RTL         (0x14)  /* ResponseTooLong */
#define DCM_NRC_BRR         (0x21)  /* BusyRepeatRequest */
#define DCM_NRC_CNC         (0x22)  /* ConditionsNotCorrect */
#define DCM_NRC_RSE         (0x24)  /* RequestSequenceError */
#define DCM_NRC_NRFSC       (0x25)  /* NoResponseFromSubnetComponent */
#define DCM_NRC_FPEORA      (0x26)  /* FailurePreventsExecOfReqAction */
#define DCM_NRC_ROOR        (0x31)  /* RequestOutOfRange */
#define DCM_NRC_SAD         (0x33)  /* SecurityAccessDenied */
#define DCM_NRC_IK          (0x35)  /* InvalidKey */
#define DCM_NRC_ENOA        (0x36)  /* ExeceedNumberOfAttempts */
#define DCM_NRC_RTDNE       (0x37)  /* RequiredTimeDelayNotExpired */
#define DCM_NRC_UDNA        (0x70)  /* UploadDownloadNotAccepted */
#define DCM_NRC_TDS         (0x71)  /* TransferDataSuspended */
#define DCM_NRC_GPF         (0x72)  /* GeneralProgrammingFailure */
#define DCM_NRC_WBSC        (0x73)  /* WrongBlockSequenceCounter */
#define DCM_NRC_RCRRP       (0x78)  /* ReqCorrectlyReceivedResPending */
#define DCM_NRC_SFNSIAS     (0x7E)  /* SubFunNotSupportedInActiveSession */
#define DCM_NRC_SNSIAS      (0x7F)  /* ServiceNotSupportedInActiveSession */
#define DCM_NRC_RPMTH       (0x81)  /* RpmTooHigh */
#define DCM_NRC_RPMTL       (0x82)  /* RpmTooLow */
#define DCM_NRC_EIR         (0x83)  /* EngineIsRunning */
#define DCM_NRC_EINR        (0x84)  /* EngineIsNotRunning */
#define DCM_NRC_ERTTL       (0x85)  /* EngineRunTimeTooLow */
#define DCM_NRC_TEMPTH      (0x86)  /* TemperatureTooHigh */
#define DCM_NRC_TEMPTL      (0x87)  /* TemperatureTooLow */
#define DCM_NRC_VSTH        (0x88)  /* VehicleSpeedTooHigh */
#define DCM_NRC_VSTL        (0x89)  /* VehicleSpeedTooLow */
#define DCM_NRC_TPTH        (0x8A)  /* ThrottlePedalTooHigh */
#define DCM_NRC_TPTL        (0x8B)  /* ThrottlePedalTooLow */
#define DCM_NRC_TRNIN       (0x8C)  /* TransMissionRangeNotInNeutral */
#define DCM_NRC_TRNIG       (0x8D)  /* TransMissionRangeNotInGear */
#define DCM_NRC_BSNC        (0x8F)  /* BrakeSwitchNotClosed */
#define DCM_NRC_SLNIP       (0x90)  /* ShifterLevelNotInPark */
#define DCM_NRC_TCCL        (0x91)  /* ToRqueConverterClutchLocked */
#define DCM_NRC_VTH         (0x92)  /* VoltageTooHigh */
#define DCM_NRC_VHL         (0x93)  /* VoltageTooLow */

typedef struct
{
    uint8 RxChId;
    uint8 ServiceId;  /* Request service id */
    const uint8* ReqParam;  /* Request parameters */
    uint16 ReqLength;  /* Request parameters length */
    uint8* ResBuffer;  /* Response parameters buffer */
    uint16 ResBufSize; /* Response parameters buffer size */
} Dcm_MsgContextType;

#endif

