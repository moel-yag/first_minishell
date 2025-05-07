#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

// Define the maximum length for command input
#define MAX_CMD_LENGTH 1024

// Structure for linked list nodes to store commands
typedef struct s_command
{
    char *cmd;
    char **args;
    struct s_command *next;
} t_command;

// Structure for lexer tokens
typedef struct s_lexer
{
    char *value;           // Token value
    char type;             // Token type (e.g., 'P' for pipe, 'I' for input redirection, etc.)
    bool in_quotes;        // Whether the token is inside quotes
    struct s_lexer *next;  // Pointer to the next token
    struct s_lexer *prev;  // Pointer to the previous token
} t_lexer;

// Structure for environment variables
typedef struct s_env
{
    int exit_status; // Stores the exit status of the last command
} t_env;

extern t_env *g_env;

// Function prototypes
bool is_blank_line(const char *s);
void print_syntax_error(const char *msg);
bool validate_syntax(const char *input);
char **ft_split(const char *str, char delimiter);

// Syntax validation functions
int pipe_syntax(t_lexer *lex);
int files_syntax(t_lexer *lex);
int check_syntax(t_lexer *lex);

#endif // MINISHELL_H
