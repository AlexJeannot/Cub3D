/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:25:57 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/08 18:46:06 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	turn_left(void)
{
	double previous_dir_x;
	double previous_plane_x;

	previous_dir_x = g_player->dir_x;
	previous_plane_x = g_player->plane_x;
	g_player->dir_x = g_player->dir_x * cos(-g_player->rotate_speed)
	- g_player->dir_y * sin(-g_player->rotate_speed);
	g_player->dir_y = previous_dir_x * sin(-g_player->rotate_speed)
	+ g_player->dir_y * cos(-g_player->rotate_speed);
	g_player->plane_x = g_player->plane_x * cos(-g_player->rotate_speed)
	- g_player->plane_y * sin(-g_player->rotate_speed);
	g_player->plane_y = previous_plane_x * sin(-g_player->rotate_speed)
	+ g_player->plane_y * cos(-g_player->rotate_speed);
}

void	turn_right(void)
{
	double previous_dir_x;
	double previous_plane_x;

	previous_dir_x = g_player->dir_x;
	previous_plane_x = g_player->plane_x;
	g_player->dir_x = g_player->dir_x * cos(g_player->rotate_speed)
	- g_player->dir_y * sin(g_player->rotate_speed);
	g_player->dir_y = previous_dir_x * sin(g_player->rotate_speed)
	+ g_player->dir_y * cos(g_player->rotate_speed);
	g_player->plane_x = g_player->plane_x * cos(g_player->rotate_speed)
	- g_player->plane_y * sin(g_player->rotate_speed);
	g_player->plane_y = previous_plane_x * sin(g_player->rotate_speed)
	+ g_player->plane_y * cos(g_player->rotate_speed);
}
