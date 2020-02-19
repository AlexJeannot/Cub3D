/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:14:05 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/08 18:46:08 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_texture_array(void)
{
	if (!(g_textures = malloc(sizeof(t_image *) * 4)))
		exit_game("Error\nMemory allocation error\n");
}

void	init_texture(char *path, int index)
{
	t_image *new_elem;

	if (!(new_elem = (t_image *)malloc(sizeof(t_image))))
		exit_game("Error\nMemory allocation error\n");
	new_elem->path = path;
	g_textures[index] = new_elem;
	if (index == 0)
		g_config->texture_no = 1;
	else if (index == 1)
		g_config->texture_so = 1;
	else if (index == 2)
		g_config->texture_we = 1;
	else if (index == 3)
		g_config->texture_ea = 1;
}

void	init_texture_data(void)
{
	int		cmp;
	t_image	*elem;

	cmp = 0;
	while (cmp < 4)
	{
		elem = g_textures[cmp];
		elem->img_ptr = mlx_xpm_file_to_image(g_win->mlx_ptr, elem->path,
		&elem->width, &elem->height);
		elem->data = mlx_get_data_addr(elem->img_ptr, &elem->bpp,
		&elem->size_line, &elem->endian);
		free(elem->path);
		elem->path = NULL;
		cmp++;
	}
	init_sprite_data();
}

void	init_sprite(char *path)
{
	if (!(g_s_texture = malloc(sizeof(t_image))))
		exit_game("Error\nMemory allocation error\n");
	g_s_texture->path = path;
}

void	init_sprite_data(void)
{
	g_s_texture->img_ptr = mlx_xpm_file_to_image(g_win->mlx_ptr,
	g_s_texture->path, &g_s_texture->width, &g_s_texture->height);
	g_s_texture->data = mlx_get_data_addr(g_s_texture->img_ptr,
	&g_s_texture->bpp, &g_s_texture->size_line, &g_s_texture->endian);
	free(g_s_texture->path);
	g_s_texture->path = NULL;
}
