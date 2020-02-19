/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:11:46 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/08 18:46:08 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_win(void)
{
	if (!(g_win = (t_win *)malloc(sizeof(t_win))))
		exit_game("Error\nMemory allocation error\n");
	g_win->width = 0;
	g_win->height = 0;
	g_win->floor_color = 0;
	g_win->ceiling_color = 0;
	g_win->have_sprite = 0;
	g_win->win_set = 0;
}

void	init_map(void)
{
	if (!(g_map = (t_map *)malloc(sizeof(t_map))))
		exit_game("Error\nMemory allocation error\n");
	g_map->map_str = NULL;
	g_map->map_array = NULL;
	g_map->width = 0;
	g_map->height = 0;
}

void	init_key(void)
{
	if (!(g_key = (t_key *)malloc(sizeof(t_key))))
		exit_game("Error\nMemory allocation error\n");
	g_key->toward = 0;
	g_key->backward = 0;
	g_key->left = 0;
	g_key->right = 0;
	g_key->turn_left = 0;
	g_key->turn_right = 0;
	g_key->exit = 0;
}

void	init_player(void)
{
	if (!(g_player = (t_player *)malloc(sizeof(t_player))))
		exit_game("Error\nMemory allocation error\n");
	g_player->pos_x = 0;
	g_player->pos_y = 0;
	g_player->dir_x = 0.0;
	g_player->dir_y = 0.0;
	g_player->plane_x = 0.0;
	g_player->plane_y = 0.0;
	g_player->rotate_speed = 0.10;
	g_player->speed = 0.25;
	g_player->cam_height = 1.0;
}

void	init_img(void)
{
	if (!(g_img = (t_image *)malloc(sizeof(t_image))))
		exit_game("Error\nMemory allocation error\n");
	g_img->width = g_win->width;
	g_img->height = g_win->height;
	g_img->size_line = 0;
	g_img->bpp = 0;
	g_img->endian = 0;
}
