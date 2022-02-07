/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:20:13 by jarsenio          #+#    #+#             */
/*   Updated: 2021/03/09 17:11:37 by jarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	while (*s1 && i < n)
	{
		j = 0;
		while ((i + j) < n && s1[i + j] == s2[j])
		{
			if (s2[j + 1] == '\0')
			{
				return ((char *)&(s1[i]));
			}
			j++;
		}
		i++;
	}
	return (0);
}
