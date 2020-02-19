/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:30:07 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/19 10:51:47 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		is_sprite(char *str)
{
	if (str[0] == 'S')
	{
		if (g_config->sprite == 1)
			exit_game("Error\nSprite texture already defined\n");
		return (OK);
	}
	return (KO);
}

void	sprite_extension(char *str)
{
	int len;

	len = ft_strlen(str);
	if (str[len - 4] != '.' && str[len - 3] != 'x'
	&& str[len - 2] != 'p' && str[len - 1] != 'm')
		exit_game("Error\nInvalid sprite texture file extension\n");
}

void	open_sprite_file(char *path)
{
	if (open(path, O_RDONLY) == -1)
		exit_game("Error\nSprite texture file can't be open\n");
	else
		init_sprite(path);
}

void	parse_sprite(char *str)
{
	int		cmp_str;
	int		cmp_path;
	char	*path;

	cmp_path = 0;
	cmp_str = 1;
	sprite_extension(str);
	cmp_str += browse_space(&str[cmp_str]);
	if (str[cmp_str] == '.')
	{
		if (!(path = (char *)malloc(sizeof(char) * (ft_strlen(str) - cmp_str + 1))))
			exit_game("Error\nMemory allocation error\n");
		while (str[cmp_str] >= ' ' && str[cmp_str] <= '~')
		{
			path[cmp_path] = str[cmp_str];
			cmp_path++;
			cmp_str++;
		}
		path[cmp_path] = '\0';
		open_sprite_file(path);
	}
	else
		exit_game("Error\nInvalid caracter before sprite texture path\n");
	g_config->sprite = 1;
}
