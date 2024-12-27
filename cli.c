#include "gpio.h"
#include "serial.h"
#include <string.h>
char buff[16];
unsigned short int index=0;
void cln_fun(void)
{
unsigned char data;
	while(1)
	{
		data=serial_getc();
		serial_putc(data);
		if(data=='\n'||data=='\r')
		{
			buff[index+1]='\0';
			serial_putc('\n');
			serial_putc('\r');
			for(int i=0;i<index;i++)
			{
				serial_putc(buff[i]);
			}
			memset(buff,'\0',sizeof(buff));
			index=0;
			serial_putc('\n');
			serial_putc('\r');
		}
		else
		{
			buff[index++]=data;
			if(index>=sizeof(buff))
			{
				 serial_putc('\n');
			   serial_putc('\r');
				 serial_putc('f');
				 serial_putc('u');
				 serial_putc('l');
				 serial_putc('l');
				 memset(buff,'\0',sizeof(buff));
				 index=0;
				 serial_putc('\n');
				 serial_putc('\r');
			}
		}
	}
}