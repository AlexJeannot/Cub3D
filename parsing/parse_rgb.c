#include "../includes/cub3D.h"

int create_rgb(int color_value, int rgb, char color, char type)
{
  if (check_error_rgb_value(color_value, color, type) != -1)
  {
    if (color == 'r')
      rgb = color_value;
    else if (color == 'g' || color == 'b')
      rgb = (rgb << 8) + color_value;
    return (rgb);
  }
  return (KO);
}

char set_color(int index)
{
  if (index == 0)
    return ('r');
  else if (index == 1)
    return ('g');
  else
    return ('b');
}

void set_color_value(char *str, char color, char type)
{
  if (str[0] >= '0' && str[0] <= '9')
  {
    if (type == 'F')
      win->floor_color = create_rgb(ft_atoi_cub(str), win->floor_color, color, type);
    else if (type == 'C')
      win->ceiling_color = create_rgb(ft_atoi_cub(str), win->floor_color, color, type);
  }
  else
    error_before_rgb_value(str[0], color, type);
}

void end_parse_rgb(char type, char last)
{
  if (type == 'F')
    config->rgb_f = 1;
  else if (type == 'C')
    config->rgb_c = 1;
  if (last != '\0' && type == 'F')
    exit_game("Error\nInvalid caracter after floor RGB\n");
  else if (last != '\0' && type == 'C')
    exit_game("Error\nInvalid caracter after ceiling RGB\n");
}

void parse_rgb(char *str)
{
  int cmp;
  int index;
  char color;

  cmp = 1;
  index = 0;
  while (str[cmp] == ' ')
    cmp++;
  while ((config->rgb_f != 1 && str[0] == 'F') || (config->rgb_c != 1 && str[0] == 'C'))
  {
    color = set_color(index);
    cmp += browse_space(&str[cmp]);
    set_color_value(&str[cmp], color, str[0]);
    cmp += browse_number(&str[cmp]);
    cmp += browse_space(&str[cmp]);
    if (index == 2)
      break ;
    cmp += check_coma_between_rgb(str[cmp], color, str[0]);
    index++;
  }
  end_parse_rgb(str[0], str[cmp]);
}
