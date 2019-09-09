/**
  ******************************************************************************
  * @file    bsp_conf.h 
  * @author  Elliot-Chen
  * @version V1.0
  * @date    9-Setember-2019
  * @brief   Board Support Package Library configuration file.
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_CONF_H
#define __BSP_CONF_H



/* Includes ------------------------------------------------------------------*/
/* Uncomment/Comment the line below to enable/disable BSP(Board Support Package) header file inclusion */
/* �����bsp����ͷ�ļ� */

#include "stdio.h"
//#include "delay.h"	//ʹ��OSʱ���ø���ʱ�ļ�

#include "bsp_led.h"
#include "bsp_usart1.h"
//#include "bsp_key.h"


/* Includes ------------------------------------------------------------------*/
/* Uncomment/Comment the line below to enable/disable OS(Operating System) header file inclusion */
/* �����OS����ͷ�ļ� */
#if SYSTEM_SUPPORT_OS

	#include "FreeRTOSConfig.h" //FreeRTOS�����ļ�����FreeRTOSԴ����и���оƬ�ͺſ���
	#include "FreeRTOS.h" 		//FreeRTOSͷ�ļ�
	#include "task.h"
	#include "queue.h"
	#include "list.h"

	#include "sys_delay.h"	//����OS����ʱ��������Ҫ��ʱ��bsp�ļ������ͷ�ļ�"FreeRTOSConfig.h"

#endif

#endif
/******************END OF FILE*****************/

