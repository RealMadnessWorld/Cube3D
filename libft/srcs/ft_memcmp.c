/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:25:10 by jarsenio          #+#    #+#             */
/*   Updated: 2021/03/05 20:00:49 by jarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	char			*ss1;
	char			*ss2;

	i = 0;
	ss1 = (char *)s1;
	ss2 = (char *)s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && ss1[i] == ss2[i])
		i++;
	return ((unsigned char)ss1[i] - (unsigned char)ss2[i]);
}
