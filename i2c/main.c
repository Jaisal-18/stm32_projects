#include "gpio.h"
#include "serial.h"
#define slave_addr 0x50
unsigned short int mem_addr=0x0000;
int main()
{
	sys_clk_8();
	UART_config();
	gpio_config();
	
	I2C_init();
	I2C_start();
	I2C_write(slave_addr<<1);
	//up to here working
	I2C_write((mem_addr>>8)& 0xFF);//msb first
	send_data('p');
	I2C_write(mem_addr & 0xFF);
	send_data('h');
	I2C_write('A');
	I2C_stop();
	
	
	I2C_start();
	send_data('z');
	I2C_write(slave_addr<<1|1);
	send_data('p');
	unsigned char read=I2C_read();
	I2C_stop();
	
	while(1)
	{
		send_data(read);
	}
}