/******************************************************************************
Copyright (C) 2019 Steven, mculib.net All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Isr.c  Interrupt Service Routine
Author: Steven
******************************************************************************/
#include "Tbm_Isr.h"
#include "Can_Isr.h"
#include "Adc_Isr.h"
#include "Spi_Isr.h"
#include "I2c_Isr.h"
#include "Uart_Isr.h"
#include "Pint_Isr.h"

/******************************************************************************
函数名称: void SysTick_Handler(void)
函数说明: 
最后修改: Steven
******************************************************************************/
void SysTick_Handler(void)
{
    Tbm_Isr();
}

/******************************************************************************
函数名称: void ADC0_IRQHandler(void)
函数说明: 
最后修改: Steven
******************************************************************************/
void ADC0_IRQHandler(void)
{
    Adc_Isr();
}

/******************************************************************************
函数名称: void CAN0_ORed_IRQHandler(void)
函数说明: 
最后修改: Steven
******************************************************************************/
void CAN0_ORed_IRQHandler(void)
{
    Can_StatusIsr(0);
}

/******************************************************************************
函数名称: void CAN0_ORed_0_15_MB_IRQHandler(void)
函数说明: 
最后修改: Steven
******************************************************************************/
void CAN0_ORed_0_15_MB_IRQHandler(void)
{
    Can_MsgboxIsr(0);
}

/******************************************************************************
函数名称: void LPUART1_RxTx_IRQHandler(void)
函数说明: 
最后修改: Steven
******************************************************************************/
void LPUART1_RxTx_IRQHandler(void)
{
    Uart_Isr(UART_CH_GDCIF);
}

/******************************************************************************
函数名称: void LPUART2_RxTx_IRQHandler(void)
函数说明: 
最后修改: Steven
******************************************************************************/
void LPUART2_RxTx_IRQHandler(void)
{
    Uart_Isr(UART_CH_DEBUG);
}

/******************************************************************************
函数名称: void LPSPI1_IRQHandler(void)
函数说明: 
最后修改: Steven
******************************************************************************/
void LPSPI1_IRQHandler(void)
{
    Spi_Isr(SPI_CH_FPGA);
}

/******************************************************************************
函数名称: void LPSPI2_IRQHandler(void)
函数说明: 
最后修改: Steven
******************************************************************************/
void LPSPI2_IRQHandler(void)
{
    Spi_Isr(SPI_CH_FLASH);
}

/******************************************************************************
函数名称: void LPI2C0_Master_IRQHandler(void)
函数说明: 
最后修改: Steven
******************************************************************************/
void LPI2C0_Master_IRQHandler(void)
{
    I2c_Isr(I2C_CH_SENSER);
}

/******************************************************************************
函数名称: void PORTE_IRQHandler(void)
函数说明: 
最后修改: Steven
******************************************************************************/
void PORTE_IRQHandler(void)
{
    Pint_Isr(PINT_CH_ACC);
}

/******************************************************************************
函数名称: void PORTC_IRQHandler(void)
函数说明: 
最后修改: Steven
******************************************************************************/
void PORTC_IRQHandler(void)
{
    Pint_Isr(PINT_CH_CAN);
}

