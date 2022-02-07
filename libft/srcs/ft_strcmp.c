/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:32:59 by fmeira            #+#    #+#             */
/*   Updated: 2022/01/02 19:01:49 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	char	*one;
	char	*two;

	one = s1;
	two = s2;
	if (!one && !two)
		return (0);
	if (ft_strlen(one) != ft_strlen(two))
		return (1);
	while (*one != '\0' && *one == *two)
	{
		one++;
		two++;
	}
	if (*one == '\0')
		return (0);
	else
		return (*(unsigned char *)one - *(unsigned char *)two);
}
