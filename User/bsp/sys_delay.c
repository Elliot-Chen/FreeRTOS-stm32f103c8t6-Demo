/**
  ******************************************************************************
  * @file    sys_delay.c
  * @author  Elliot-C
  * @version V1.0
  * @date    9-Setember-2019
  * @brief   ����FreeRTOSϵͳʱ����ʱ�ļ�
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
  * @brief  ϵͳ��ʱ����
  * @param  ns		��ʱ����
  * @retval ��
  */
void delay_us(u32 us)
{
//ϵͳʱ��Ƭ����Ϊ1ms����ʱ�޷�ʵ��us��ʱ
}
	

/**
  * @brief  ϵͳ��ʱ����
  * @param  ms		��ʱ����
  * @retval ��
  */
void delay_ms(u32 ms)
{
	//portTICK_RATE_MS
	//���ٴ����֪ʱ��Ƭ����Ϊ1ms
	//�ñ��ʽ��˼����ʱn��ʱ��Ƭ����Ϊn��ms
	vTaskDelay(ms/portTICK_RATE_MS);
}











