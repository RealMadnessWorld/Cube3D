/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ext.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:35 by jarsenio          #+#    #+#             */
/*   Updated: 2021/11/16 17:57:15 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	find_extention(char *str, char *ext)
{
	int	i;
	int	x;

	i = ft_strlen(str);
	x = ft_strlen(ext);
	while (i != 0 && str[i] != '.')
	{
		if (str[i] != ext[x])
		{
			return (0);
		}
		i--;
		x--;
	}
	return (1);
}
