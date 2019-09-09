/**
  ******************************************************************************
  * @file    bsp_led.h
  * @author  Elliot-C
  * @version V1.0
  * @date    9-Setember-2019
  * @brief   LED板载配置文件
  ******************************************************************************
  * @attention
  *
  * 
  * 
  * 
  *
  ******************************************************************************
  */
#ifndef __LED_H
#define	__LED_H

#include "stm32f10x.h"
#include "bsp_conf.h"

/* if use OS */	
#if SYSTEM_SUPPORT_OS
	#include "FreeRTOSConfig.h" //FreeRTOS配置文件
#endif

/** the macro definition to trigger the led on or off 
  * 1 - off
  *0 - on
  */
#define ON  0
#define OFF 1

/* 带参宏，可以像内联函数一样使用 */
#define LED1(a)	if (a)	\
					GPIO_SetBits(GPIOA,GPIO_Pin_1);\
					else		\
					GPIO_ResetBits(GPIOA,GPIO_Pin_1)

#define LED2(a)	if (a)	\
					GPIO_SetBits(GPIOC,GPIO_Pin_4);\
					else		\
					GPIO_ResetBits(GPIOC,GPIO_Pin_4)

#define LED3(a)	if (a)	\
					GPIO_SetBits(GPIOC,GPIO_Pin_3);\
					else		\
					GPIO_ResetBits(GPIOC,GPIO_Pin_3)




void LED_GPIO_Config(void);
void LED_test(void);

#endif /* __LED_H */
