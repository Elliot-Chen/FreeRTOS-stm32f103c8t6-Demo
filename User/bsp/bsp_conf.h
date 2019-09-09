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
/* 可添加bsp配置头文件 */

#include "stdio.h"
//#include "delay.h"	//使用OS时不用该延时文件

#include "bsp_led.h"
#include "bsp_usart1.h"
//#include "bsp_key.h"


/* Includes ------------------------------------------------------------------*/
/* Uncomment/Comment the line below to enable/disable OS(Operating System) header file inclusion */
/* 可添加OS配置头文件 */
#if SYSTEM_SUPPORT_OS

	#include "FreeRTOSConfig.h" //FreeRTOS配置文件，从FreeRTOS源码包中根据芯片型号拷贝
	#include "FreeRTOS.h" 		//FreeRTOS头文件
	#include "task.h"
	#include "queue.h"
	#include "list.h"

	#include "sys_delay.h"	//基于OS的延时函数，需要延时的bsp文件需包含头文件"FreeRTOSConfig.h"

#endif

#endif
/******************END OF FILE*****************/

