/**
  ******************************************************************************
  * @file    sys_delay.c
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

#include "sys_delay.h"

/**
  * @brief  系统延时函数
  * @param  ns		延时毫秒
  * @retval 无
  */
void delay_us(u32 us)
{
//系统时间片长度为1ms，暂时无法实现us延时
}
	

/**
  * @brief  系统延时函数
  * @param  ms		延时毫秒
  * @retval 无
  */
void delay_ms(u32 ms)
{
	//portTICK_RATE_MS
	//跟踪代码可知时间片长度为1ms
	//该表达式意思是延时n个时间片，即为n个ms
	vTaskDelay(ms/portTICK_RATE_MS);
}











