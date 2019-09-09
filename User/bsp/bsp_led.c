/**
  ******************************************************************************
  * @file    bsp_led.c
  * @author  Elliot-C
  * @version V1.0
  * @date    9-Setember-2019
  * @brief   LED���������ļ�
  ******************************************************************************
  * @attention
  *
  * 
  * 
  * 
  *
  ******************************************************************************
  */
  
#include "bsp_led.h"   

/**
  * @brief  LED��test
  * @param  ��
  * @retval ��
  */
void LED_test(void)
{
	LED1(ON);
	delay_ms(500);
		
	LED1(OFF);
	delay_ms(500);
}


 /**
  * @brief  ��ʼ������LED��IO
  * @param  ��
  * @retval ��
  */
void LED_GPIO_Config(void)
{		
		/*����һ��GPIO_InitTypeDef���͵Ľṹ��*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*����LED������ʱ��*/
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE); 

		/*ѡ��Ҫ���Ƶ�GPIOB����*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;	

		/*��������ģʽΪͨ���������*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*������������Ϊ50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*���ÿ⺯������ʼ��GPIO*/
		GPIO_Init(GPIOA, &GPIO_InitStructure);	
		
		/*ѡ��Ҫ���Ƶ�����*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		GPIO_Init(GPIOA, &GPIO_InitStructure);

		/* �ر�����led��	*/
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
}
/*********************************************END OF FILE**********************/
