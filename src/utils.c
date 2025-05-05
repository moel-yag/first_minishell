#include "../includes/minishell.h"

char    *ft_getline(char *str, size_t *len, int fd)
{
    char    *buffer;
    size_t  bytes_read;
    size_t  total_bytes = 0;

    buffer = malloc(1024);
    if (!buffer)
        return (NULL);
    while ((bytes_read = read(fd, buffer + total_bytes, 1024 - total_bytes)) > 0)
    {
        total_bytes += bytes_read;
        if (buffer[total_bytes - 1] == '\n')
            break;
        if (total_bytes >= 1024 - 1)
            break;
    }
    if (bytes_read <= 0 && total_bytes == 0)
    {
        free(buffer);
        return (NULL);
    }
    buffer[total_bytes] = '\0';
    str = realloc(str, total_bytes + 1);
    if (!str)
    {
        free(buffer);
        return (NULL);
    }
    strcpy(str, buffer);
    free(buffer);
    *len = total_bytes;
    return (str);
}


// To detect Emty input
bool    is_blank_line(const char *s)
{
    size_t  i = 0;
    if (!s)
        return (true);
    while (s[i])
    {
        if (!isspace((unsigned char)s[i]))
            return (false);
        i++;
    }
    return (true);
}

void    print_syntax_error(const char *msg)
{
    perror("minishell: syntax error!\n");
    extern int g_exit_status;
    g_exit_status = 2;
}
