typedef struct
{
	unsigned int CR;//0x00
	unsigned int CFGR;//0x04
}JAISAL_RCC;

typedef struct
{
	unsigned short int SR;//0x00
	unsigned short int R0;//0x02
	unsigned short int DR;//0x04
	unsigned short int R1;//0x06
	unsigned short int BRR;//0x08
	unsigned short int R2;//0x0A
	unsigned short int CR1;//0x0C
	unsigned short int R3;//0x0E
	unsigned short int CR2;//0x10
	unsigned short int R4;//0x12
	unsigned short int CR3;//0x14
	unsigned short int R5;//0x16
	unsigned short int GTBR;//0x18
	unsigned short int R6;//0x1A
}JAISAL_UART;

typedef struct 
{
	unsigned int CRL;//offset 0x00
	unsigned int CRH;//offset 0x04
	unsigned int IDR;//offset 0x08
	unsigned int ODR;//odr offset 0x0C
}JAISAL_GPIO;

#define UART_BASE ((unsigned int)0x40013800)// usart1_base
#define GPIO_BASE ((unsigned int)0x40010800)//gpioa_base
#define RCC_BASE  ((unsigned int)0x40021000)//rcc_base

#define JAI_RPTR  ((volatile JAISAL_RCC *)RCC_BASE)
#define JAI_UPTR  ((volatile JAISAL_UART *)UART_BASE)
#define JAI_GPTR  ((volatile JAISAL_GPIO *)GPIO_BASE)

#define JAI_APB2 (*(volatile unsigned int*)(0x40021018))

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
void led_config()
{
	JAI_APB2|=(1<<2);
	JAI_GPTR->CRL&=~(0xFFFF);
	JAI_GPTR->CRL|=(3<<0)|(3<<4)|(3<<8)|(3<<12);
}
void delay(int n)
{
	for(int i=0;i<n;i++)
	for(int i=0;i<100000;i++);
}
