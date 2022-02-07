/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 20:14:44 by jarsenio          #+#    #+#             */
/*   Updated: 2022/01/02 19:04:02 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin_path(char const *s1, char const *s2, char const *s3)
{
	char	*ptr;
	int		len;
	int		i;

	i = 0;
	len = (ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3));
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	if (!s1)
		return (NULL);
	if (!s2)
		return ((char *)s1);
	while (*s1 != '\0')
	{
		ptr[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
		ptr[i++] = *s2++;
	while (*s3 != '\0')
		ptr[i++] = *s3++;
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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
