#ifndef __UTIL_H__
#define __UTIL_H__

#include "lw_stm32_uart.h"

/*****************�ӳٺ���********************************/
/*---------------------------------
����������ʱ������ʽ��delaynus����, 
��  ��������1��Ϊ1ms
-----------------------------------*/
void delayms(unsigned int ms);
/*---------------------------------
����������ʱ������ʽ��delay����, 
��  ��������1��Ϊ1s
-----------------------------------*/
void delay(unsigned long n);

void debug_printf_m(uint8_t *m) ;
void debug_printf_h(uint8_t m);
void debug_printf_s(uint8_t *m);

#endif
