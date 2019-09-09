/**
  ******************************************************************************
  * @file    bsp_usart1.h
  * @author  Elliot-C
  * @version V1.0
  * @date    9-Setember-2019
  * @brief   usart∞Â‘ÿ≈‰÷√Œƒº˛
  ******************************************************************************
  * @attention
  *
  * 
  * 
  * 
  *
  ******************************************************************************
  */
#ifndef __USART1_H
#define	__USART1_H

#include "stm32f10x.h"
#include "bsp_conf.h"

#define UART_RX_LEN		1024
extern u8 Uart_Rx[UART_RX_LEN];


void USART1_Config(u32 BaudRate);

int fputc(int ch, FILE *f);
int fgetc(FILE *f);


#endif /* __USART1_H */
