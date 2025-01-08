#include<stdio.h>
#include <stdbool.h>
#include <stddef.h>

#define SHELLPROMT "jaisal>>"

struct shellcontent
{
    int(*send_char)(char c);
    ssize_t size;
    char buff[256];
};

extern struct shellcontent s_shell;

static bool shell_is_initialize(void);
void shell_send_char(char c);
void shell_echo(char c);
void shell_reset_buffer(void);
void shell_put_line(const char *str);
void shell_boot(int (*send2_char_func)(char));
int send(char c);