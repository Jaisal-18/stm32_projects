#include "shell.h"

// Global variables
struct shellcontent s_shell;
scommand command_array[] = {{"led", display, "this is led command"},{"exit",shell_exit,"a exit function"}};
int casize = sizeof(command_array)/sizeof(command_array[0]);

// Internal helper functions
static bool shell_is_initialize(void)
{
    return s_shell.send_char != NULL;
}

static void shell_send_char(char c)
{
    if (shell_is_initialize())
    {
        s_shell.send_char(c);
    }
}

// Shell functionality
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

// Command handler
int display(int argc, char *argv[])
{
    shell_put_line("led function\n");
    return 0;
}
int shell_exit(int argc,char *argv[])
{
        shell_put_line("exit command\n");
        return 0;
}

void shell_process_cmd(void)
{
    if (s_shell.size == 0)
    {
        return;
    }

    char *argv[256];
    int size = 0;
    char *token = strtok(s_shell.buff, " ");
    while (token != NULL)
    {
        argv[size++] = token;
        token = strtok(NULL, " ");
    }
    if (size > 0)
    {
        scommand *command = NULL;
        test_loop(cmd)
        {
            if (strcmp(cmd->command, argv[0]) == 0)
            {
                command = cmd;
                break;
            }
        }

        if (command)
        {
            command->handler(size, argv);
        }
        else
        {
            shell_put_line("unkown\n");
        }
    }
}