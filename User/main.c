/**
  ******************************************************************************
  * @file    main.c
  * @author  Elliot-C
  * @version V1.0
  * @date    9-Setember-2019
  * @brief   ��ST�ٷ�3.5.0�汾�⼰FreeRTOS(v10.2.1)Դ�빹���Ĺ���ģ��
  ******************************************************************************
  * @attention
  * �ù���ģ��������stm32f103c8t6оƬ
  * "bsp_conf.h"�а�����OS���ͷ�ļ�
  * 
  * 
  *
  ******************************************************************************
  */
  
#include "stm32f10x.h"
#include "bsp_conf.h"



///**************����1����****************/
#define			START_TASK_PRIO			1		//�������ȼ�
#define			START_STK_SIZE			128		//�����ջ��С
TaskHandle_t	StartTask_Handler;				//������
void start_task(void *pvParameters);			//����������

/**************����2����****************/
#define			USART_TASK_PRIO			2		//�������ȼ�
#define			USART_STK_SIZE			50		//�����ջ��С
TaskHandle_t	USARTTask_Handler;				//������
void usart_task(void *pvParameters);			//����������

/**************����2����****************/
#define			LED_TASK_PRIO			3		//�������ȼ�
#define			LED_STK_SIZE			50		//�����ջ��С
TaskHandle_t	LEDTask_Handler;				//������
void led_task(void *pvParameters);			//����������

/***************��������ģ��***************/
//����������ʵ��
//xTaskCreate((TaskFunction_t )start_task,         
//			(const char*    )"start_task",       
//			(uint16_t       )START_STK_SIZE, 
//			(void*          )NULL,              
//			(UBaseType_t    )START_TASK_PRIO,    
//			(TaskHandle_t*  )&StartTask_Handler);
//			
//vTaskDelete(StartTask_Handler); //ɾ����ʼ����
//taskEXIT_CRITICAL();            //�˳��ٽ���

/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);//����ϵͳ�ж����ȼ�����4
//	delay_init();
	
	
	
	//������ʼ���񣬸�����ᴴ����������
	xTaskCreate((TaskFunction_t )start_task,         
				(const char*    )"start_task",       
				(uint16_t       )START_STK_SIZE, 
				(void*          )NULL,              
				(UBaseType_t    )START_TASK_PRIO,    
				(TaskHandle_t*  )&StartTask_Handler);
				
	vTaskStartScheduler();//�����������
	  /* add your code here ^_^. */
}


//��ʼ����������
void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();           //�����ٽ���
    //����USART����
	xTaskCreate((TaskFunction_t )usart_task,     	
				(const char*    )"usart_task",   	
				(uint16_t       )USART_STK_SIZE, 
				(void*          )NULL,				
				(UBaseType_t    )USART_TASK_PRIO,	
				(TaskHandle_t*  )&USARTTask_Handler);
				   
    //����LED����
	xTaskCreate((TaskFunction_t )led_task,     
				(const char*    )"led_task",   
				(uint16_t       )LED_STK_SIZE, 
				(void*          )NULL,
				(UBaseType_t    )LED_TASK_PRIO,
				(TaskHandle_t*  )&LEDTask_Handler);

	vTaskDelete(StartTask_Handler); //ɾ����ʼ����
    taskEXIT_CRITICAL();            //�˳��ٽ���
}

//LED������ 
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
		//		printf("hello world!");		//�����ã��Ѿ�ʵ�ִ��ڽ��պͷ���
//		vTaskDelay(1000/portTICK_RATE_MS);
	}
}

/*********************************************END OF FILE**********************/

