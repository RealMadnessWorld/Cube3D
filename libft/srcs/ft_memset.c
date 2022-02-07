/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:21:01 by jarsenio          #+#    #+#             */
/*   Updated: 2021/03/05 20:03:31 by jarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char			*lol;
	unsigned int	i;

	lol = str;
	i = 0;
	while (i < n)
	{
		lol[i] = c;
		i++;
	}
	return (str);
}
