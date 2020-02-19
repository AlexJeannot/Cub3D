/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:12:40 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/19 10:52:19 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		is_map(char *str)
{
	int cmp;

	cmp = 0;
	cmp += browse_space(&str[cmp]);
	if (g_config->map == 1)
	{
		if (str[cmp] == '1')
			return (OK);
		else
			exit_game("Error\nMap is not closed on the west side\n");
		return (KO);
	}
	else
	{
		if (str[cmp] == '1')
			return (OK);
	}
	return (KO);
}

void	parse_map(char *str)
{
	int len;

	len = ft_strlen(str);
	if (g_config->map == 0)
	{
		check_all_config_elem_before_map();
		g_map->map_str = ft_strjoin_cub(g_map->map_str, str, ft_strlen(g_map->map_str), ft_strlen(str));
		g_map->width = ft_strlen_without_space(str);
		g_config->map = 1;
	}
	else
		g_map->map_str = ft_strjoin_cub(g_map->map_str, str, ft_strlen(g_map->map_str), ft_strlen(str));
	g_map->height++;
}

int		char_into_str(int cmp_global, int cmp_str, char *map_str)
{
	while (g_map->map_str[cmp_global] == ' '
	|| g_map->map_str[cmp_global] == '\n')
		cmp_global++;
	map_str[cmp_str] = g_map->map_str[cmp_global];
	return (cmp_global);
}

int		start_map_into_array(void)
{
	check_line_length();
	if (!(g_map->map_array = malloc(sizeof(char *) * (g_map->height))))
		exit_game("Error\nMemory allocation error\n");
	return (0);
}

void	map_into_array(void)
{
	int		cmp_array;
	int		cmp_str;
	int		cmp_global;
	char	*map_str;

	cmp_array = 0;
	cmp_global = start_map_into_array();
	while (cmp_array < g_map->height)
	{
		cmp_str = 0;
		if (!(map_str = malloc(sizeof(char) * (g_map->width + 1))))
			exit_game("Error\nMemory allocation error\n");
		while (cmp_str < g_map->width)
		{
			cmp_global = char_into_str(cmp_global, cmp_str, map_str);
			cmp_str++;
			cmp_global++;
		}
		map_str[cmp_str] = '\0';
		g_map->map_array[cmp_array] = map_str;
		cmp_array++;
		cmp_global++;
	}
	free(g_map->map_str);
	g_map->map_str = NULL;
}
