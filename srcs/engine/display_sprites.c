/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:47:07 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/07 14:27:41 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_values(void)
{
	g_s_draw->inv_det = 1.0 / (g_player->plane_x * g_player->dir_y
	- g_player->dir_x * g_player->plane_y);
	g_s_draw->transform_x = g_s_draw->inv_det * (g_player->dir_y
	* g_s_draw->sprite_x - g_player->dir_x * g_s_draw->sprite_y);
	g_s_draw->transform_y = g_s_draw->inv_det * (-g_player->plane_y
	* g_s_draw->sprite_x + g_player->plane_x * g_s_draw->sprite_y);
	g_s_draw->sprite_screen_x = (int)((g_win->width / 2)
	* (1 + g_s_draw->transform_x / g_s_draw->transform_y));
}

void	calcul_values(void)
{
	set_values();
	g_s_draw->sprite_height = abs((int)(g_win->height
	/ g_s_draw->transform_y));
	g_s_draw->start_y = -g_s_draw->sprite_height / 2
	+ ((g_win->height / 2) * g_player->cam_height);
	if (g_s_draw->start_y < 0)
		g_s_draw->start_y = 0;
	g_s_draw->end_y = g_s_draw->sprite_height / 2
	+ ((g_win->height / 2) * g_player->cam_height);
	if (g_s_draw->end_y >= g_win->height)
		g_s_draw->end_y = g_win->height - 1;
	g_s_draw->sprite_width = abs((int)(g_win->height
	/ g_s_draw->transform_y));
	g_s_draw->start_x = -g_s_draw->sprite_width / 2
	+ g_s_draw->sprite_screen_x;
	if (g_s_draw->start_x < 0)
		g_s_draw->start_x = 0;
	g_s_draw->end_x = g_s_draw->sprite_width / 2
	+ g_s_draw->sprite_screen_x;
	if (g_s_draw->end_x >= g_win->width)
		g_s_draw->end_x = g_win->width - 1;
}

void	pix_on_sprite_image(void)
{
	g_s_draw->coef = g_s_draw->y * g_s_texture->size_line - (g_win->height
	* g_player->cam_height) * (g_s_texture->size_line / 2)
	+ g_s_draw->sprite_height * g_s_texture->size_line / 2;
	g_s_draw->tex_y = ((g_s_draw->coef * g_s_texture->height)
	/ g_s_draw->sprite_height) / g_s_texture->size_line;
	g_s_draw->pix_color = g_s_texture->data[g_s_draw->tex_y
	* g_s_texture->size_line + g_s_draw->tex_x * g_s_texture->bpp / 8]
	+ g_s_texture->data[g_s_draw->tex_y * g_s_texture->size_line
	+ g_s_draw->tex_x * g_s_texture->bpp / 8 + 1]
	+ g_s_texture->data[g_s_draw->tex_y * g_s_texture->size_line
	+ g_s_draw->tex_x * g_s_texture->bpp / 8 + 2];
}

void	pix_to_be_diplay(void)
{
	g_img->data[g_s_draw->y * g_img->size_line + g_s_draw->start_x
	* g_img->bpp / 8] =
	g_s_texture->data[g_s_draw->tex_y * g_s_texture->size_line
	+ g_s_draw->tex_x * g_s_texture->bpp / 8];
	g_img->data[g_s_draw->y * g_img->size_line + g_s_draw->start_x
	* g_img->bpp / 8 + 1] =
	g_s_texture->data[g_s_draw->tex_y * g_s_texture->size_line
	+ g_s_draw->tex_x * g_s_texture->bpp / 8 + 1];
	g_img->data[g_s_draw->y * g_img->size_line + g_s_draw->start_x
	* g_img->bpp / 8 + 2] =
	g_s_texture->data[g_s_draw->tex_y * g_s_texture->size_line
	+ g_s_draw->tex_x * g_s_texture->bpp / 8 + 2];
}

void	draw_sprite(t_sprite_array *sprite_pos)
{
	g_s_draw->sprite_x = sprite_pos->x - (g_player->pos_x - 0.5);
	g_s_draw->sprite_y = sprite_pos->y - (g_player->pos_y - 0.5);
	calcul_values();
	while (g_s_draw->start_x < g_s_draw->end_x)
	{
		g_s_draw->tex_x = (int)(g_s_texture->size_line * (g_s_draw->start_x
		- (-g_s_draw->sprite_width / 2 + g_s_draw->sprite_screen_x))
		* g_s_texture->width / g_s_draw->sprite_width) / g_s_texture->size_line;
		if (g_s_draw->transform_y > 0 && g_s_draw->start_x > 0
		&& g_s_draw->start_x < g_win->width && g_s_draw->transform_y
		< g_ray->z_buffer[g_s_draw->start_x])
		{
			g_s_draw->y = g_s_draw->start_y;
			while (g_s_draw->y < g_s_draw->end_y)
			{
				pix_on_sprite_image();
				if (g_s_draw->pix_color != 0)
					pix_to_be_diplay();
				g_s_draw->y++;
			}
		}
		g_s_draw->start_x++;
	}
}
