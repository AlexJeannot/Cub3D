#include "../includes/second_cube.h"

int		end_game(int key)
{
  exit_game(NULL);
  return (1);
}

void exit_game(char *str)
{
  if (str)
    write(1, &str, ft_strlen(str));
  exit(1);
}
