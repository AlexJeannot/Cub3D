#include "../includes/second_cube.h"

int is_resolution(char *str)
{
  int cmp;

  cmp = 1;
  if (str[0] == 'R')
  {
    while (str[cmp] == ' ')
      cmp++;
    if (str[cmp] >= '0' && str[cmp] <= '9')
      return (OK);
  }
  return (KO);
}

int is_texture(char *str)
{
  int cmp;

  cmp = 2;
  if ((str[0] == 'N' && str[1] == 'O') || (str[0] == 'S' && str[1] == 'O')
  || (str[0] == 'W' && str[1] == 'E') || (str[0] == 'E' && str[1] == 'A'))
  {
    while (str[cmp] == ' ')
      cmp++;
    if (str[cmp] == '.')
      return (OK);
  }
  return (KO);
}

int is_rgb(char *str)
{
  int cmp;

  cmp = 1;
  if (str[0] == 'F' || str[0] == 'C')
  {
    while (str[cmp] == ' ')
      cmp++;
    if (str[cmp] == '.')
      return (OK);
  }
  return (KO);
}

int is_map(char *str)
{
  int cmp;

  cmp = 1;
  if (str[0] == 'F' || str[0] == 'C')
  {
    while (str[cmp] == ' ')
      cmp++;
    if (str[cmp] >= '0' && str[cmp] <= '9')
      return (OK);
  }
  return (KO);
}
