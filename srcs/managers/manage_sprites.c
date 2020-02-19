/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:34:14 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/08 18:46:04 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_displayable_sprites	*init_displayable_sprite(void)
{
	t_displayable_sprites	*new_elem;

	if (!(new_elem = malloc(sizeof(t_displayable_sprites))))
		exit_game("Error\nMemory allocation error\n");
	new_elem->x = g_ray->map_x;
	new_elem->y = g_ray->map_y;
	new_elem->next = NULL;
	return (new_elem);
}

void					add_displayable_sprite(void)
{
	t_displayable_sprites	*browse;

	if (g_win->have_sprite == 0)
	{
		g_s_displayable = init_displayable_sprite();
		g_win->have_sprite += 1;
	}
	else
	{
		browse = g_s_displayable;
		while (browse->next && (browse->x != g_ray->map_x
		|| browse->y != g_ray->map_y))
			browse = browse->next;
		if (browse->x != g_ray->map_x || browse->y != g_ray->map_y)
		{
			browse->next = init_displayable_sprite();
			g_win->have_sprite += 1;
		}
	}
}

void					sprites_into_array(void)
{
	int						cmp;
	t_displayable_sprites	*browse;
	t_sprite_array			*new_sprite;
	t_sprite_array			*last_sprite;

	cmp = 0;
	browse = g_s_displayable;
	if (!(last_sprite = malloc(sizeof(t_sprite_array))))
		exit_game("Error\nMemory allocation error\n");
	browse = g_s_displayable;
	if (browse)
		while (browse)
		{
			if (!(new_sprite = malloc(sizeof(t_sprite_array))))
				exit_game("Error\nMemory allocation error\n");
			new_sprite->x = browse->x;
			new_sprite->y = browse->y;
			g_s_array[cmp] = new_sprite;
			browse = browse->next;
			cmp++;
		}
	last_sprite->y = -1;
	last_sprite->x = -1;
	g_s_array[cmp] = last_sprite;
}

void					sort_displayable_sprites(void)
{
	t_sprite_array	*tmp;
	int				distance_first;
	int				distance_second;
	int				cmp;

	cmp = 0;
	while (g_s_array[cmp + 1]->x != -1)
	{
		distance_first = ((g_player->pos_x - g_s_array[cmp]->x)
	* (g_player->pos_x - g_s_array[cmp]->x)
	+ (g_player->pos_y - g_s_array[cmp]->y)
	* (g_player->pos_y - g_s_array[cmp]->y));
		distance_second = ((g_player->pos_x - g_s_array[cmp + 1]->x)
	* (g_player->pos_x - g_s_array[cmp + 1]->x) + (g_player->pos_y
	- g_s_array[cmp + 1]->y) * (g_player->pos_y - g_s_array[cmp + 1]->y));
		if (distance_first < distance_second)
		{
			tmp = g_s_array[cmp];
			g_s_array[cmp] = g_s_array[cmp + 1];
			g_s_array[cmp + 1] = tmp;
			cmp = 0;
		}
		else
			cmp++;
	}
}
