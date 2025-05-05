#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

// Define the maximum length for command input
#define MAX_CMD_LENGTH 1024

// Structure for linked list nodes to store commands
typedef struct s_command {
    char *cmd;
    char **args;
    struct s_command *next;
} t_command;

// Function prototypes
bool    is_blank_line(const char *s);
void    print_syntax_error(const char *msg);

#endif // MINISHELL_H