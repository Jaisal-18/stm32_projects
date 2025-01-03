#include "cli.h"
#include "command.h"
#include "serial.h"
#include <string.h>
#include <stdio.h>
void cli_parse_and_execute(char *input)
{
		//serial_puts("\r\nfrom cli function1\r\n");//for debugging;
    char command[16] = {0};    // Main command
    char subcommand[16] = {0}; // Subcommand
		sscanf(input, "%s %s", command, subcommand);// Parse the input into command and subcommand
		if(strcasecmp(command,"led")==0)
		{
			if(strcasecmp(subcommand,"on")==0)
			{
				execute_cmd("on");
				serial_puts("\r\nLED IS ON\r\n");
			}
			else if(strcasecmp(subcommand,"off")==0)
			{
				execute_cmd("off");
				serial_puts("\r\nLED IS TURNED OFF\r\n");
			}
			else
			{
				serial_puts("\r\nUNKOWN SUBCOMMAND\r\n");
			}
		}
		else
		{
			serial_puts("\r\nUNKOWN COMMAND\r\n");
		}
}
