#include "gpio.h"
#include "serial.h"
typedef struct
{
	char * cmd;
	void (*handler)(void);
}command;
void led_on(void);
void led_off(void);
void execute_cmd(char * name);

