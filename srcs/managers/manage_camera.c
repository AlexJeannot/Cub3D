#include "../../includes/cub3D.h"

void	turn_left(void)
{
	double previous_dir_x;
	double previous_plane_x;

	previous_dir_x = player->dir_x;
	previous_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(-player->rotate_speed) - player->dir_y * sin(-player->rotate_speed);
	player->dir_y = previous_dir_x * sin(-player->rotate_speed) + player->dir_y * cos(-player->rotate_speed);
	player->plane_x = player->plane_x * cos(-player->rotate_speed) - player->plane_y * sin(-player->rotate_speed);
	player->plane_y = previous_plane_x * sin(-player->rotate_speed) + player->plane_y * cos(-player->rotate_speed);
}

void	turn_right(void)
{
	double previous_dir_x;
	double previous_plane_x;

	previous_dir_x = player->dir_x;
	previous_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(player->rotate_speed) - player->dir_y * sin(player->rotate_speed);
	player->dir_y = previous_dir_x * sin(player->rotate_speed) + player->dir_y * cos(player->rotate_speed);
	player->plane_x = player->plane_x * cos(player->rotate_speed) - player->plane_y * sin(player->rotate_speed);
	player->plane_y = previous_plane_x * sin(player->rotate_speed) + player->plane_y * cos(player->rotate_speed);
}
