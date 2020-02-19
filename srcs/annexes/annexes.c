/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <ajeannot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:42:25 by ajeannot          #+#    #+#             */
/*   Updated: 2020/02/08 18:46:11 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_atoi_cub(const char *nb_str)
{
	int	cmp;
	int	nb_final;

	cmp = 0;
	nb_final = 0;
	while (nb_str[cmp] > 47 && nb_str[cmp] < 58)
	{
		nb_final = (nb_final * 10) + (nb_str[cmp] - 48);
		cmp++;
	}
	return (nb_final);
}

char	*ft_strjoin_cub(char *str_1, char *str_2, int len_1, int len_2)
{
	int		cmp;
	char	*output_str;

	if (!(output_str = (char *)malloc(sizeof(char) * (len_1 + len_2 + 2))))
		exit_game("Error\nMemory allocation error\n");
	cmp = 0;
	if (str_1)
		while (str_1[cmp])
		{
			output_str[cmp] = str_1[cmp];
			cmp++;
		}
	cmp = 0;
	while (str_2[cmp])
	{
		output_str[cmp + len_1] = str_2[cmp];
		cmp++;
	}
	output_str[cmp + len_1] = '\n';
	output_str[cmp + len_1 + 1] = '\0';
	if (str_1)
		free(str_1);
	return (output_str);
}

int		ft_strlen(char *str)
{
	int cmp;

	cmp = 0;
	if (str)
		while (str[cmp])
			cmp++;
	return (cmp);
}

int		ft_strlen_without_space(char *str)
{
	int cmp;
	int cmp_car;

	cmp = 0;
	cmp_car = 0;
	if (str)
		while (str[cmp])
		{
			if (str[cmp] != ' ')
			{
				cmp++;
				cmp_car++;
			}
			else
				cmp++;
		}
	return (cmp_car);
}

int		browse_space(char *str)
{
	int cmp;

	cmp = 0;
	while (str[cmp] == ' ')
		cmp++;
	return (cmp);
}
