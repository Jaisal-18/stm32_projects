#include "serial.h"
#include "command.h"
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
			execute_cmd(buff);
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
				 serial_gets("buffer is full");
				 memset(buff,'\0',sizeof(buff));
				 index=0;
				 serial_putc('\n');
				 serial_putc('\r');
			}
		}
	}
}