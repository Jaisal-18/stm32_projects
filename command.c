#include "command.h"
#include <string.h>
void led_on(void)
{
	gpio_led_on();
	//gpio_binary_on();
}

void led_off(void)
{
	gpio_led_off();
	//gpio_binary_off();
}
command comd_list[] = {
    {"on", led_on},
    {"off", led_off}
};

void execute_command( char *input)
{
    for (int i = 0; i < 2; i++) 
	{
        if (strcmp(input, comd_list[i].cmd) == 0)
					{
            comd_list[i].handler();  // Call the corresponding handler
            return;
        }
    }
}
