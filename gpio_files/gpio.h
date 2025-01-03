typedef struct
{
	unsigned int CR;//0x00
	unsigned int CFGR;//0x04
}JAISAL_RCC;

typedef struct 
{
	unsigned int CRL;//offset 0x00
	unsigned int CRH;//offset 0x04
	unsigned int IDR;//offset 0x08
	unsigned int ODR;//odr offset 0x0C
}JAISAL_GPIO;

#define GPIO_BASE ((unsigned int)0x40010800)//gpioa_base
#define RCC_BASE  ((unsigned int)0x40021000)//rcc_base
	
#define JAI_RPTR  ((volatile JAISAL_RCC *)RCC_BASE)
#define JAI_GPTR  ((volatile JAISAL_GPIO *)GPIO_BASE)
#define JAI_APB2 (*(volatile unsigned int*)(0x40021018))
	
void sys_clk_8(void);
void gpio_init(void);
void delay(int n);
void gpio_binary_on(void);
void gpio_binary_off(void);
void gpio_led_on(void);
void gpio_led_off(void);