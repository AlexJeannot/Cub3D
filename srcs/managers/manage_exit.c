/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:26:39 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/12 10:11:11 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_path_textures(void)
{
	if (g_textures)
	{
		if (g_config->texture_no == 1 && g_textures[0]->path)
			free(g_textures[0]->path);
		if (g_config->texture_so == 1 && g_textures[1]->path)
			free(g_textures[1]->path);
		if (g_config->texture_we == 1 && g_textures[2]->path)
			free(g_textures[2]->path);
		if (g_config->texture_ea == 1 && g_textures[3]->path)
			free(g_textures[3]->path);
	}
}

void	free_textures(void)
{
	free_path_textures();
	if (g_textures)
	{
		if (g_config)
		{
			if (g_config->texture_no == 1)
				free(g_textures[0]);
			if (g_config->texture_so == 1)
				free(g_textures[1]);
			if (g_config->texture_we == 1)
				free(g_textures[2]);
			if (g_config->texture_ea == 1)
				free(g_textures[3]);
		}
		free(g_textures);
	}
}

void	free_struct(void)
{
	if (g_map)
		free(g_map);
	if (g_key)
		free(g_key);
	if (g_player)
		free(g_player);
	if (g_img)
		free(g_img);
	if (g_ray)
		free(g_ray);
	if (g_s_texture)
	{
		if (g_s_texture->path)
			free(g_s_texture->path);
		free(g_s_texture);
	}
	if (g_win)
		free(g_win);
	if (g_config)
		free(g_config);
}

void	free_elements(void)
{
	int	cmp;

	cmp = 0;
	if (g_map && g_map->map_array)
	{
		while (cmp < g_map->height)
		{
			if (g_map->map_array[cmp])
				free(g_map->map_array[cmp]);
			cmp++;
		}
	}
	if (g_ray && g_ray->z_buffer)
		free(g_ray->z_buffer);
	if (g_map && g_map->map_str)
		free(g_map->map_str);
	if (g_map && g_map->map_array)
		free(g_map->map_array);
	if (g_s_draw)
		free(g_s_draw);
	free_diplayed_sprites();
	free_textures();
	free_struct();
}

void	exit_game(char *str)
{
	int cmp;

	cmp = 0;
	if (str)
	{
		while (str[cmp])
		{
			write(1, &str[cmp], 1);
			cmp++;
		}
	}
	if (g_win && g_win->win_set == 1)
		mlx_destroy_window(g_win->mlx_ptr, g_win->win_ptr);
	free_elements();
	exit(1);
}
