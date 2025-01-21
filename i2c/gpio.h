
//RCC APB
#define JAI_APB2 (*(volatile unsigned int*)(0x40021018))//rcc_apb2enr(gpiob)
#define JAI_APB1 (*(volatile unsigned int*)(0x4002101C))//rcc_apb1enr(i2c)

//GPIOB;
typedef struct
{
	unsigned  int CRL;
}GPIO;

#define GPIOB_BASE ((unsigned int)0x40010C00)
#define JAIGPIOB ((volatile GPIO *)GPIOB_BASE)
	
//I2c
typedef struct
{
	volatile unsigned short int CR1; // to ensure
	volatile unsigned short int R1;
	volatile unsigned short int CR2;
	volatile unsigned short int R2;
	volatile unsigned short int OAR1;
	volatile unsigned short int R3;
	volatile unsigned short int OAR2;
	volatile unsigned short int R4;
	volatile unsigned short int DR;
	volatile unsigned short int R5;
	volatile unsigned short int SR1;
	volatile unsigned short int R6;
	volatile unsigned short int SR2;
	volatile unsigned short int R7;
	volatile unsigned short int CCR;
	volatile unsigned short int R8;
	volatile unsigned short int TRISE;
	volatile unsigned short int R9;
}I2C1;
#define I2C1_BASE ((unsigned int)0x40005400)
#define JAI_I2C ((I2C1 *)I2C1_BASE)
	
//functions
void I2C_init(void);
void I2C_start(void);
void I2C_stop(void);
void I2C_write(unsigned char data);
unsigned char I2C_read(void);