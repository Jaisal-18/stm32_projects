#include "serial.h"
#include "cli.h"
#include <string.h>
char buff[16];
unsigned short int index=0;
void console_read_input(void)
{
	unsigned char data=serial_getc();
	serial_putc(data);
	if(data=='\n'||data=='\r')
	{
		buff[index]='\0';
		cli_parse_and_execute(buff);//command_line_interpetr_function
		/*serial_puts("\r\n");
		serial_puts(buff);
		serial_puts("\r\n");*/
		memset(buff,'\0',sizeof(buff));
		index=0;
	}
	else
	{
		if(index<16-1)
			buff[index++]=data;
		else
		{
			serial_puts("\r\nthe buff is full\r\n");
			index=0;
			memset(buff,'\0',sizeof(buff));
		}
	}
}