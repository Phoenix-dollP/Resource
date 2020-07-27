/******************************************************************************
Copyright (C) 2019 Steven, mculib.net All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Isr.h  Interrupt Service Routine
Author: Steven
******************************************************************************/
#ifndef ISR_H
#define ISR_H

#include "Std_Types.h"

extern void DefaultISR(void);
extern void Reset_Handler(void);
extern void NMI_Handler(void);
extern void HardFault_Handler(void);
extern void MemManage_Handler(void);
extern void BusFault_Handler(void);
extern void UsageFault_Handler(void);
extern void SVC_Handler(void);
extern void DebugMon_Handler(void);
extern void PendSV_Handler(void);
extern void SysTick_Handler(void);

extern void DMA0_IRQHandler(void);
extern void DMA1_IRQHandler(void);
extern void DMA2_IRQHandler(void);
extern void DMA3_IRQHandler(void);
extern void DMA4_IRQHandler(void);
extern void DMA5_IRQHandler(void);
extern void DMA6_IRQHandler(void);
extern void DMA7_IRQHandler(void);
extern void DMA8_IRQHandler(void);
extern void DMA9_IRQHandler(void);
extern void DMA10_IRQHandler(void);
extern void DMA11_IRQHandler(void);
extern void DMA12_IRQHandler(void);
extern void DMA13_IRQHandler(void);
extern void DMA14_IRQHandler(void);
extern void DMA15_IRQHandler(void);
extern void DMA_Error_IRQHandler(void);
extern void MCM_IRQHandler(void);
extern void FTFC_IRQHandler(void);
extern void Read_Collision_IRQHandler(void);
extern void LVD_LVW_IRQHandler(void);
extern void FTFC_Fault_IRQHandler(void);
extern void WDOG_EWM_IRQHandler(void);
extern void RCM_IRQHandler(void);
extern void LPI2C0_Master_IRQHandler(void);
extern void LPI2C0_Slave_IRQHandler(void);
extern void LPSPI0_IRQHandler(void);
extern void LPSPI1_IRQHandler(void);
extern void LPSPI2_IRQHandler(void);
extern void Reserved45_IRQHandler(void);
extern void Reserved46_IRQHandler(void);
extern void LPUART0_RxTx_IRQHandler(void);
extern void Reserved48_IRQHandler(void);
extern void LPUART1_RxTx_IRQHandler(void);
extern void Reserved50_IRQHandler(void);
extern void LPUART2_RxTx_IRQHandler(void);
extern void Reserved52_IRQHandler(void);
extern void Reserved53_IRQHandler(void);
extern void Reserved54_IRQHandler(void);
extern void ADC0_IRQHandler(void);
extern void ADC1_IRQHandler(void);
extern void CMP0_IRQHandler(void);
extern void Reserved58_IRQHandler(void);
extern void Reserved59_IRQHandler(void);
extern void ERM_single_fault_IRQHandler(void);
extern void ERM_double_fault_IRQHandler(void);
extern void RTC_IRQHandler(void);
extern void RTC_Seconds_IRQHandler(void);
extern void LPIT0_Ch0_IRQHandler(void);
extern void LPIT0_Ch1_IRQHandler(void);
extern void LPIT0_Ch2_IRQHandler(void);
extern void LPIT0_Ch3_IRQHandler(void);
extern void PDB0_IRQHandler(void);
extern void Reserved69_IRQHandler(void);
extern void Reserved70_IRQHandler(void);
extern void Reserved71_IRQHandler(void);
extern void Reserved72_IRQHandler(void);
extern void SCG_IRQHandler(void);
extern void LPTMR0_IRQHandler(void);
extern void PORTA_IRQHandler(void);
extern void PORTB_IRQHandler(void);
extern void PORTC_IRQHandler(void);
extern void PORTD_IRQHandler(void);
extern void PORTE_IRQHandler(void);
extern void SWI_IRQHandler(void);
extern void Reserved81_IRQHandler(void);
extern void Reserved82_IRQHandler(void);
extern void Reserved83_IRQHandler(void);
extern void PDB1_IRQHandler(void);
extern void FLEXIO_IRQHandler(void);
extern void Reserved86_IRQHandler(void);
extern void Reserved87_IRQHandler(void);
extern void Reserved88_IRQHandler(void);
extern void Reserved89_IRQHandler(void);
extern void Reserved90_IRQHandler(void);
extern void Reserved91_IRQHandler(void);
extern void Reserved92_IRQHandler(void);
extern void Reserved93_IRQHandler(void);
extern void CAN0_ORed_IRQHandler(void);
extern void CAN0_Error_IRQHandler(void);
extern void CAN0_Wake_Up_IRQHandler(void);
extern void CAN0_ORed_0_15_MB_IRQHandler(void);
extern void CAN0_ORed_16_31_MB_IRQHandler(void);
extern void Reserved99_IRQHandler(void);
extern void Reserved100_IRQHandler(void);
extern void CAN1_ORed_IRQHandler(void);
extern void CAN1_Error_IRQHandler(void);
extern void Reserved103_IRQHandler(void);
extern void CAN1_ORed_0_15_MB_IRQHandler(void);
extern void Reserved105_IRQHandler(void);
extern void Reserved106_IRQHandler(void);
extern void Reserved107_IRQHandler(void);
extern void CAN2_ORed_IRQHandler(void);
extern void CAN2_Error_IRQHandler(void);
extern void Reserved110_IRQHandler(void);
extern void CAN2_ORed_0_15_MB_IRQHandler(void);
extern void Reserved112_IRQHandler(void);
extern void Reserved113_IRQHandler(void);
extern void Reserved114_IRQHandler(void);
extern void FTM0_Ch0_Ch1_IRQHandler(void);
extern void FTM0_Ch2_Ch3_IRQHandler(void);
extern void FTM0_Ch4_Ch5_IRQHandler(void);
extern void FTM0_Ch6_Ch7_IRQHandler(void);
extern void FTM0_Fault_IRQHandler(void);
extern void FTM0_Ovf_Reload_IRQHandler(void);
extern void FTM1_Ch0_Ch1_IRQHandler(void);
extern void FTM1_Ch2_Ch3_IRQHandler(void);
extern void FTM1_Ch4_Ch5_IRQHandler(void);
extern void FTM1_Ch6_Ch7_IRQHandler(void);
extern void FTM1_Fault_IRQHandler(void);
extern void FTM1_Ovf_Reload_IRQHandler(void);
extern void FTM2_Ch0_Ch1_IRQHandler(void);
extern void FTM2_Ch2_Ch3_IRQHandler(void);
extern void FTM2_Ch4_Ch5_IRQHandler(void);
extern void FTM2_Ch6_Ch7_IRQHandler(void);
extern void FTM2_Fault_IRQHandler(void);
extern void FTM2_Ovf_Reload_IRQHandler(void);
extern void FTM3_Ch0_Ch1_IRQHandler(void);
extern void FTM3_Ch2_Ch3_IRQHandler(void);
extern void FTM3_Ch4_Ch5_IRQHandler(void);
extern void FTM3_Ch6_Ch7_IRQHandler(void);
extern void FTM3_Fault_IRQHandler(void);
extern void FTM3_Ovf_Reload_IRQHandler(void);

#endif

