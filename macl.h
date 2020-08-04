/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : MACL.h  Microcontroller Abstraction Layer
Author: Steven 
******************************************************************************/

/**
  * @brief  MCU(Microcontroller Unit Driver)
  * @param  
  * @retval 
  */

 typedef enum{
    MCU_PLL_STATUS_UNDEFINED,
    MCU_PLL_STATUS_LOCKED,
    MCU_PLL_STATUS_UNLOCKED
 }Mcu_PllStatusType;

  typedef enum{
    E_OK,
    E_NOT_OK
 }Std_Return_Type;

void Mcu_Init(const Mcu_ConfigType * ConfigPtr);
Std_Return_Type Mcu_InitClock(Mcu_ClockType ClockSetting);
Mcu_PllStatusType Mcu_GetPllStatus(void);
void Mcu_DistributePllClock(void);
Std_Return_Type Mcu_InitRamSection(Mcu_RamSectionType RamSection);

/** Usage Mcu
 * 
 Mcu_Init(&McuConfigPB)

 void McuFunc_InitializeClock(void)
 {
     Mcu_InitClock(McuConf_McuClockSettingConfig_McuClockSettingConfig);
     while(MCU_PLL_STATUS_LOCKED != Mcu_GetPllStatus)
     {

     }
     Mcu_DistributePllClock();
 }
   **/

  
/**
  * @brief  GPT(General Purpose Timer Driver)
  * @param  ONESHORT   CONTINUOUS
  * @retval 
  */
 void Gpt_Init(const Gpt_ConfigType *configPtr);
 void Gpt_EnableNotification(Gpt_ChannelType channel);
 void Gpt_StartTimer(Gpt_ChannelType channel, Gpt_ValueType value);

 /**Usage Gpt
 * 
 Gpt_Init(&GptChannelConfigSet_0);

 Gpt_EnableNotification(GptConf_GptChannelConfiguration_OsCounter);

 Gpt_StartTimer(GptConf_GptChannelConfiguration_OsCounter, OSCYCLESPERSECOND);

 void Gpt_Cbk_ProcessOsCounter(void)
 {
     IncrementCounter(Rte_TickCounter);
 }
   **/

/**
 * @brief  PORT(PORTDriver)
 * @param  
 * @retval 
 */
void Port_Init(const Port_ConfigType *ConfigPtr);

 /**Usage Gpt
 * 
 Port_Init(&PortConfigSet_o);
   **/

  /**
  * @brief  DIO(Digital Input / Output Driver)
  * @param  ONESHORT   CONTINUOUS
  * @retval 
  */
 void Dio_Init(const Dio_ConfigType *ConfigPtr);
 void Dio_WriteChannel(const Dio_ChannelType ChannelId, const Dio_LevelType Level);
 Dio_LevelType Dio_ReadChannel(const Dio_ChannelType ChannelId);
 Dio_LevelType Dio_FlipChannel(const Dio_ChannelType ChannelId);

   /**
  * @brief  ADC(Analog-to-Digital converter Driver)
  * @param  ONESHORT   CONTINUOUS
  * @retval 
  */

 typedef enum {
     ADC_IDLE,
     ADC_BUSY,
     ADC_COMPLETED,
     ADC_STREAM_COMPLETED

 }Adc_StatusType;
 
 void Adc_Init(const Adc_ConfigType *pConfigPtr);
 Std_Return_Type Adc_SetUpResultBuffer(Adc_GroupType group, Adc_ValueGroupType *pDataBufferPtr);

 Std_Return_Type Adc_ReadGroup(Adc_GroupType group, Adc_ValueGroupType *pDataBufferPtr);
 Adc_StreamNumSampleType Adc_GetStreamLastPointer(Adc_GroupType group, Adc_ValueGroupType *pDataBufferPtr);

 void Adc_StartGroupConversion(Adc_GroupType group);
  void Adc_StopGroupConversion(Adc_GroupType group);
  Adc_StatusType Adc_GetGroupStatus(Adc_GroupType group);

     /**
  * @brief  Pwm(Pulse Width Modulation Driver)
  * @param  ONESHORT   CONTINUOUS
  * @retval 
  */
 void Pwm_Init(const Pwm_ConfigType* ConfigPtr);
 void Pwm_SetDutyCycle(Pwm_ChannelType ChannelNum, uint16 Duty Cycle);

/**
  * @brief  Pwm(Pulse Width Modulation Driver)
  * @param  ONESHORT   CONTINUOUS
  * @retval 
  */
 typedef struct 
 {
     Icu_ValueType ActiveTime;
     Icu_ValueType PeriodTime;
 }Icu_DutyCycleType;

 void Icu_Init(const Icu_ConfigType *ConfigPtr);
 void Icu_GetDutyCycleValues(Icu_channelType Channel, Icu_DutyCycleType *DutyCycleValues);

/**Usage Gpt
 * 
 1.高低电平时间测量(hight time/low time Mesurement)
 2.占空比测量（Duty Cycle Mesurement）
 3.周期性信号时间测量（Period time mesurement）
 4.信号边沿检测和通知（Edge Detection And Notification）
 5.边沿计数（Edge Counting）
 6.边沿时间戳获取（Edge Time Stamping）
 7.中断唤醒（Wake-up Interrupt）
**/


