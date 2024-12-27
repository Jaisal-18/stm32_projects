#include "gpio.h"
void sys_clk_8(void)
{
	JAI_RPTR->CR|=(1<<0);//HSI ON
	while(!(JAI_RPTR->CR & (1<<1)));//WAITING FOR HSI TO READY;
	JAI_RPTR->CFGR&=~(3<<0);//HSI AS SYSCLK
}

void gpio_init(void)
{
	JAI_APB2|=(1<<2);
	JAI_GPTR->CRL&=~(0xFFFF);
	JAI_GPTR->CRL|=(3<<0)|(3<<4)|(3<<8)|(3<<12);
}
void gpio_led_on(void)
{
	JAI_GPTR->ODR|=(1<<0);
	delay(1);
}
void gpio_led_off(void)
{
	JAI_GPTR->ODR&=~(1<<0);
	delay(1);
}

void gpio_binary_on(void)
{
	int i=0;
	while(i!=4)
	{
		JAI_GPTR->ODR|=(1<<i);
		delay(1);
		JAI_GPTR->ODR&=~(1<<i);
		delay(1);
	}
}
void gpio_binary_off(void)
{
	JAI_GPTR->ODR&=~((1<<0)|(1<<1)|(1<<2)|(1<<3));
}

void delay(int n)
{
	for(int i=0;i<n;i++)
	for(int i=0;i<100000;i++);
}