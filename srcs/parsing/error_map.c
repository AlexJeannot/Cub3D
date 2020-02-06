#include "../../includes/cub3D.h"

void check_map_error(void)
{
  int cmp_array;
  int cmp_str;

  check_top_and_bottom_map(0);
  check_top_and_bottom_map(map->height - 1);
  cmp_array = 1;
  while (cmp_array < map->height - 1)
  {
    cmp_str = 0;
    if (map->map_array[cmp_array][0] != '1')
      exit_game("Error\nMap is not closed on the west side\n");
    if (map->map_array[cmp_array][map->width - 1] != '1')
      exit_game("Error\nMap is not closed on the east side\n");
    while (map->map_array[cmp_array][cmp_str])
    {
      while (map->map_array[cmp_array][cmp_str] == ' ')
        cmp_str++;
      if (map->map_array[cmp_array][cmp_str] == 'N' || map->map_array[cmp_array][cmp_str] == 'S' || map->map_array[cmp_array][cmp_str] == 'E' || map->map_array[cmp_array][cmp_str] == 'W')
        cmp_str += set_player_position(cmp_str, cmp_array, map->map_array[cmp_array][cmp_str]);
      else if (map->map_array[cmp_array][cmp_str] != '0' && map->map_array[cmp_array][cmp_str] != '1' && map->map_array[cmp_array][cmp_str] != '2')
        exit_game("Error\nInvalid caracter in the map\n");
      cmp_str++;
    }
    cmp_array++;
  }
  if (config->player_position == 0)
    exit_game("Error\nNo player position defined\n");
}

void check_top_and_bottom_map(int array)
{
  int cmp_str;

  cmp_str = 0;
  while (map->map_array[array][cmp_str])
  {
    while (map->map_array[array][cmp_str] == ' ')
      cmp_str++;
    if (map->map_array[array][cmp_str] != '1')
    {
      if (array == 0)
        exit_game("Error\nMap is not closed on the north side\n");
      else if (array == map->height - 1)
        exit_game("Error\nMap is not closed on the south side\n");
    }
    cmp_str++;
  }
}
