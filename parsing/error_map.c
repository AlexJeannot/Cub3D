#include "../includes/second_cube.h"

void check_map_error(void)
{
  int cmp_array;
  int cmp_str;

  check_top_and_bottom_map(0);
  check_top_and_bottom_map(win->my_map->height - 1);
  cmp_array = 1;
  while (cmp_array < win->my_map->height - 1)
  {
    cmp_str = 0;
    if (win->my_map->map[cmp_array][0] != '1')
      exit_game("frontiere ouest non ferme\n");
    if (win->my_map->map[cmp_array][win->my_map->width - 1] != '1')
      exit_game("frontiere est non ferme\n");
    while (win->my_map->map[cmp_array][cmp_str])
    {
      while (win->my_map->map[cmp_array][cmp_str] == ' ')
        cmp_str++;
      if (win->my_map->map[cmp_array][cmp_str] == 'N' || win->my_map->map[cmp_array][cmp_str] == 'S' || win->my_map->map[cmp_array][cmp_str] == 'E' || win->my_map->map[cmp_array][cmp_str] == 'W')
        cmp_str += set_player_position(cmp_str, cmp_array, win->my_map->map[cmp_array][cmp_str]);
      else if (win->my_map->map[cmp_array][cmp_str] != '0' && win->my_map->map[cmp_array][cmp_str] != '1' && win->my_map->map[cmp_array][cmp_str] != '2')
        exit_game("chiffre invalide dans corps de la map\n");
      cmp_str++;
    }
    cmp_array++;
  }
  if (config->player_position == 0)
    exit_game("pas de position\n");
}

void check_top_and_bottom_map(int limit)
{
  int cmp_str;

  cmp_str = 0;

  while (win->my_map->map[limit][cmp_str])
  {
    while (win->my_map->map[limit][cmp_str] == ' ')
      cmp_str++;
    if (win->my_map->map[limit][cmp_str] != '1')
    {
      if (limit == 0)
        exit_game("frontiere nord non ferme\n");
      else if (limit == win->my_map->height - 1)
        exit_game("frontiere sud non ferme\n");
    }
    cmp_str++;
  }
}
