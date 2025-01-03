#include "serial.h"
typedef struct
{
	char * cmd;
	void (*handler)(void);
}command;
void execute_cmd(char * name);

