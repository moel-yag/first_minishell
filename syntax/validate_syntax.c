#include "../../includes/minishell.h"

bool validate_syntax(const char *input)
{
  int i = 0;
  int single_q = 0;
  int double_q = 0;

  while (input[i])
  {
    if (input[i] == '\'' && !double_q)
      single_q ^= 1;
    else if (input[i] == '"' && !single_q)
      double_q ^= 1;
    i++;
  }
  if (single_q || double_q)
  {
    printf("Error: Unclosed quotes\n");
    return (false);
  }
  i = 0;
  while (input[i])
  {
    if (input[i] == '>' || input[i] == '<')
    {
      if (!input[i + 1] || input[i + 1] == '|' || input[i + 1] == '>' || input[i + 1] == '<')
      {
        printf("Error: Invalid redirection\n");
        return false;
      }
    }
    if (input[i] == '|')
    {
      if (i == 0 || !input[i + 1] || input[i + 1] == '|')
      {
        printf("Error: Invalid pipe\n");
        return false;
      }
    }
    i++;
  }
  return true;
}