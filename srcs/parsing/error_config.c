/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:50:30 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/08 18:45:57 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		arg_extension(char *str)
{
	int cmp;

	cmp = ft_strlen(str);
	if (str[cmp - 4] != '.' && str[cmp - 3] != 'b'
	&& str[cmp - 2] != 'u' && str[cmp - 1] != 'c')
	{
		exit_game("Error\nWrong extension for configuration file");
		return (KO);
	}
	else
		return (OK);
}

int		open_config(char *path)
{
	int		fd;
	char	buf[1];

	if ((fd = open(path, O_RDONLY)) == -1)
	{
		exit_game("Error\nConfiguration file can't be open\n");
		return (KO);
	}
	else
		return (fd);
}

void	check_all_config_elem_before_map(void)
{
	if (g_config->resolution == 0)
		exit_game("Error\nNo resolution before map in configuration file\n");
	else if (g_config->texture_no == 0)
		exit_game("Error\nNo north texture before map in configuration file\n");
	else if (g_config->texture_so == 0)
		exit_game("Error\nNo south texture before map in configuration file\n");
	else if (g_config->texture_ea == 0)
		exit_game("Error\nNo east texture before map in configuration file\n");
	else if (g_config->texture_we == 0)
		exit_game("Error\nNo west texture before map in configuration file\n");
	else if (g_config->rgb_f == 0)
		exit_game("Error\nNo floor RGB before map in configuration file\n");
	else if (g_config->rgb_c == 0)
		exit_game("Error\nNo ceiling RGB before map in configuration file\n");
	else if (g_config->sprite == 0)
		exit_game("Error\nNo sprite texture in configuration file\n");
}
