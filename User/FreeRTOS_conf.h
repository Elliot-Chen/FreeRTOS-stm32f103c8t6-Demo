/**
  ******************************************************************************
  * @file    bsp_conf.h 
  * @author  Elliot-Chen
  * @version V1.0
  * @date    16-April-2019
  * @brief   Board Support Package Library configuration file.
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __OS_CONF_H
#define __OS_CONF_H



/* Includes ------------------------------------------------------------------*/
/* Uncomment/Comment the line below to enable/disable OS(Operating System) header file inclusion */
#include "FreeRTOS.h" //OSÍ·ÎÄ¼þ
#include "task.h"
#include "queue.h"
#include "list.h"

#include "FreeRTOSConfig.h"
//#include "sys_delay.h"


#endif
/******************END OF FILE*****************/
