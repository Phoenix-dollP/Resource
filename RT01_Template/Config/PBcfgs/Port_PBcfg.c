/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Port_PBcfg.c For Nxp S32K14x Series
Author: Steven
******************************************************************************/
#include "Port_PBcfg.h"
#include "Port_Define.h"

static const Port_GpioCfgType PortGpioCfg[] = 
{
    /* PID  DDR         DOR         IDR */
    {PORTA, 0x00003808, 0x00000000, 0x00000000},
    {PORTB, 0x00003028, 0x00000000, 0x00000000},
    {PORTC, 0x00010020, 0x00000000, 0x00000000},
    {PORTD, 0x0000003C, 0x00000000, 0x00000000},
    {PORTE, 0x00000202, 0x00000000, 0x00000000},
};

static const Port_PpcrCfgType PortPpcrCfg[] = 
{
    /* PID  Pin. PCRv */
    {PORTA, 0,   0x00000100UL},  /* LPI2C0_SCL(GPIO) */
    {PORTA, 1,   0x00000100UL},  /* LPI2C0_SDA(GPIO) */
    {PORTA, 3,   0x00000100UL},  /* GPIO MOTOR_BIN2 */
    {PORTA, 7,   0x00000100UL},  /* GPIO Sensor_SCL */
    {PORTA, 11,  0x00000100UL},  /* GPIO LCM_EN */
    {PORTA, 12,  0x00000100UL},  /* GPIO LCM_RST */
    {PORTA, 13,  0x00000100UL},  /* GPIO XRST */
    {PORTB, 1,   0x00000000UL},  /* ADC0_SE5 TMP */
    {PORTB, 2,   0x00000200UL},  /* FTM1CH0 BL_PWM */
    {PORTB, 3,   0x00000100UL},  /* GPIO BL_EN */
    {PORTB, 5,   0x00000100UL},  /* GPIO ON/OFF */
    {PORTB, 12,  0x00000100UL},  /* GPIO MOTOR_nSLEEP */
    {PORTB, 13,  0x00000100UL},  /* GPIO MT_EN */
    {PORTC, 0,   0x00000300UL},  /* LPSPI2_SIN FLASH */
    {PORTC, 1,   0x00000300UL},  /* LPSPI2_SOUT FLASH */
    {PORTC, 2,   0x00000300UL},  /* CAN0_RX */
    {PORTC, 3,   0x00000300UL},  /* CAN0_TX */
    {PORTC, 5,   0x00000100UL},  /* GPIO SPI_SW */
    {PORTC, 6,   0x00000200UL},  /* LPUART1_RX FPGA */
    {PORTC, 7,   0x00000200UL},  /* LPUART1_TX FPGA */
    {PORTC, 8,   0x00000100UL},  /* GPIO Sensor_SDA */
    {PORTC, 9,   0x00000100UL},  /* GPIO Sensor_INT */
    {PORTC, 14,  0x00000100UL},  /* GPIO Flash PCS0 */
    {PORTC, 15,  0x00000300UL},  /* LPSPI2_SCK FLASH */
    {PORTC, 16,  0x00000100UL},  /* GPIO VCC5V_EN FPGA */
    {PORTC, 17,  0x00000000UL},  /* ADC0_SE15 VBAT_DET */
    {PORTD, 0,   0x00000300UL},  /* LPSPI1_SCK FPGA */
    {PORTD, 1,   0x00000300UL},  /* LPSPI1_SIN FPGA */
    {PORTD, 2,   0x00000100UL},  /* GPIO MOTOR_BIN2 */
    {PORTD, 3,   0x00000100UL},  /* GPIO MOTOR_AIN2 */
    {PORTD, 4,   0x00000100UL},  /* GPIO MOTOR_AIN1 */
    {PORTD, 5,   0x00000100UL},  /* GPIO CAN_STB */
    {PORTD, 6,   0x00000200UL},  /* UART0_RX DEBUG */
    {PORTD, 7,   0x00000200UL},  /* UART0_TX DEBUG */
    {PORTE, 0,   0x00000500UL},  /* LPSPI1_SOUT FPGA */
    {PORTE, 1,   0x00000100UL},  /* GPIO FPGA PCS0 */
    {PORTE, 2,   0x00000100UL},  /* GPIO SPI0_EN  FLASH供电控制 */
    {PORTE, 7,   0x00000100UL},  /* GPIO KEY */
    {PORTE, 8,   0x00000100UL},  /* GPIO ACC */
    {PORTE, 9,   0x00000100UL},  /* GPIO LED */
};

/* Port Configuration */
static const Port_ConfigType PortConfig = 
{
    PortGpioCfg,  /* GpioCfg */
    PortPpcrCfg,  /* PpcrCfg */
    sizeof(PortGpioCfg)/sizeof(PortGpioCfg[0]), /* GpioNum */
    sizeof(PortPpcrCfg)/sizeof(PortPpcrCfg[0]), /* PpcrNum */
};

const Port_ConfigType* const PortCfgPtr = &PortConfig;

