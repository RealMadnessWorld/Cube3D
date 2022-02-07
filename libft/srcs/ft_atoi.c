/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:47:32 by jarsenio          #+#    #+#             */
/*   Updated: 2021/03/05 19:50:29 by jarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	int	neg;
	int	n;

	n = 0;
	neg = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || \
			*str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		neg = 1;
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
		n = n * 10 + (*str++ - '0');
	if (neg == 1)
		return (-n);
	else
		return (n);
}
