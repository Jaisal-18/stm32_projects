#include "serial.h"
void sys_clk_8(void)
{
	JAI_RPTR->CR|=(1<<0);//HSI ON
	while(!(JAI_RPTR->CR & (1<<1)));//WAITING FOR HSI TO READY;
	JAI_RPTR->CFGR&=~(3<<0);//HSI AS SYSCLK
}
void UART_config(void)
{
	JAI_APB2|=(1<<14);//enable uart clock;
	JAI_UPTR->CR1&=~(1<<12);//8 BIT DATA
	JAI_UPTR->CR2&=~(3<<12);//1 STOP BIT
	JAI_UPTR->BRR=0X341;//BAUD RATE IN HEXA// MANTISSA &
	JAI_UPTR->CR1|=(1<<3)|(1<<2);//ENABLE TX & RX 
	JAI_UPTR->CR1|=(1<<13);//ENABLE UART
}
void gpio_config(void)
{
	JAI_APB2|=(1<<2);//enable gpio clock
	JAI_GPTR->CRH&=~(0XFF<<4);
	JAI_GPTR->CRH|=(11<<4);//PIN 9 IN ALTERNATIVE OUTPUT MODE 50HZ ;(TRANSMISSION)
	JAI_GPTR->CRH|=(4<<8);//PIN 10 IN FLOAT INPUT MODE;(RECEIVE)
}
void send_data(unsigned char data)//PUTC
{
	while(!(JAI_UPTR->SR & (1<<7)));//WAITING FOR BUFFER TO BE EMPTY
	JAI_UPTR->DR=data;
}
unsigned char receive_data(void)//GETC
{
	while(!(JAI_UPTR->SR & (1<<5)));//WAITING FOR RECEIVE BUFFER TO BE EMPTY
	return JAI_UPTR->DR;
}
