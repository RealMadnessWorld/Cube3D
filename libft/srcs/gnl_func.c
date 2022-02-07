/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:02:19 by jarsenio          #+#    #+#             */
/*   Updated: 2021/11/16 17:56:37 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoingnl(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlengnl(s1) + ft_strlengnl(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

size_t	ft_strlengnl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdupgnl(const char *str)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(sizeof(*str) * (ft_strlengnl(str) + 1));
	if (!ptr)
		return (NULL);
	while (str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchrgnl(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == 0)
			return (0);
		s++;
	}
	return ((char *)s);
}

char	*ft_substrgnl(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlengnl(s);
	if (start >= s_len)
	{
		p = malloc(sizeof(char));
		if (!p)
			return (0);
		*p = '\0';
		return (p);
	}
	if (s_len < len)
		return (ft_strdupgnl(s + start));
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (start < s_len && i < len)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}
