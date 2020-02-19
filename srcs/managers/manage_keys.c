/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:32:42 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/08 18:51:28 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	key_manager(void)
{
	if (g_key->exit == 1)
		exit_game(NULL);
	if (g_key->toward == 1)
		forward();
	if (g_key->backward == 1)
		backward();
	if (g_key->left == 1)
		left();
	if (g_key->right == 1)
		right();
	if (g_key->turn_left == 1)
		turn_left();
	if (g_key->turn_right == 1)
		turn_right();
}
