/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 19:14:05 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/10 13:31:36 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_ray(void)
{
	if (!(g_ray = (t_ray *)malloc(sizeof(t_ray))))
		exit_game("Error\nMemory allocation error\n");
	g_ray->line_x = 0;
	if (!(g_ray->z_buffer = malloc(sizeof(double) * g_win->width)))
		exit_game("Error\nMemory allocation error\n");
}

void	init_ray_values(void)
{
	g_ray->camera_x = (2 * g_ray->line_x) / (double)g_win->width - 1;
	g_ray->dir_x = g_player->dir_x + g_player->plane_x * g_ray->camera_x;
	g_ray->dir_y = g_player->dir_y + g_player->plane_y * g_ray->camera_x;
	g_ray->map_x = (int)g_player->pos_x;
	g_ray->map_y = (int)g_player->pos_y;
	g_ray->delta_dist_x = fabs(1 / g_ray->dir_x);
	g_ray->delta_dist_y = fabs(1 / g_ray->dir_y);
	g_ray->hit = 0;
}

void	set_win_and_img(void)
{
	g_win->mlx_ptr = mlx_init();
	g_win->win_ptr = mlx_new_window(g_win->mlx_ptr,
	g_win->width, g_win->height, "Cub3D");
	g_img->img_ptr = mlx_new_image(g_win->mlx_ptr,
	g_win->width, g_win->height);
	g_img->data = mlx_get_data_addr(g_img->img_ptr, &g_img->bpp,
	&g_img->size_line, &g_img->endian);
	g_win->win_set = 1;
}
