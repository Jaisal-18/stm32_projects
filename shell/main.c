#include "shell.h"

int send(char c)
{
    putchar(c);
    return 0;
}

int main(void)
{
    shell_boot(send);
    s_shell.send_char = send;

    char c;
    while (1)
    {
        c = getchar();
        if (c == EOF)
        {
            break;
        }

        if (s_shell.size < (sizeof(s_shell.buff) - 1))
        {
                if(c == '\n');
                else
                        s_shell.buff[s_shell.size++] = c;
        }
        shell_echo(c);

        if (c == '\n')
        {
            s_shell.buff[s_shell.size] = '\0';
            shell_process_cmd();
            shell_reset_buffer();
            shell_put_line(SHELLPROMT);
        }
    }

}