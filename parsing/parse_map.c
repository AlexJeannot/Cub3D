#include "../includes/second_cube.h"

int is_map(char *str)
{
  int cmp;

  cmp = 0;
  while (str[cmp] == ' ')
    cmp++;
  if (config->map == 1)
  {
    if (str[cmp] == '1')
      return (OK);
    else
      exit_game("ligne de map non conforme");
    return (KO);
  }
  else
  {
    if (str[cmp] == '1')
      return (OK);
    else
      return (KO);
  }
}

void parse_map(char *str)
{
  int len;

  len = ft_strlen(str);
  if (config->map == 0)
  {
    check_all_config_elem_before_map();
    win->my_map->map_str = ft_strjoin_cub(win->my_map->map_str, str, ft_strlen(win->my_map->map_str), ft_strlen(str));
    win->my_map->width = ft_strlen_without_space(str);
    config->map = 1;
  }
  else
    win->my_map->map_str = ft_strjoin_cub(win->my_map->map_str, str, ft_strlen(win->my_map->map_str), ft_strlen(str));
  win->my_map->height++;
}

void map_into_array(void)
{
  int cmp_array;
  int cmp_str;
  int cmp_global;
  char **map_array;
  char *map_str;
  cmp_array = 0;
  cmp_global = 0;
  map_array = malloc(sizeof(char *) * win->my_map->height);
  while (cmp_array < win->my_map->height)
  {
    cmp_str = 0;
    map_str = malloc(sizeof(char) * (win->my_map->width + 1));
    while (cmp_str < win->my_map->width)
    {
      while (win->my_map->map_str[cmp_global] == ' ' || win->my_map->map_str[cmp_global] == '\n')
        cmp_global++;
      map_str[cmp_str] = win->my_map->map_str[cmp_global];
      cmp_str++;
      cmp_global++;
    }
    map_str[cmp_str] = '\0';
    map_array[cmp_array] = map_str;
    cmp_array++;
    cmp_global++;
  }
  win->my_map->map = map_array;
  free(win->my_map->map_str);
}
