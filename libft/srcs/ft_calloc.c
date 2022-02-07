/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:50:47 by jarsenio          #+#    #+#             */
/*   Updated: 2021/11/07 04:06:57 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	alloc;
	char	*p;

	alloc = size * count;
	p = malloc(alloc);
	if (!(p))
		return (NULL);
	ft_bzero(p, alloc);
	return (p);
}
