/**
  ******************************************************************************
  * @file    main.c
  * @author  Elliot-C
  * @version V1.0
  * @date    9-Setember-2019
  * @brief   用ST官方3.5.0版本库及FreeRTOS(v10.2.1)源码构建的工程模板
  ******************************************************************************
  * @attention
  * 该工程模板适用于stm32f103c8t6芯片
  * "bsp_conf.h"中包含有OS相关头文件
  * 
  * 
  *
  ******************************************************************************
  */
  
#include "stm32f10x.h"
#include "bsp_conf.h"



///**************任务1声明****************/
#define			START_TASK_PRIO			1		//任务优先级
#define			START_STK_SIZE			128		//任务堆栈大小
TaskHandle_t	StartTask_Handler;				//任务句柄
void start_task(void *pvParameters);			//任务函数声明

/**************任务2声明****************/
#define			USART_TASK_PRIO			2		//任务优先级
#define			USART_STK_SIZE			50		//任务堆栈大小
TaskHandle_t	USARTTask_Handler;				//任务句柄
void usart_task(void *pvParameters);			//任务函数声明

/**************任务2声明****************/
#define			LED_TASK_PRIO			3		//任务优先级
#define			LED_STK_SIZE			50		//任务堆栈大小
TaskHandle_t	LEDTask_Handler;				//任务句柄
void led_task(void *pvParameters);			//任务函数声明

/***************创建任务模板***************/
//在主函数里实现
//xTaskCreate((TaskFunction_t )start_task,         
//			(const char*    )"start_task",       
//			(uint16_t       )START_STK_SIZE, 
//			(void*          )NULL,              
//			(UBaseType_t    )START_TASK_PRIO,    
//			(TaskHandle_t*  )&StartTask_Handler);
//			
//vTaskDelete(StartTask_Handler); //删除开始任务
//taskEXIT_CRITICAL();            //退出临界区

/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//设置系统中断优先级分组4
//	delay_init();
	
	
	
	//创建开始任务，该任务会创建其他任务
	xTaskCreate((TaskFunction_t )start_task,         
				(const char*    )"start_task",       
				(uint16_t       )START_STK_SIZE, 
				(void*          )NULL,              
				(UBaseType_t    )START_TASK_PRIO,    
				(TaskHandle_t*  )&StartTask_Handler);
				
	vTaskStartScheduler();//开启任务调度
	  /* add your code here ^_^. */
}


//开始任务任务函数
void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();           //进入临界区
    //创建USART任务
	xTaskCreate((TaskFunction_t )usart_task,     	
				(const char*    )"usart_task",   	
				(uint16_t       )USART_STK_SIZE, 
				(void*          )NULL,				
				(UBaseType_t    )USART_TASK_PRIO,	
				(TaskHandle_t*  )&USARTTask_Handler);
				   
    //创建LED任务
	xTaskCreate((TaskFunction_t )led_task,     
				(const char*    )"led_task",   
				(uint16_t       )LED_STK_SIZE, 
				(void*          )NULL,
				(UBaseType_t    )LED_TASK_PRIO,
				(TaskHandle_t*  )&LEDTask_Handler);

	vTaskDelete(StartTask_Handler); //删除开始任务
    taskEXIT_CRITICAL();            //退出临界区
}

//LED任务函数 
void led_task(void *pvParameters)
{
	LED_GPIO_Config();
    while(1)
    {
		LED_test();	
	}
}   

void usart_task(void *pvParameters)
{
	USART1_Config(115200);
	while(1){
		//		printf("hello world!");		//测试用，已经实现串口接收和发送
//		vTaskDelay(1000/portTICK_RATE_MS);
	}
}

/*********************************************END OF FILE**********************/

