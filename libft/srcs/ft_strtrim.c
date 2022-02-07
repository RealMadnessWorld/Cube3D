/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:23:19 by jarsenio          #+#    #+#             */
/*   Updated: 2021/03/05 20:23:44 by jarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	check(char const c, char const *set)
{
	int		i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		i;
	int		end;
	char	*ugh;

	if (!s1)
		return (0);
	end = ft_strlen(s1);
	start = 0;
	i = 0;
	while (s1[start] != '\0' && check(s1[start], set))
		start++;
	while (end > start && check(s1[end - 1], set))
		end--;
	ugh = malloc(sizeof(*s1) * (end - start + 1));
	if (!ugh)
		return (NULL);
	while (start != end)
		ugh[i++] = s1[start++];
	ugh[i] = '\0';
	return (ugh);
}
