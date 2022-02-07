/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:24:15 by jarsenio          #+#    #+#             */
/*   Updated: 2021/03/09 17:27:08 by jarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int i, size_t len)
{
	size_t	c;
	char	*temp;

	c = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	temp = malloc(sizeof(*s) * (len + 1));
	if (!temp)
		return (NULL);
	if (i >= ft_strlen(s))
	{
		temp[c] = '\0';
		return (temp);
	}
	while (c < len)
	{
		temp[c] = s[i];
		i++;
		c++;
	}
	temp[c] = '\0';
	return (temp);
}
