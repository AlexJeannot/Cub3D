/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:24:26 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/12 10:18:58 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		is_resolution(char *str)
{
	if (str[0] == 'R')
	{
		if (g_config->resolution == 1)
			exit_game("Error\nResolution already defined\n");
		return (OK);
	}
	return (KO);
}

void	set_width(char *str, int cmp)
{
	if ((g_win->width = ft_atoi_cub(&str[cmp])) == 0)
		exit_game("Error\nResolution width must not be zero\n");
	else if (g_win->width > 2560)
		g_win->width = 2560;
}

void	parse_resolution(char *str)
{
	int cmp;

	cmp = 1;
	cmp += browse_space(&str[cmp]);
	if (str[cmp] >= '0' && str[cmp] <= '9')
	{
		set_width(str, cmp);
		cmp += browse_number(&str[cmp]);
		cmp += browse_space(&str[cmp]);
		if (str[cmp] < '0' || str[cmp] > '9')
			exit_game("Error\nInvalid caracter between resolution W and H\n");
		if ((g_win->height = ft_atoi_cub(&str[cmp])) == 0)
			exit_game("Error\nResolution height must not be zero\n");
		if (g_win->height > 1440)
			g_win->height = 1440;
		cmp += browse_number(&str[cmp]);
		cmp += browse_space(&str[cmp]);
		if (str[cmp] != '\0')
			exit_game("Error\nInvalid caracter after resolution height\n");
		g_config->resolution = 1;
	}
	else
		exit_game("Error\nInvalid caracter before resolution width\n");
}
