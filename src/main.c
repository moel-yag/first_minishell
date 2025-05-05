#include "../includes/minishell.h"

int main(int ac, char **av)
{
  if (ac < 2)
  {
    printf("\n");
    return 0;
  }
  int i, j, k;
  char *res = malloc(1000);
  if (res == NULL)
  {
    perror("malloc");
    return 1;
  }

  k = 0;
  i = 1;
  while (i < ac)
  {
    j = 0;
    while (av[i][j])
    {
      while (av[i][j] && av[i][j] == ' ')
        j++;
      while (av[i][j] && av[i][j] != ' ')
        res[k++] = av[i][j++];
      while (av[i][j] && av[i][j] == ' ')
        j++;
      if (av[i][j] != '\0')
        res[k++] = ' ';
    }
    if (i < ac - 1)
      res[k++] = ' ';
    i++;
  }
  res[k] = '\0';

  printf("%s\n", res);
  free(res);

  return 0;
}