/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:39:09 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/10 16:49:00 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	draw_vert(void)
{
	display_vertical_color(g_win->floor_color, 0, g_ray->draw_start);
	display_vertical_texture(g_ray->draw_start, g_ray->draw_end);
	display_vertical_color(g_win->ceiling_color,
	g_ray->draw_end, g_win->height);
}

void	draw(void)
{
	init_ray();
	while (g_ray->line_x < g_win->width)
	{
		init_ray_values();
		calcul_wall_distance();
		find_wall_or_sprite();
		calcul_wall_height();
		calcul_wall_ordinate();
		calcul_wall_x();
		draw_vert();
		g_ray->line_x++;
	}
	diplay_sprite();
	if (g_win->save == 0)
		mlx_put_image_to_window(g_win->mlx_ptr,
		g_win->win_ptr, g_img->img_ptr, 0, 0);
	else if (g_win->save == 1)
		create_bitmap();
	free(g_ray->z_buffer);
	g_ray->z_buffer = NULL;
	free(g_ray);
	g_ray = NULL;
	free_diplayed_sprites();
}

int		loop(void)
{
	draw();
	key_manager();
	return (1);
}

void	check_save(int argc, char **argv)
{
	if (argc < 2)
		exit_game("Error\nNo map provided\n");
	else if (argc >= 3)
	{
		if (argv[2][0] == '-' && argv[2][1] == 's' && argv[2][2] == 'a'
		&& argv[2][3] == 'v' && argv[2][4] == 'e')
			g_win->save = 1;
		else if (argv[2][0] == '-' && argv[2][1] == '-' && argv[2][2] == 's'
		&& argv[2][3] == 'a' && argv[2][4] == 'v' && argv[2][5] == 'e')
			g_win->save = 1;
		else
			g_win->save = 0;
	}
}

int		main(int argc, char **argv)
{
	init_win();
	check_save(argc, argv);
	init_map();
	init_key();
	init_player();
	init_img();
	init_texture_array();
	parse_config(argv[1]);
	set_win_and_img();
	init_texture_data();
	mlx_hook(g_win->win_ptr, 2, 0, key_pressed, g_win);
	mlx_hook(g_win->win_ptr, 3, 0, key_released, g_win);
	mlx_hook(g_win->win_ptr, 17, 0, end_game, g_win);
	mlx_loop_hook(g_win->mlx_ptr, loop, g_win);
	mlx_loop(g_win->mlx_ptr);
}
