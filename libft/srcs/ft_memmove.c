/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:14:19 by jarsenio          #+#    #+#             */
/*   Updated: 2021/03/05 20:03:05 by jarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	const char	*tsrc;
	char		*tdest;

	tsrc = src;
	tdest = dest;
	if (!dest && !src)
		return (0);
	if (src < dest)
	{
		tsrc = tsrc + len - 1;
		tdest = tdest + len - 1;
		while (len--)
		{
			*tdest-- = *tsrc--;
		}
	}
	else
		while (len--)
			*tdest++ = *tsrc++;
	return (dest);
}
