/**
  ******************************************************************************
  * @file    delay.c
  * @author  
  * @version 
  * @date    
  * @brief   ��ʱbsp�����ļ�
  ******************************************************************************
  * @attention
  *
  *  
  * 
  * 
  *
  ******************************************************************************
  */

#include	"delay.h"


/**
  * @brief  us��ʱ����
  * @param  i		��ʱi΢��
  * @retval none
  */
void delay_us(u32 i)
{
    u32 temp;
    SysTick->LOAD = 9*i;         //������װ��ֵ, 72MHZʱ
    SysTick->CTRL = 0X01;         //ʹ�ܣ����������޶����������ⲿʱ��Դ
    SysTick->VAL = 0;                //���������
    do
    {
        temp = SysTick->CTRL;           //��ȡ��ǰ������ֵ
    }
    while((temp & 0x01) && (!(temp & (1 << 16))));     //�ȴ�ʱ�䵽��
    SysTick->CTRL = 0;    //�رռ�����
    SysTick->VAL = 0;        //��ռ�����
}


/**
  * @brief  ms��ʱ����
  * @param  i		��ʱi����
  * @retval none
  */
void delay_ms(u32 i)
{
    u32 temp;
    SysTick->LOAD = 9000*i;      //������װ��ֵ, 72MHZʱ
    SysTick->CTRL = 0X01;        //ʹ�ܣ����������޶����������ⲿʱ��Դ
    SysTick->VAL = 0;            //���������
    do
    {
        temp = SysTick->CTRL;       //��ȡ��ǰ������ֵ
    }
    while((temp & 0x01) && (!(temp & (1 << 16))));    //�ȴ�ʱ�䵽��
    SysTick->CTRL = 0;    //�رռ�����
    SysTick->VAL = 0;        //��ռ�����
}
