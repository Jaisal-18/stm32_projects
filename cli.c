#include "gpio.h"
#include "serial.h"
void cln_fun(void)
{
unsigned char data;
	while(1)
	{
		data=serial_getc();
		gpio_led_on();
		serial_putc(data);
		gpio_led_off();
	}
}