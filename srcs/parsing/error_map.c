/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:52:23 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/19 10:52:36 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		check_map_middle(int cmp_array, int cmp_str)
{
	if (g_map->map_array[cmp_array][cmp_str] == 'N'
	|| g_map->map_array[cmp_array][cmp_str] == 'S'
	|| g_map->map_array[cmp_array][cmp_str] == 'E'
	|| g_map->map_array[cmp_array][cmp_str] == 'W')
		cmp_str += set_player_position(cmp_str, cmp_array,
		g_map->map_array[cmp_array][cmp_str]);
	else if (g_map->map_array[cmp_array][cmp_str] != '0'
	&& g_map->map_array[cmp_array][cmp_str] != '1'
	&& g_map->map_array[cmp_array][cmp_str] != '2')
		exit_game("Error\nInvalid caracter in the map\n");
	return (cmp_str);
}

void	check_map_error(void)
{
	int cmp_array;
	int cmp_str;

	check_top_and_bottom_map(0);
	check_top_and_bottom_map(g_map->height - 1);
	cmp_array = 1;
	while (cmp_array < g_map->height - 1)
	{
		cmp_str = 0;
		if (g_map->map_array[cmp_array][0] != '1')
			exit_game("Error\nMap is not closed on the west side\n");
		if (g_map->map_array[cmp_array][g_map->width - 1] != '1')
			exit_game("Error\nMap is not closed on the east side\n");
		while (g_map->map_array[cmp_array][cmp_str])
		{
			cmp_str = check_map_middle(cmp_array, cmp_str);
			cmp_str++;
		}
		cmp_array++;
	}
	if (g_config->player_position == 0)
		exit_game("Error\nNo player position defined\n");
}

void	check_top_and_bottom_map(int array)
{
	int cmp_str;

	cmp_str = 0;
	while (g_map->map_array[array][cmp_str])
	{
		while (g_map->map_array[array][cmp_str] == ' ')
			cmp_str++;
		if (g_map->map_array[array][cmp_str] != '1')
		{
			if (array == 0)
				exit_game("Error\nMap is not closed on the north side\n");
			else if (array == g_map->height - 1)
				exit_game("Error\nMap is not closed on the south side\n");
		}
		cmp_str++;
	}
}

void	check_line_length(void)
{
	int cmp;
	int cmp_car;

	cmp_car = 0;
	if (g_config->map == 0)
		exit_game("Error\nNo map in configuration file\n");
	while (g_map->map_str[cmp])
	{
		if (g_map->map_str[cmp] == '\n')
		{
			if (cmp_car != g_map->width)
				exit_game("Error\nInvalid map width\n");
			cmp_car = -1;
		}
		if (g_map->map_str[cmp] == ' ')
			cmp++;
		else
		{
			cmp++;
			cmp_car++;
		}
	}
}
