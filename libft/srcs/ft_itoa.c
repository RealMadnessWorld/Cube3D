/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:53:44 by jarsenio          #+#    #+#             */
/*   Updated: 2022/01/02 17:07:40 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	is_neg(int i)
{
	if (i < 0)
		return (-1);
	else
		return (1);
}

static char	*ft_swap(char *s)
{
	int		i;
	int		leng;
	char	temp;

	leng = ft_strlen(s);
	i = 0;
	while (i < leng / 2)
	{
		temp = s[i];
		s[i] = s[leng - i - 1];
		s[leng - i - 1] = temp;
		i++;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		i;
	char	str[12];

	i = 0;
	sign = 0;
	ft_memset(str, 0, 12);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	sign = is_neg(n);
	n = is_neg(n) * n;
	while (n > 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (sign < 0)
		str[i] = '-';
	ft_swap(str);
	return (ft_strdup(str));
}
