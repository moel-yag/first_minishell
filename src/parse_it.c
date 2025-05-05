#include "../includes/minishell.h"

t_command *parse_input(char *input)
{
    char **tokens = ft_split(input, ' ');
    if (!tokens)
        return NULL;
    t_command *cmd = create_command(tokens[0], tokens + 1);
    return cmd;
}
