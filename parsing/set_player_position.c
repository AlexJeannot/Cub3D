#include "../includes/cub3D.h"

int set_player_position(int x, int y, char orientation)
{
  if (config->player_position == 1)
  {
    exit_game("Error\nPlayer position already defined\n");
    return (KO);
  }
  player->pos_x = x - 1;
  player->pos_y = y - 1;
  if (orientation == 'N' || orientation == 'S')
    set_player_dir_n_or_s(orientation);
  else if (orientation == 'E' || orientation == 'W')
    set_player_dir_e_or_w(orientation);
  map->map_array[y][x] = '0';
  config->player_position = 1;
  return (OK);
}

void set_player_dir_n_or_s(char orientation)
{
  if (orientation == 'N')
  {
    player->dir_x = 0.0;
    player->dir_y = -1.0;
    player->plane_x = 0.66;
    player->plane_y = 0.0;
  }
  else if (orientation == 'S')
  {
    player->dir_x = 0.0;
    player->dir_y = 1.0;
    player->plane_x = -0.66;
    player->plane_y = 0.0;
  }
}

void set_player_dir_e_or_w(char orientation)
{
  if (orientation == 'E')
  {
    player->dir_x = 1.0;
    player->dir_y = 0.0;
    player->plane_x = 0.0;
    player->plane_y = 0.66;
  }
  else if (orientation == 'W')
  {
    player->dir_x = -1.0;
    player->dir_y = 0.0;
    player->plane_x = 0.0;
    player->plane_y = -0.66;
  }
}
