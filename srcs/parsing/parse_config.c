/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:06:25 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/08 18:35:33 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_config(void)
{
	if (!(g_config = malloc(sizeof(t_config))))
		exit_game("Error\nMemory allocation error\n");
	g_config->resolution = 0;
	g_config->texture_no = 0;
	g_config->texture_so = 0;
	g_config->texture_ea = 0;
	g_config->texture_we = 0;
	g_config->rgb_f = 0;
	g_config->rgb_c = 0;
	g_config->sprite = 0;
	g_config->map = 0;
	g_config->player_position = 0;
}

void	parse_line(char *str)
{
	int index_texture;

	if (is_resolution(str) != -1)
		parse_resolution(str);
	else if ((index_texture = is_texture(str)) != -1)
		parse_texture(str, index_texture);
	else if (is_rgb(str) != -1)
		parse_rgb(str);
	else if (is_sprite(str) != -1)
		parse_sprite(str);
	else if (is_map(str) != -1)
		parse_map(str);
	else
		exit_game("Error\nInvalid line in configuration file\n");
}

void	check_in_map(int ret, char *str)
{
	free(str);
	str = NULL;
	if (g_config->map == 1 && ret != 0)
		exit_game("Error\nLine beak in map description\n");
}

void	end_parse_config(char *str, int pass)
{
	if (pass == 0)
		exit_game("Error\nConfiguration file is empty\n");
	free(str);
	str = NULL;
	map_into_array();
	check_map_error();
}

int		parse_config(char *path)
{
	char	*str;
	int		ret;
	int		fd;
	int		pass;

	pass = 0;
	init_config();
	arg_extension(path);
	fd = open_config(path);
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		pass = 1;
		if (ret == -1)
			exit_game("Error\nWhile browsing configuration file\n");
		if (str[0] != '\0')
		{
			parse_line(str);
			free(str);
			str = NULL;
		}
		else
			check_in_map(ret, str);
	}
	end_parse_config(str, pass);
	return (OK);
}
