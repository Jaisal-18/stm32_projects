#include "console.h"
#include "gpio.h"
#include "serial.h"
int main()
{
	sys_clk_8();
	serial_init();
	gpio_init();
	while(1)
	{
		console_read_input();
	}
}