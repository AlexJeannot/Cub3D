#include "../includes/cub3D.h"

int is_map(char *str)
{
  int cmp;

  cmp = 0;
  cmp += browse_space(&str[cmp]);
  if (config->map == 1)
  {
    if (str[cmp] == '1')
      return (OK);
    else
      exit_game("Error\nMap line beginning by a invalid caracter\n");
    return (KO);
  }
  else
    if (str[cmp] == '1')
      return (OK);
  return (KO);
}

void parse_map(char *str)
{
  int len;

  len = ft_strlen(str);
  if (config->map == 0)
  {
    check_all_config_elem_before_map();
    map->map_str = ft_strjoin_cub(map->map_str, str, ft_strlen(map->map_str), ft_strlen(str));
    map->width = ft_strlen_without_space(str);
    config->map = 1;
  }
  else
    map->map_str = ft_strjoin_cub(map->map_str, str, ft_strlen(map->map_str), ft_strlen(str));
  map->height++;
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
  if (!(map_array = malloc(sizeof(char *) * map->height)))
    exit_game("Error\nMemory allocation error\n");
  while (cmp_array < map->height)
  {
    cmp_str = 0;
    if (!(map_str = malloc(sizeof(char) * (map->width + 1))))
      exit_game("Error\nMemory allocation error\n");
    while (cmp_str < map->width)
    {
      while (map->map_str[cmp_global] == ' ' || map->map_str[cmp_global] == '\n')
        cmp_global++;
      map_str[cmp_str] = map->map_str[cmp_global];
      cmp_str++;
      cmp_global++;
    }
    map_str[cmp_str] = '\0';
    map_array[cmp_array] = map_str;
    cmp_array++;
    cmp_global++;
  }
  map->map_array = map_array;
  free(map->map_str);
}
