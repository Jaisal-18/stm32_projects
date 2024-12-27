#include "cli.h"
#include "gpio.h"
#include "serial.h"
int main()
{
	sys_clk_8();
	serial_init();
	gpio_init();
	cln_fun();
}