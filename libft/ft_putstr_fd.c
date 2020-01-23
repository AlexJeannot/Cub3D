/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 18:57:18 by ajeannot          #+#    #+#             */
/*   Updated: 2019/11/09 16:30:51 by ajeannot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	cmp;

	cmp = 0;
	while (s[cmp])
	{
		ft_putchar_fd(s[cmp], fd);
		cmp++;
	}
}
