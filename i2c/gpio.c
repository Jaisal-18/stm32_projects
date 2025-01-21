#include "gpio.h"
#include "serial.h"
void I2C_init(void)
{
	//clock set
	JAI_APB1|=(1<<21);// clock for I2C1;
	JAI_APB2|=(1<<3);//Clock for PB 6&7
	//gpio_set
	JAIGPIOB->CRL &=~(0XFF << 24);//clear gpio
	JAIGPIOB->CRL |=(0xEE <<24);//set GPIO in alternative opedrain output mode 50hz.
	//i2c config
	JAI_I2C->CR2=8;//my hsi default
	JAI_I2C->CCR=40;// ccr=(apb1/2*speed)-1;
	JAI_I2C->TRISE=9;//trise=(apb1/10^6 )+1;
	JAI_I2C->CR1|=(1<<0);
}
void I2C_start(void)
{
	JAI_I2C->CR1|=(1<<8);
	while(!(JAI_I2C->SR1 & (1<<0)));
}
void I2C_stop(void)
{
	JAI_I2C->CR1|=(1<<9);
}

void I2C_write(unsigned char data)
{
	JAI_I2C->DR=data;
	send_data('u');
	while(!(JAI_I2C->SR1 &(1<<7)));
	if(JAI_I2C->SR1 & (1<<7))
	{
		send_data('q');// for mem_addr this is not printing.
	}
}
unsigned char I2C_read(void)
{
	while(!(JAI_I2C->SR1 & (1<<6)));
	return JAI_I2C->DR;
}