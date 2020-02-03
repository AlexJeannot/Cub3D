#include "../includes/second_cube.h"

int set_player_position(int x, int y, char orientation)
{
  if (config->player_position == 1)
  {
    exit_game("Redefinition de player position\n");
    return (KO);
  }
  win->player->pos_x = x - 1;
  win->player->pos_y = y - 1;
  if (orientation == 'N' || orientation == 'S')
    set_player_dir_n_or_s(orientation);
  else if (orientation == 'E' || orientation == 'W')
    set_player_dir_e_or_w(orientation);
  win->my_map->map[y][x] = '0';
  config->player_position = 1;
  return (OK);
}

void set_player_dir_n_or_s(char orientation)
{
  if (orientation == 'N')
  {
    win->player->dir_x = 0.0;
    win->player->dir_y = -1.0;
    win->player->plane_x = 0.66;
    win->player->plane_y = 0.0;
  }
  else if (orientation == 'S')
  {
    win->player->dir_x = 0.0;
    win->player->dir_y = 1.0;
    win->player->plane_x = -0.66;
    win->player->plane_y = 0.0;
  }
}

void set_player_dir_e_or_w(char orientation)
{
  if (orientation == 'E')
  {
    win->player->dir_x = 1.0;
    win->player->dir_y = 0.0;
    win->player->plane_x = 0.0;
    win->player->plane_y = 0.66;
  }
  else if (orientation == 'W')
  {
    win->player->dir_x = -1.0;
    win->player->dir_y = 0.0;
    win->player->plane_x = 0.0;
    win->player->plane_y = -0.66;
  }
}
