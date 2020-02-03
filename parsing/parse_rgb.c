#include "../includes/second_cube.h"

int is_rgb(char *str)
{
  if (str[0] == 'F' || str[0] == 'C')
  {
    if (str[0] == 'F' && config->rgb_f == 1)
      exit_game("rgb floor already set\n");
    else if (str[0] == 'C' && config->rgb_c == 1)
      exit_game("rgb ceiling already set\n");
    return (OK);
  }
  return (KO);
}

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
    if (index == 0)
      color = 'r';
    else if (index == 1)
      color = 'g';
    else if (index == 2)
      color = 'b';
    while (str[cmp] == ' ')
      cmp++;
    if (str[cmp] >= '0' && str[cmp] <= '9')
    {
      if (str[0] == 'F')
      {
        win->floor_color = create_rgb(ft_atoi_cub(&str[cmp]), win->floor_color, color, str[0]);
      }
      else if (str[0] == 'C')
      {
        win->ceiling_color = create_rgb(ft_atoi_cub(&str[cmp]), win->floor_color, color, str[0]);
      }
    }
    else
      error_before_rgb_value(str[cmp], color, str[0]);
    while (str[cmp] >= '0' && str[cmp] <= '9')
      cmp++;
    while (str[cmp] == ' ')
      cmp++;
    if (index == 2)
      break ;
    cmp += check_coma_between_rgb(str[cmp], color, str[0]);
    index++;
  }
  if (str[0] == 'F')
    config->rgb_f = 1;
  if (str[0] == 'C')
    config->rgb_c = 1;
  if (str[cmp] != '\0')
    exit_game("caractere invalide post rgb\n");
}
