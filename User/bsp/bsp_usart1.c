/**
  ******************************************************************************
  * @file    bsp_usart1.c
  * @author  Elliot-C
  * @version V1.0
  * @date    9-Setember-2019
  * @brief   usart板载配置文件
  ******************************************************************************
  * @attention
  *
  * 
  * 
  * 
  *
  ******************************************************************************
  */
#include "bsp_usart1.h"

u8 Uart_Rx[UART_RX_LEN];
u32 RxCounter;

void NVIC_USART_Config(void);


 /**
  * @brief  USART1 GPIO 配置,工作模式配置 8-N-1
  * @param  BaudRate		波特率
  * @retval 无
  */
void USART1_Config(u32 BaudRate)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	
	/* config USART1 clock */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_GPIOA, ENABLE);
	
	/* USART1 GPIO config */
	/* Configure USART1 Tx (PA.09) as alternate function push-pull */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);    
	/* Configure USART1 Rx (PA.10) as input floating */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	/* USART1 mode config */
	USART_InitStructure.USART_BaudRate = BaudRate;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No ;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStructure);
	
	/* 使能串口1接收中断 */
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	USART_ITConfig(USART1, USART_IT_IDLE, ENABLE);
	
	USART_Cmd(USART1, ENABLE);
	
	NVIC_USART_Config();
}

/// 配置USART1接收中断
void NVIC_USART_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure; 
	/* Configure the NVIC Preemption Priority Bits */  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
	
	/* Enable the USARTy Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;	 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

//USART1 Interrupt Server Function
void USART1_IRQHandler(void)	
{
	u8 clear = clear;
	USART_ClearFlag(USART1, USART_FLAG_TC);
 
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != Bit_RESET)        
	{
		Uart_Rx[RxCounter++] = USART1->DR;
	}
	else if(USART_GetFlagStatus(USART1,USART_FLAG_IDLE) != Bit_RESET)
	{					
		clear = USART1->SR;
		clear = USART1->DR;	
		printf("Receive Done Size:%d\r\n",RxCounter);
		printf("%s\r\n",Uart_Rx);
		RxCounter = 0;
	}	
					
}


// 重定向c库函数printf到USART1
int fputc(int ch, FILE *f)
{
	/* 读SR寄存器，防止第一个字符丢失 */
	USART1->SR;
	/* 发送一个字节数据到USART1 */
	USART_SendData(USART1, (uint8_t) ch);
	/* 等待发送完毕 */
	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);		

	return (ch);
}

// 重定向c库函数scanf到USART1
int fgetc(FILE *f)
{
		/* 等待串口1输入数据 */
		while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET);

		return (int)USART_ReceiveData(USART1);
}
/*********************************************END OF FILE**********************/
