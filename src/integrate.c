#include "../includes/minishell.h"

static void remove_newline(char *line) {
    size_t i = 0;

    while (line[i]) { // Iterate through the string
        if (line[i] == '\n') { // Check for newline character
            line[i] = '\0';    // Replace it with null terminator
            break;             // Stop once newline is replaced
        }
        i++;
    }
}

void shell_loop() {
    char *input = NULL;
    size_t len = 0;
    t_command *commands = NULL;

    while (1) {
        printf("minishell> ");
        input = ft_getline(input, &len, stdin);

        // Remove trailing newline
        remove_newline(input);
        if (strlen(input) == 0) {
            free(input);
            continue; // Skip empty input
        }

        // Parse input and add to linked list
        t_command *cmd = parse_input(input);
        if (cmd)
            add_command(&commands, cmd);

        // Exit condition
        if (strcmp(input, "exit") == 0)
            break;
    }

    free(input);
    free_commands(commands);
}