/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_sprites_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:57:12 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/07 14:27:42 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	diplay_sprite(void)
{
	int cmp;

	cmp = 0;
	if (g_s_displayable)
	{
		if (!(g_s_draw = malloc(sizeof(t_draw))))
			exit_game("Error\nMemory allocation error\n");
		if (!(g_s_array = malloc(sizeof(t_sprite_array *)
		* (g_win->have_sprite + 1))))
			exit_game("Error\nMemory allocation error\n");
		sprites_into_array();
		sort_displayable_sprites();
		while (g_s_array[cmp]->x != -1)
		{
			draw_sprite(g_s_array[cmp]);
			cmp++;
		}
	}
}
