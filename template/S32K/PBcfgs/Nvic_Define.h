/******************************************************************************
Copyright (C) 2020 Querda Electronic Technology All Rights Reserved

This software and code can be freely used for study and research. 
For commercial purposes, please contact the owner for permission.

File  : Nvic_Define.h  Nxp S32K14x NVIC driver
Author: Steven
******************************************************************************/
#ifndef NVIC_DEFINE_H
#define NVIC_DEFINE_H

#define NVIC_IRQ_DMA0           (0U)    /* DMA channel 0 transfer complete */
#define NVIC_IRQ_DMA1           (1U)    /* DMA channel 1 transfer complete */
#define NVIC_IRQ_DMA2           (2U)    /* DMA channel 2 transfer complete */
#define NVIC_IRQ_DMA3           (3U)    /* DMA channel 3 transfer complete */
#define NVIC_IRQ_DMA4           (4U)    /* DMA channel 4 transfer complete */
#define NVIC_IRQ_DMA5           (5U)    /* DMA channel 5 transfer complete */
#define NVIC_IRQ_DMA6           (6U)    /* DMA channel 6 transfer complete */
#define NVIC_IRQ_DMA7           (7U)    /* DMA channel 7 transfer complete */
#define NVIC_IRQ_DMA8           (8U)    /* DMA channel 8 transfer complete */
#define NVIC_IRQ_DMA9           (9U)    /* DMA channel 9 transfer complete */
#define NVIC_IRQ_DMA10          (10U)   /* DMA channel 10 transfer complete */
#define NVIC_IRQ_DMA11          (11U)   /* DMA channel 11 transfer complete */
#define NVIC_IRQ_DMA12          (12U)   /* DMA channel 12 transfer complete */
#define NVIC_IRQ_DMA13          (13U)   /* DMA channel 13 transfer complete */
#define NVIC_IRQ_DMA14          (14U)   /* DMA channel 14 transfer complete */
#define NVIC_IRQ_DMA15          (15U)   /* DMA channel 15 transfer complete */
#define NVIC_IRQ_DMA_ERR        (16U)   /* DMA error interrupt channels 0-15 */
#define NVIC_IRQ_MCM            (17U)   /* FPU sources */
#define NVIC_IRQ_FTFC           (18U)   /* FTFC Command complete */
#define NVIC_IRQ_FTFC_READ      (19U)   /* FTFC Read collision */
#define NVIC_IRQ_LVD_LVW        (20U)   /* PMC Low voltage detect interrupt */
#define NVIC_IRQ_FTFC_FAULT     (21U)   /* FTFC Double bit fault detect */
#define NVIC_IRQ_WDOG_EWM       (22U)   /* Single interrupt vector for WDOG and EWM */
#define NVIC_IRQ_RCM            (23U)   /* RCM Asynchronous Interrupt */
#define NVIC_IRQ_LPI2C0_MASTER  (24U)   /* LPI2C0 Master Interrupt */
#define NVIC_IRQ_LPI2C0_SLAVE   (25U)   /* LPI2C0 Slave Interrupt */
#define NVIC_IRQ_LPSPI0         (26U)   /* LPSPI0 Interrupt */
#define NVIC_IRQ_LPSPI1         (27U)   /* LPSPI1 Interrupt */
#define NVIC_IRQ_LPSPI2         (28U)   /* LPSPI2 Interrupt */
#define NVIC_IRQ_LPUART0        (31U)   /* LPUART0 Transmit Receive Interrupt */
#define NVIC_IRQ_LPUART1        (33U)   /* LPUART1 Transmit Receive  Interrupt */
#define NVIC_IRQ_LPUART2        (35U)   /* LPUART2 Transmit Receive  Interrupt */
#define NVIC_IRQ_ADC0           (39U)   /* ADC0 interrupt request. */
#define NVIC_IRQ_ADC1           (40U)   /* ADC1 interrupt request. */
#define NVIC_IRQ_CMP0           (41U)   /* CMP0 interrupt request */
#define NVIC_IRQ_ERM_SF         (44U)   /* ERM single bit error correction */
#define NVIC_IRQ_ERM_DF         (45U)   /* ERM double bit error non-correctable */
#define NVIC_IRQ_RTC_ALARM      (46U)   /* RTC alarm interrupt */
#define NVIC_IRQ_RTC_SECONDS    (47U)   /* RTC seconds interrupt */
#define NVIC_IRQ_LPIT0_CH0      (48U)   /* LPIT0 channel 0 overflow interrupt */
#define NVIC_IRQ_LPIT0_CH1      (49U)   /* LPIT0 channel 1 overflow interrupt */
#define NVIC_IRQ_LPIT0_CH2      (50U)   /* LPIT0 channel 2 overflow interrupt */
#define NVIC_IRQ_LPIT0_CH3      (51U)   /* LPIT0 channel 3 overflow interrupt */
#define NVIC_IRQ_PDB0           (52U)   /* PDB0 interrupt */
#define NVIC_IRQ_SCG            (57U)   /* SCG bus interrupt request */
#define NVIC_IRQ_LPTMR0         (58U)   /* LPTIMER interrupt request */
#define NVIC_IRQ_PORTA          (59U)   /* Port A pin detect interrupt */
#define NVIC_IRQ_PORTB          (60U)   /* Port B pin detect interrupt */
#define NVIC_IRQ_PORTC          (61U)   /* Port C pin detect interrupt */
#define NVIC_IRQ_PORTD          (62U)   /* Port D pin detect interrupt */
#define NVIC_IRQ_PORTE          (63U)   /* Port E pin detect interrupt */
#define NVIC_IRQ_SWI            (64U)   /* Software interrupt */
#define NVIC_IRQ_PDB1           (68U)   /* PDB1 interrupt */
#define NVIC_IRQ_FLEXIO         (69U)   /* FlexIO Interrupt */
#define NVIC_IRQ_CAN0_ORED      (78U)   /* CAN0 OR'ed [Bus Off OR Transmit Warning OR Receive Warning] */
#define NVIC_IRQ_CAN0_ERROR     (79U)   /* CAN0 Interrupt indicating that errors were detected on the CAN bus */
#define NVIC_IRQ_CAN0_WAKEUP    (80U)   /* CAN0 Interrupt asserted when Pretended Networking operation is enabled, and a valid message matches the selected filter criteria during Low Power mode */
#define NVIC_IRQ_CAN0_MB00_15   (81U)   /* CAN0 OR'ed Message buffer (0-15) */
#define NVIC_IRQ_CAN0_MB16_31   (82U)   /* CAN0 OR'ed Message buffer (16-31) */
#define NVIC_IRQ_CAN1_ORED      (85U)   /* CAN1 OR'ed [Bus Off OR Transmit Warning OR Receive Warning] */
#define NVIC_IRQ_CAN1_ERROR     (86U)   /* CAN1 Interrupt indicating that errors were detected on the CAN bus */
#define NVIC_IRQ_CAN1_MB00_15   (88U)   /* CAN1 OR'ed Interrupt for Message buffer (0-15) */
#define NVIC_IRQ_CAN2_ORED      (92U)   /* CAN2 OR'ed [Bus Off OR Transmit Warning OR Receive Warning] */
#define NVIC_IRQ_CAN2_ERROR     (93U)   /* CAN2 Interrupt indicating that errors were detected on the CAN bus */
#define NVIC_IRQ_CAN2_MB00_15   (95U)   /* CAN2 OR'ed Message buffer (0-15) */
#define NVIC_IRQ_FTM0_CH01      (99U)   /* FTM0 Channel 0 and 1 interrupt */
#define NVIC_IRQ_FTM0_CH23      (100U)  /* FTM0 Channel 2 and 3 interrupt */
#define NVIC_IRQ_FTM0_CH45      (101U)  /* FTM0 Channel 4 and 5 interrupt */
#define NVIC_IRQ_FTM0_CH67      (102U)  /* FTM0 Channel 6 and 7 interrupt */
#define NVIC_IRQ_FTM0_FAULT     (103U)  /* FTM0 Fault interrupt */
#define NVIC_IRQ_FTM0_OVERFLOW  (104U)  /* FTM0 Counter overflow and Reload interrupt */
#define NVIC_IRQ_FTM1_CH01      (105U)  /* FTM1 Channel 0 and 1 interrupt */
#define NVIC_IRQ_FTM1_CH23      (106U)  /* FTM1 Channel 2 and 3 interrupt */
#define NVIC_IRQ_FTM1_CH45      (107U)  /* FTM1 Channel 4 and 5 interrupt */
#define NVIC_IRQ_FTM1_CH67      (108U)  /* FTM1 Channel 6 and 7 interrupt */
#define NVIC_IRQ_FTM1_FAULT     (109U)  /* FTM1 Fault interrupt */
#define NVIC_IRQ_FTM1_OVERFLOW  (110U)  /* FTM1 Counter overflow and Reload interrupt */
#define NVIC_IRQ_FTM2_CH01      (111U)  /* FTM2 Channel 0 and 1 interrupt */
#define NVIC_IRQ_FTM2_CH23      (112U)  /* FTM2 Channel 2 and 3 interrupt */
#define NVIC_IRQ_FTM2_CH45      (113U)  /* FTM2 Channel 4 and 5 interrupt */
#define NVIC_IRQ_FTM2_CH67      (114U)  /* FTM2 Channel 6 and 7 interrupt */
#define NVIC_IRQ_FTM2_FAULT     (115U)  /* FTM2 Fault interrupt */
#define NVIC_IRQ_FTM2_OVERFLOW  (116U)  /* FTM2 Counter overflow and Reload interrupt */
#define NVIC_IRQ_FTM3_CH01      (117U)  /* FTM3 Channel 0 and 1 interrupt */
#define NVIC_IRQ_FTM3_CH23      (118U)  /* FTM3 Channel 2 and 3 interrupt */
#define NVIC_IRQ_FTM3_CH45      (119U)  /* FTM3 Channel 4 and 5 interrupt */
#define NVIC_IRQ_FTM3_CH67      (120U)  /* FTM3 Channel 6 and 7 interrupt */
#define NVIC_IRQ_FTM3_FAULT     (121U)  /* FTM3 Fault interrupt */
#define NVIC_IRQ_FTM3_OVERFLOW  (122U)  /* FTM3 Counter overflow and Reload interrupt */

#endif

