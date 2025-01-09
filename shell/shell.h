#include <stddef.h>
#include <stdio.h>
#include <string.h>

// Macro definitions
#define SHELLPROMT "jaisal>>"

// Typedef for shell command structure
typedef struct shellcommand
{
    char *command;
    int (*handler)(int argc, char *argv[]);
    char *help;
}scommand;

// Macro for looping through commands
#define test_loop(cmd) \
    for (scommand *cmd = command_array; cmd < &command_array[casize]; ++cmd)

// Shell content structure
struct shellcontent
{
    int (*send_char)(char c);
    ssize_t size;
    char buff[256];
};

// Extern declarations for global variables
extern struct shellcontent s_shell;
extern scommand command_array[];
extern int casize;

// Function declarations
void shell_put_line(const char *str);
void shell_boot(int (*send2_char_func)(char));
void shell_process_cmd(void);
void shell_reset_buffer(void);
void shell_echo(char c);
int display(int argc, char *argv[]);
int shell_exit(int argc, char *argv[]);
int send(char c);