#include "command.h"
#include "led_fun.h"
#include <string.h>

command comd_list[]={{"on",led_on},{"off",led_off}};//structure variable array;

static int n=sizeof(comd_list)/sizeof(comd_list[0]);

void execute_cmd(char *input)
{
    for (int i=0;i<n;i++) 
	{
        if (strcmp(input,comd_list[i].cmd)==0)
					{
            comd_list[i].handler();  // Call the corresponding handler
          }
    }
}