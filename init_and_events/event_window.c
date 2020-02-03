#include "../includes/second_cube.h"

int		end_game(void)
{
  exit_game(NULL);
  return (1);
}

void exit_game(char *str)
{
  int cmp;

  cmp = 0;
  if (str)
  {
      while (str[cmp])
      {
        write(1, &str[cmp], 1);
        cmp++;
      }
  }
  exit(1);
}
