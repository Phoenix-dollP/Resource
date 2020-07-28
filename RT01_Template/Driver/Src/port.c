/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Port.h For Nxp S32K14x Series
Author: Steven 
******************************************************************************/
#include "S32K144.h"
#include "Port_PBcfg.h"

extern const Port_ConfigType* const PortCfgPtr;
static GPIO_Type * const GPIO_X[] = {PTA, PTB, PTC, PTD, PTE};
static PORT_Type * const PORT_X[] = {PORTA, PORTB, PORTC, PORTD, PORTE};

/**
  * @brief  初始化Port模块
  * @param  
  * @param  
  * @retval 
  */
void Port_Init(void)
{
    const Port_GpioCfgType* GpioCfg = PortCfgPtr->GpioCfg;
    uint8 GpioNum = PortCfgPtr->GpioNum;
    const Port_PpcrCfgType* PpcrCfg = PortCfgPtr->PpcrCfg;
    uint8 PpcrNum = PortCfgPtr->PpcrNum;
    uint8_t i;

    
    for (i = 0; i < GpioNum; i++)
    {
        /* Enable clocks to peripherals (PORT modules) */
        PCC->PCCn[i + PCC_PORTA_INDEX] = PCC_PCCn_CGC_MASK;

        /* Configure port Direction */
        GPIO_X[i]->PDDR = GpioCfg[i].DDR;
    }

    for (i = 0; i < PpcrNum; i++)
    {
       /* Configure port Function */
       PORT_X[PpcrCfg[i].PortId]->PCR[PpcrCfg[i].PinNum] = PpcrCfg[i].PCRv;
    }
}

/**
  * @brief  取消初始化Port模块
  * @param  
  * @param  
  * @retval 
  */
void Port_DeInit(void)
{
    const Port_GpioCfgType* GpioCfg = PortCfgPtr->GpioCfg;
    uint8 GpioNum = PortCfgPtr->GpioNum;
    const Port_PpcrCfgType* PpcrCfg = PortCfgPtr->PpcrCfg;
    uint8 PpcrNum = PortCfgPtr->PpcrNum;
    uint8_t i;

    
    for (i = 0; i < GpioNum; i++)
    {
        /* Enable clocks to peripherals (PORT modules) */
        PCC->PCCn[i + PCC_PORTA_INDEX] = 0x00000000;

        /* Configure port Function */
        GPIO_X[i]->PDDR = 0x00000000;
    }

    for (i = 0; i < PpcrNum; i++)
    {
       /* Configure port Direction */
       PORT_X[PpcrCfg[i].PortId]->PCR[PpcrCfg[i].PinNum] = 0x00000000;
    }
}

/**
  * @brief  读取端口状态
  * @param  PortId:端口编号 0-PORTA 1-PORTB … 4-PORTE.
  * @param  
  * @retval 端口状态
  */
 uint32 Port_Read(uint8 PortId)
 {
    uint32 Return;

    Return = GPIO_X[PortId]->PDOR;

    return Return;
 }

 /**
  * @brief  设置端口输出状态
  * @param  PortId:端口编号 0-PORTA 1-PORTB … 4-PORTE.
  * @param  Levels:端口各PIN输出电平.
  * @retval None
  */
 void Port_Write(uint8 PortId, uint32 Levels)
 {
     GPIO_X[PortId]->PDOR = Levels;
 }

  /**
  * @brief  读取PIN输入或输出状态
  * @param  PinId:PIN编号 [0,31]PORTA0-31 [31-63]PORTB0-31 …
  * @param  
  * @retval PIN电平状态 STD_LOW(低) STD_HIGH(高)
  */
 Std_StatusType Port_ReadPin(uint8 PinId)
 {
    uint8 Portx = PinId / 32;
    uint8 Pin = PinId % 32;
    uint32 Levels = GPIO_X[Portx]->PDIR;

    Levels <<= 31 - Pin;
    Levels >>= 31;

    return (Std_StatusType)Levels;
 }

   /**
  * @brief  设置PIN输出状态
  * @param  PinId:PIN编号 [0,31]PORTA0-31 [31-63]PORTB0-31 …
  * @param  Level:PIN电平状态 STD_LOW(低) STD_HIGH(高
  * @retval None
  */
void Port_WritePin(uint8 PinId, Std_StatusType Level)
{
    uint8 Portx = PinId / 32;
    uint8 Pin = PinId % 32;

    if (Level == 0)
    {
        GPIO_X[Portx]->PCOR = (uint32)1 << Pin;
        return;
    }

    GPIO_X[Portx]->PSOR = (uint32)1 << Pin;

}

   /**
  * @brief  反转PIN输出状态
  * @param  PinId:PIN编号 [0,31]PORTA0-31 [31-63]PORTB0-31 …
  * @param  
  * @retval 反转后的输出电平 STD_LOW(低) STD_HIGH(高)
  */
Std_StatusType Port_FlipPin(uint8 PinId)
{
    uint8 Portx = PinId / 32;
    uint8 Pin = PinId % 32;

    GPIO_X[Portx]->PTOR = (uint32)1 << Pin;

    return Port_ReadPin(PinId);
}

   /**
  * @brief  设置PIN输入输出方向
  * @param  PinId:PIN编号 [0,31]PORTA0-31 [31-63]PORTB0-31 …
  * @param  Status:STD_IN(输入) STD_OUT(输出)
  * @retval None
  */
void Port_SetPinIO(uint8 PinId, Std_StatusType Status)
{
    uint8 Portx = PinId / 32;
    uint8 Pin = PinId % 32;

    GPIO_X[Portx]->PDDR = (uint32)Status << Pin;
}

   /**
  * @brief  获取PIN输出输出状态
  * @param  PinId:PIN编号 [0,31]PORTA0-31 [31-63]PORTB0-31 …
  * @param  
  * @retval STD_IN(输入) STD_OUT(输出)
  */
Std_StatusType Port_GetPinIO(uint8 PinId)
{
    uint8 Portx = PinId / 32;
    uint8 Pin = PinId % 32;
    uint32 Direction = GPIO_X[Portx]->PDDR;

    Direction <<= 31 - Pin;
    Direction >>= 31;

    return (Std_StatusType)Direction;
}

   /**
  * @brief  设置PIN功能(PIN功能编号详见文档
            S32K144_IO_Signal_Description_Input_Multiplexing.xlsx)
  * @param  PinId:PIN编号 [0,31]PORTA0-31 [31-63]PORTB0-31 …
  * @param  Fun:PIN功能编号
  * @retval None
  */
void Port_SetPinFun(uint8 PinId, uint8 Fun)
{
    uint8 Portx = PinId / 32;
    uint8 Pin = PinId % 32;

    PORT_X[Portx]->PCR[Pin] = Fun;
}

