#include "../../includes/cub3D.h"

void	move_forward(void)
{
	if (map->map_array[(int)player->pos_y][(int)(player->pos_x + player->dir_x * player->speed)] == '0')
		player->pos_x += player->dir_x * player->speed;
	if (map->map_array[(int)(player->pos_y + player->dir_y * player->speed)][(int)player->pos_x] == '0')
		player->pos_y += player->dir_y * player->speed;
}

void	move_backward(void)
{
	if (map->map_array[(int)player->pos_y][(int)(player->pos_x - player->dir_x * player->speed)] == '0')
		player->pos_x -= player->dir_x * player->speed;
	if (map->map_array[(int)(player->pos_y - player->dir_y * player->speed)][(int)player->pos_x] == '0')
		player->pos_y -= player->dir_y * player->speed;
}

void	move_left(void)
{
	if (map->map_array[(int)player->pos_y][(int)(player->pos_x - player->plane_x * player->speed)] == '0')
		player->pos_x -= player->plane_x * player->speed;
	if (map->map_array[(int)(player->pos_y - player->plane_y * player->speed)][(int)player->pos_x] == '0')
		player->pos_y -= player->plane_y * player->speed;
}

void	move_right(void)
{
	if (map->map_array[(int)player->pos_y][(int)(player->pos_x + player->plane_x * player->speed)] == '0')
		player->pos_x += player->plane_x * player->speed;
	if (map->map_array[(int)(player->pos_y + player->plane_y * player->speed)][(int)player->pos_x] == '0')
		player->pos_y += player->plane_y * player->speed;
}
