#include "led_fun.h"

void led_on(void)
{
	gpio_led_on();
}

void led_off(void)
{
	gpio_led_off();
}
void led_pattern_on(void)
{
	gpio_binary_on();
}
void led_pattern_off(void)
{
	gpio_binary_off();
}