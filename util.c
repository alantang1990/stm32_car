#include "util.h"

/*****************�ӳٺ���********************************/
/*---------------------------------
����������ʱ������ʽ��delaynus����, 
��  ��������1��Ϊ1ms
-----------------------------------*/
void delayms(unsigned int ms) 
{
  unsigned char k;
  while(ms--)
  {
    for(k = 0; k < 114; k++);
  }
}
/*---------------------------------
����������ʱ������ʽ��delay����, 
��  ��������1��Ϊ1s
-----------------------------------*/
void delay(unsigned long n)
{
 while(n--)
  delayms(1000);
}


void debug_printf_m(uint8_t *m) 
{
	com_send_message(2, m);
}

void debug_printf_h(uint8_t m)
{
	com_send_hex(2, m);
}

void debug_printf_s(uint8_t *m)
{
	com_send_string(2, m);
}




