/**
  ******************************************************************************
  * @file    FreeRTOS_delay.h
  * @author  Elliot-C
  * @version V1.0
  * @date    9-Setember-2019
  * @brief   基于FreeRTOS系统时钟延时文件
  ******************************************************************************
  * @attention
  *
  * 
  * 
  * 
  *
  ******************************************************************************
  */
  
#ifndef __SYS_DELAY_H
#define __SYS_DELAY_H

#include "stm32f10x.h"
#include "bsp_conf.h"


void delay_us(u32 us);
void delay_ms(u32 ms);



#endif
