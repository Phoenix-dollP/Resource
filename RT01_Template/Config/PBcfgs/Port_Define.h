/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Port_Define For Nxp S32K14x Series
Author: Steven
******************************************************************************/
#ifndef PORT_DEF_H
#define PORT_DEF_H

#define PORTA    (0)
#define PORTB    (1)
#define PORTC    (2)
#define PORTD    (3)
#define PORTE    (4)

#define PORT_DEBUG_LED      (PORTE*32 + 9)    //LED1   FPGA供电使能控制
#define PORT_VCC5V_EN       (PORTC*32 + 16)	  //VCC5V_EN   LED指示灯，用作调试状态显示
#define PORT_BL_EN          (PORTB*32 + 3)    //BL_EN   背光供电使能开关
#define PORT_ON_OFF         (PORTB*32 + 5)    //BL_ON_OFF   整机HUD开关
#define PORT_ACC            (PORTE*32 + 8)    //ACC   ON档检测
#define PORT_BL_PWM         (PORTB*32 + 2)    //BL_PWM   背光亮度控制控制
#define PORT_TMP            (PORTB*32 + 1)    //TMP   背光温度监测
#define PORT_BAT_DET        (PORTC*32 + 17)   //BAT_DET   电压监测
#define PORT_KEY            (PORTE*32 + 7)    //KEY   马达限位监测
#define PORT_XRST           (PORTA*32 + 13)   //XRST   纠畸变IC复位
#define PORT_LCM_RST        (PORTA*32 + 12)   //LCM_RST   LCM复位
#define PORT_LCM_EN         (PORTA*32 + 11)   //LCM_EN   LCM使能

#define PORT_CAN_TX         (PORTC*32 + 3)    //CAN_TX
#define PORT_CAN_RX         (PORTC*32 + 2)    //CAN_RX
#define PORT_CAN_STB        (PORTD*32 + 5)    //CAN_STB   CAN休眠

#define PORT_Epson_SCL      (PORTA*32 + 0)    //SCL   I2C时钟
#define PORT_Epson_SDA      (PORTA*32 + 1)    //SDA   I2C数据

#define PORT_Sensro_SCL     (PORTA*32 + 7)    //Sensro_SCL   I2C时钟
#define PORT_Sensro_SDA     (PORTC*32 + 8)    //Sensro_SDA   I2C数据
#define PORT_Sensro_INT     (PORTC*32 + 9)    //Sensro_INT   I2C中断

#define PORT_UART1_TX       (PORTC*32 + 7)    //UART1_TX   串口发送
#define PORT_UART1_RX       (PORTC*32 + 6)    //UART1_RX   串口接收

#define PORT_UART0_TX       (PORTD*32 + 7)    //UART0_TX   串口发送
#define PORT_UART0_RX       (PORTD*32 + 6)    //UART0_RX   串口接收

#define PORT_LPSPI2_SOUT    (PORTC*32 + 1)    //LPSPI2_SOUT   SPI 数据
#define PORT_LPSPI2_SIN     (PORTC*32 + 0)    //LPSPI2_SIN   SPI 数据
#define PORT_LPSPI2_SCK     (PORTC*32 + 15)   //LPSPI2_SCK   SPI SPI时钟
#define PORT_LPSPI2_PCS0    (PORTC*32 + 14)   //LPSPI2_PCS0   SPI片选
#define PORT_SPI_EN         (PORTE*32 + 2)    //SPI0_EN   SPI MCU端供电使能

#define PORT_LPSPI1_SOUT    (PORTE*32 + 0)    //LPSPI1_SOUT   SPI 数据
#define PORT_LPSPI1_SIN     (PORTD*32 + 1)    //LPSPI1_SIN   SPI 数据
#define PORT_LPSPI1_SCK     (PORTD*32 + 0)    //LPSPI1_SCK   SPI SPI时钟
#define PORT_LPSPI1_PCS0    (PORTE*32 + 1)    //LPSPI1_ PCS0   SPI片选
#define PORT_SPI_SW         (PORTC*32 + 5)    //SPI_SW   SPI切换

#define PORT_MOTOR_BIN1     (PORTA*32 + 3)    //MOTOR_BIN1
#define PORT_MOTOR_BIN2     (PORTD*32 + 2)    //MOTOR_BIN2
#define PORT_MOTOR_AIN1     (PORTD*32 + 3)    //MOTOR_AIN1
#define PORT_MOTOR_AIN2     (PORTD*32 + 4)    //MOTOR_AIN2
#define PORT_MOTOR_SLEEP    (PORTB*32 + 12)   //MOTOR_nSLEEP
#define PORT_MT_EN          (PORTB*32 + 13)   //MT_EN

#endif

