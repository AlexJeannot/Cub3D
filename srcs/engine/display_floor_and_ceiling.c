/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_floor_and_ceiling.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:46:20 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/10 15:30:36 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	display_pixel_color(int color, int x, int y)
{
	int r;
	int g;
	int b;

	b = color % 256;
	color = (color - b) / 256;
	g = color % 256;
	color = (color - g) / 256;
	r = color;
	g_img->data[y * g_img->size_line + x * g_img->bpp / 8] = (char)r;
	g_img->data[y * g_img->size_line + x * g_img->bpp / 8 + 1] = (char)g;
	g_img->data[y * g_img->size_line + x * g_img->bpp / 8 + 2] = (char)b;
}

void	display_vertical_color(int color, int y_start, int y_end)
{
	while (y_start < y_end)
	{
		display_pixel_color(color, g_ray->line_x, y_start);
		y_start++;
	}
}
