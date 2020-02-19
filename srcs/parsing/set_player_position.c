/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:36:14 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/10 15:31:21 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		set_player_position(int x, int y, char orientation)
{
	if (g_config->player_position == 1)
	{
		exit_game("Error\nPlayer position already defined\n");
		return (KO);
	}
	g_player->pos_x = x + 0.5;
	g_player->pos_y = y + 0.5;
	if (orientation == 'N' || orientation == 'S')
		set_player_dir_n_or_s(orientation);
	else if (orientation == 'E' || orientation == 'W')
		set_player_dir_e_or_w(orientation);
	g_map->map_array[y][x] = '0';
	g_config->player_position = 1;
	return (OK);
}

void	set_player_dir_n_or_s(char orientation)
{
	if (orientation == 'N')
	{
		g_player->dir_x = 0.0;
		g_player->dir_y = -1.0;
		g_player->plane_x = 0.66;
		g_player->plane_y = 0.0;
	}
	else if (orientation == 'S')
	{
		g_player->dir_x = 0.0;
		g_player->dir_y = 1.0;
		g_player->plane_x = -0.66;
		g_player->plane_y = 0.0;
	}
}

void	set_player_dir_e_or_w(char orientation)
{
	if (orientation == 'E')
	{
		g_player->dir_x = 1.0;
		g_player->dir_y = 0.0;
		g_player->plane_x = 0.0;
		g_player->plane_y = 0.66;
	}
	else if (orientation == 'W')
	{
		g_player->dir_x = -1.0;
		g_player->dir_y = 0.0;
		g_player->plane_x = 0.0;
		g_player->plane_y = -0.66;
	}
}
