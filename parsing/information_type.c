#include "../includes/second_cube.h"

int is_resolution(char *str)
{
  if (str[0] == 'R')
      return (OK);
  return (KO);
}

int is_texture(char *str)
{
  if (str[0] == 'N' && str[1] == 'O')
    return (0);
  else if (str[0] == 'S' && str[1] == 'O')
    return (1);
  else if (str[0] == 'W' && str[1] == 'E')
    return (2);
  else if (str[0] == 'E' && str[1] == 'A')
    return (3);
  return (KO);
}

int is_rgb(char *str)
{
  if (str[0] == 'F' || str[0] == 'C')
      return (OK);
  return (KO);
}

int is_map(char *str)
{
  if (str[0] == '1')
      return (OK);
  return (KO);
}
