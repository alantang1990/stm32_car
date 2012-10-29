#include <string.h>

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


/*
	��buf������ҷ���str��һ������
*/
uint8_t *memstr(uint8_t *buf, uint32_t buflen, uint8_t *str, uint32_t strlen)
{
	uint32_t i;
	uint8_t *p;

	while (buflen) {
		if ((p = memchr(buf, *str, buflen)) != NULL) {
			if (buflen - (p - buf) < strlen)
				return NULL;
			for (i=1; i<strlen; i++) {
				if (p[i] != str[i]){
					buflen -= p - buf;
					buf = p + 1;
					buflen -= 1;
					break;
				}
			}
			if (i == strlen) { /*find */
				return p;
			}
		}
		else {
			return NULL;
		}
	}

	return NULL;
}



