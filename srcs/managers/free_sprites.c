/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:45:57 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/08 18:46:07 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_sprites_list(void)
{
	t_displayable_sprites	*to_delete;

	while (g_s_displayable)
	{
		to_delete = g_s_displayable;
		g_s_displayable = g_s_displayable->next;
		to_delete->next = NULL;
		free(to_delete);
		to_delete = NULL;
	}
}

void	free_diplayed_sprites(void)
{
	int	cmp;

	cmp = 0;
	if (g_win->have_sprite != 0)
	{
		while (cmp <= g_win->have_sprite)
		{
			if (g_s_array[cmp])
				free(g_s_array[cmp]);
			g_s_array[cmp] = NULL;
			cmp++;
		}
		free(g_s_array);
		g_s_array = NULL;
		g_win->have_sprite = 0;
		free_sprites_list();
		if (g_s_draw)
		{
			free(g_s_draw);
			g_s_draw = NULL;
		}
	}
}
