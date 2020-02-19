/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_motion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:33:21 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/08 18:46:05 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	forward(void)
{
	if (g_map->map_array[(int)g_player->pos_y][(int)(g_player->pos_x
	+ g_player->dir_x * g_player->speed)] == '0')
		g_player->pos_x += g_player->dir_x * g_player->speed;
	if (g_map->map_array[(int)(g_player->pos_y + g_player->dir_y
	* g_player->speed)][(int)g_player->pos_x] == '0')
		g_player->pos_y += g_player->dir_y * g_player->speed;
}

void	backward(void)
{
	if (g_map->map_array[(int)g_player->pos_y][(int)(g_player->pos_x
	- g_player->dir_x * g_player->speed)] == '0')
		g_player->pos_x -= g_player->dir_x * g_player->speed;
	if (g_map->map_array[(int)(g_player->pos_y - g_player->dir_y
	* g_player->speed)][(int)g_player->pos_x] == '0')
		g_player->pos_y -= g_player->dir_y * g_player->speed;
}

void	left(void)
{
	if (g_map->map_array[(int)g_player->pos_y][(int)(g_player->pos_x
	- g_player->plane_x * g_player->speed)] == '0')
		g_player->pos_x -= g_player->plane_x * g_player->speed;
	if (g_map->map_array[(int)(g_player->pos_y - g_player->plane_y
	* g_player->speed)][(int)g_player->pos_x] == '0')
		g_player->pos_y -= g_player->plane_y * g_player->speed;
}

void	right(void)
{
	if (g_map->map_array[(int)g_player->pos_y][(int)(g_player->pos_x
	+ g_player->plane_x * g_player->speed)] == '0')
		g_player->pos_x += g_player->plane_x * g_player->speed;
	if (g_map->map_array[(int)(g_player->pos_y + g_player->plane_y
	* g_player->speed)][(int)g_player->pos_x] == '0')
		g_player->pos_y += g_player->plane_y * g_player->speed;
}
