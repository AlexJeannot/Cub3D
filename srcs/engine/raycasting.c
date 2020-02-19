/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:02:56 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/10 16:49:36 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calcul_wall_distance(void)
{
	if (g_ray->dir_x < 0)
	{
		g_ray->step_x = -1;
		g_ray->side_dist_x = (g_player->pos_x - g_ray->map_x)
		* g_ray->delta_dist_x;
	}
	else
	{
		g_ray->step_x = 1;
		g_ray->side_dist_x = (g_ray->map_x + 1.0 - g_player->pos_x)
		* g_ray->delta_dist_x;
	}
	if (g_ray->dir_y < 0)
	{
		g_ray->step_y = -1;
		g_ray->side_dist_y = (g_player->pos_y - g_ray->map_y)
		* g_ray->delta_dist_y;
	}
	else
	{
		g_ray->step_y = 1;
		g_ray->side_dist_y = (g_ray->map_y + 1.0 - g_player->pos_y)
		* g_ray->delta_dist_y;
	}
}

void	find_wall_or_sprite(void)
{
	while (g_ray->hit == 0)
	{
		if (g_ray->side_dist_x < g_ray->side_dist_y)
		{
			g_ray->side_dist_x += g_ray->delta_dist_x;
			g_ray->map_x += g_ray->step_x;
			if (g_ray->step_x == 1)
				g_ray->side = 0;
			else if (g_ray->step_x == -1)
				g_ray->side = 1;
		}
		else
		{
			g_ray->side_dist_y += g_ray->delta_dist_y;
			g_ray->map_y += g_ray->step_y;
			if (g_ray->step_y == 1)
				g_ray->side = 2;
			else if (g_ray->step_y == -1)
				g_ray->side = 3;
		}
		if (g_map->map_array[g_ray->map_y][g_ray->map_x] == '1')
			g_ray->hit = 1;
		else if (g_map->map_array[g_ray->map_y][g_ray->map_x] == '2')
			add_displayable_sprite();
	}
}

void	calcul_wall_height(void)
{
	if (g_ray->side == 0 || g_ray->side == 1)
		g_ray->perp_wall_dist = (g_ray->map_x - g_player->pos_x
		+ (1 - g_ray->step_x) / 2) / g_ray->dir_x;
	else
		g_ray->perp_wall_dist = (g_ray->map_y - g_player->pos_y
		+ (1 - g_ray->step_y) / 2) / g_ray->dir_y;
	if (g_ray->perp_wall_dist == -0)
		g_ray->perp_wall_dist = 0;
	g_ray->z_buffer[g_ray->line_x] = g_ray->perp_wall_dist;
	g_ray->wall_height = (int)(g_win->height / g_ray->perp_wall_dist);
}

void	calcul_wall_ordinate(void)
{
	g_ray->draw_start = (-g_ray->wall_height / 2) + (g_win->height / 2);
	if (g_ray->draw_start < 0)
		g_ray->draw_start = 0;
	g_ray->draw_end = (g_ray->wall_height / 2) + (g_win->height / 2);
	if (g_ray->draw_end >= g_win->height || g_ray->draw_end < 0)
		g_ray->draw_end = g_win->height - 1;
}

void	calcul_wall_x(void)
{
	if (g_ray->side == 0 || g_ray->side == 1)
		g_ray->wall_x = g_player->pos_y + g_ray->perp_wall_dist * g_ray->dir_y;
	else
		g_ray->wall_x = g_player->pos_x + g_ray->perp_wall_dist * g_ray->dir_x;
	g_ray->wall_x -= floor((g_ray->wall_x));
}
