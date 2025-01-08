#include "shell.h"
#include <stdio.h>
#include <string.h>

struct shellcontent s_shell;

static bool shell_is_initialize(void)
{
    return s_shell.send_char != NULL;
}

void shell_send_char(char c)
{
    if (shell_is_initialize())
    {
        s_shell.send_char(c);
    }
}

void shell_echo(char c)
{
    if (c == '\n')
    {
        s_shell.send_char('\r');
    }
    s_shell.send_char(c);
}

void shell_reset_buffer(void)
{
    memset(s_shell.buff, 0, sizeof(s_shell.buff));
    s_shell.size = 0;
}

void shell_put_line(const char *str)
{
    for (const char *c = str; *c != '\0'; ++c)
    {
        shell_send_char(*c);
    }
}

void shell_boot(int (*send2_char_func)(char))
{
    s_shell.send_char = send2_char_func;
    shell_reset_buffer();
    shell_put_line(SHELLPROMT);
}

int send(char c)
{
    putchar(c);
    return 0;
}
