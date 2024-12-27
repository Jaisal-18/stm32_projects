#include "uart_head.h"
#include <string.h>

unsigned int flag=0;

void led_on(void)
{
	for(int i=0;flag;i++)
	{
		if(i==4)
			i=0;
		JAI_GPTR->ODR|=(1<<i);
		delay(1);
		JAI_GPTR->ODR&=~(1<<i);
		delay(1);
	}
}
void led_off(void)
{
	JAI_GPTR->ODR&=~(1<<0);
	JAI_GPTR->ODR&=~(1<<1);
	JAI_GPTR->ODR&=~(1<<2);
	JAI_GPTR->ODR&=~(1<<3);
}
char buff[16];
unsigned int index=0;
int main()
{
	sys_clk_8();
	UART_config();
	gpio_config();
	led_config();
	unsigned char data;
	unsigned int i;
	while(1)
	{
		data=receive_data();
		send_data(data);
		if((data == '\n')||(data == '\r'))
		{
			buff[index+1]='\0';
			send_data('\r');
			send_data('\n');
			for(i=0;i<index;i++)
			{
				send_data(buff[i]);
			}
			if(strcmp(buff,"on")==0)
			{
				send_data('\r');
			  send_data('\n');
				send_data('Z');
				flag=1;
				led_on();
				memset(buff,0,sizeof(buff));
				index=0;
			}
			if(strcmp(buff,"off")==0)
			{
				send_data('\r');
			  send_data('\n');
				send_data('W');
				flag=0;
				led_off();
				memset(buff,0,sizeof(buff));
				index=0;
			}
			memset(buff,0,sizeof(buff));
			send_data('\r');
			send_data('\n');
			index=0;
		}
		else
		{
			buff[index++]=data;
			if(index>=sizeof(buff))
			{
				send_data('\r');
				send_data('\n');
				send_data('b');
				send_data('u');
				send_data('f');
				send_data('f');
				send_data(' ');
				send_data('f');
				send_data('u');
				send_data('l');
				send_data('l');
				send_data('\r');
				send_data('\n');
				memset(buff,0,sizeof(buff));
				index=0;
			}
		}
	}
}
