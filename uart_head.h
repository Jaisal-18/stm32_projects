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

#define JAI_UPTR  ((volatile JAISAL_UART *)UART_BASE)
#define JAI_GPTR  ((volatile JAISAL_GPIO *)GPIO_BASE)

#define JAI_APB2 (*(volatile unsigned int*)(0x40021018))
