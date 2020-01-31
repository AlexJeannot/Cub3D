#include "../includes/second_cube.h"

void	turn_left(void)
{
	double olddirx;
	double oldplanex;

	olddirx = win->player->dir_x;
	oldplanex = win->player->plane_x;
	win->player->dir_x = win->player->dir_x * cos(-win->player->rotate_speed) - win->player->dir_y * sin(-win->player->rotate_speed);
	win->player->dir_y = olddirx * sin(-win->player->rotate_speed) + win->player->dir_y * cos(-win->player->rotate_speed);
	win->player->plane_x = win->player->plane_x * cos(-win->player->rotate_speed) - win->player->plane_y * sin(-win->player->rotate_speed);
	win->player->plane_y = oldplanex * sin(-win->player->rotate_speed) + win->player->plane_y * cos(-win->player->rotate_speed);
}

void	turn_right(void)
{
	double olddirx;
	double oldplanex;

	olddirx = win->player->dir_x;
	oldplanex = win->player->plane_x;
	win->player->dir_x = win->player->dir_x * cos(win->player->rotate_speed) - win->player->dir_y * sin(win->player->rotate_speed);
	win->player->dir_y = olddirx * sin(win->player->rotate_speed) + win->player->dir_y * cos(win->player->rotate_speed);
	win->player->plane_x = win->player->plane_x * cos(win->player->rotate_speed) - win->player->plane_y * sin(win->player->rotate_speed);
	win->player->plane_y = oldplanex * sin(win->player->rotate_speed) + win->player->plane_y * cos(win->player->rotate_speed);
}
