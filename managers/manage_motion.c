#include "../includes/second_cube.h"

void	move_forward(void)
{
	if (win->my_map->map[(int)win->player->pos_y][(int)(win->player->pos_x + win->player->dir_x * win->player->speed)] == '0')
    {
		win->player->pos_x += win->player->dir_x * win->player->speed;
    }
	if (win->my_map->map[(int)(win->player->pos_y + win->player->dir_y * win->player->speed)][(int)win->player->pos_x] == '0')
    {
		win->player->pos_y += win->player->dir_y * win->player->speed;
    }
}

void	move_backward(void)
{
	if (win->my_map->map[(int)win->player->pos_y][(int)(win->player->pos_x - win->player->dir_x * win->player->speed)] == '0')
  {
	 win->player->pos_x -= win->player->dir_x * win->player->speed;
  }
	if (win->my_map->map[(int)(win->player->pos_y - win->player->dir_y * win->player->speed)][(int)win->player->pos_x] == '0')
  {
		win->player->pos_y -= win->player->dir_y * win->player->speed;
    }
}

void	move_left(void)
{
	if (win->my_map->map[(int)win->player->pos_y][(int)(win->player->pos_x - win->player->plane_x * win->player->speed)] == '0')
  {
		win->player->pos_x -= win->player->plane_x * win->player->speed;
    }
	if (win->my_map->map[(int)(win->player->pos_y - win->player->plane_y * win->player->speed)][(int)win->player->pos_x] == '0')
  {
		win->player->pos_y -= win->player->plane_y * win->player->speed;
    }
}

void	move_right(void)
{
	if (win->my_map->map[(int)win->player->pos_y][(int)(win->player->pos_x + win->player->plane_x * win->player->speed)] == '0')
  {
		win->player->pos_x += win->player->plane_x * win->player->speed;
  }
	if (win->my_map->map[(int)(win->player->pos_y + win->player->plane_y * win->player->speed)][(int)win->player->pos_x] == '0')
  {
		win->player->pos_y += win->player->plane_y * win->player->speed;
  }
}
