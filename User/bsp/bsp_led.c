/**
  ******************************************************************************
  * @file    bsp_led.c
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
  
#include "bsp_led.h"   

/**
  * @brief  LED棗test
  * @param  无
  * @retval 无
  */
void LED_test(void)
{
	LED1(ON);
	delay_ms(500);
		
	LED1(OFF);
	delay_ms(500);
}


 /**
  * @brief  初始化控制LED的IO
  * @param  无
  * @retval 无
  */
void LED_GPIO_Config(void)
{		
		/*定义一个GPIO_InitTypeDef类型的结构体*/
		GPIO_InitTypeDef GPIO_InitStructure;

		/*开启LED的外设时钟*/
		RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA, ENABLE); 

		/*选择要控制的GPIOB引脚*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;	

		/*设置引脚模式为通用推挽输出*/
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;   

		/*设置引脚速率为50MHz */   
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 

		/*调用库函数，初始化GPIO*/
		GPIO_Init(GPIOA, &GPIO_InitStructure);	
		
		/*选择要控制的引脚*/															   
		GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		GPIO_Init(GPIOA, &GPIO_InitStructure);

		/* 关闭所有led灯	*/
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
}
/*********************************************END OF FILE**********************/
