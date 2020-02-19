/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:59:00 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/10 16:49:41 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	display_pixel_texture(int x, int y)
{
	int			coef;
	int			tex_x;
	int			tex_y;
	t_image		*text;

	if (g_ray->side == 0)
		text = g_textures[3];
	else if (g_ray->side == 1)
		text = g_textures[2];
	else if (g_ray->side == 2)
		text = g_textures[1];
	else
		text = g_textures[0];
	tex_x = (int)(g_ray->wall_x * (double)text->width);
	coef = y * text->size_line - (g_win->height * g_player->cam_height)
	* text->size_line / 2 + g_ray->wall_height * text->size_line / 2;
	tex_y = ((coef * text->height) / g_ray->wall_height) / text->size_line;
	g_img->data[y * g_img->size_line + x * g_img->bpp / 8] =
	text->data[tex_y * text->size_line + tex_x * text->bpp / 8];
	g_img->data[y * g_img->size_line + x * g_img->bpp / 8 + 1] =
	text->data[tex_y * text->size_line + tex_x * text->bpp / 8 + 1];
	g_img->data[y * g_img->size_line + x * g_img->bpp / 8 + 2] =
	text->data[tex_y * text->size_line + tex_x * text->bpp / 8 + 2];
}

void	display_vertical_texture(int y_start, int y_end)
{
	while (y_start < y_end)
	{
		display_pixel_texture(g_ray->line_x, y_start);
		y_start++;
	}
}
