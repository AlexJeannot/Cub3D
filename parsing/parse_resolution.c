#include "../includes/cub3D.h"

int is_resolution(char *str)
{
  if (str[0] == 'R')
  {
    if (config->resolution == 1)
      exit_game("Error\nResolution already defined\n");
    return (OK);
  }
  return (KO);
}

void parse_resolution(char *str)
{
  int cmp;

  cmp = 1;
  cmp += browse_space(&str[cmp]);
  if (str[cmp] >= '0' && str[cmp] <= '9')
  {
    win->width = ft_atoi_cub(&str[cmp]);
    cmp += browse_number(&str[cmp]);
    cmp += browse_space(&str[cmp]);
    if (str[cmp] < '0' || str[cmp] > '9')
      exit_game("Error\nInvalid caracter between resolution width and height\n");
    win->height = ft_atoi_cub(&str[cmp]);
    cmp += browse_number(&str[cmp]);
    cmp += browse_space(&str[cmp]);
    if (str[cmp] != '\0')
      exit_game("Error\nInvalid caracter after resolution height\n");
    config->resolution = 1;
  }
  else
    exit_game("Error\nInvalid caracter before resolution width\n");
}
