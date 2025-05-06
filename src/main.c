#include "../includes/minishell.h"

void  multi_to_single_space(char **av, char *res, int ac)
{
  int (i), (j), (k);

  i = 1;
  k = 0;
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
}

int main(int ac, char **av)
{
  if (ac < 2)
  {
    printf("\n");
    return 0;
  }
  char *res = malloc(1000);
  if (res == NULL)
  {
    perror("malloc");
    return 1;
  }
  multi_to_single_space(av, res, ac);
  printf("%s\n", res);
  free(res);

  return 0;
}
