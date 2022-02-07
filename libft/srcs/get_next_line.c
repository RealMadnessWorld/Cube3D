/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:16:04 by jarsenio          #+#    #+#             */
/*   Updated: 2021/03/23 16:16:18 by jarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	gnl_lines(int fd, char **line, char **hotline)
{
	int		i;
	char	*temp;

	i = 0;
	while (hotline[fd][i] != '\n' && hotline[fd][i] != '\0')
		i++;
	if (hotline[fd][i] == '\n')
	{
		*line = ft_substrgnl(hotline[fd], 0, i);
		temp = ft_substrgnl(hotline[fd], i + 1, ft_strlengnl(hotline[fd]) - 1);
		free(hotline[fd]);
		hotline[fd] = temp;
		return (1);
	}
	else
	{
		*line = ft_substrgnl(hotline[fd], 0, i);
		free(hotline[fd]);
		hotline[fd] = 0;
		return (0);
	}
}

int	gnl_returns(int fd, char **line, char **hotline, int i)
{
	if (i == -1)
		return (-1);
	if (!hotline[fd] && !i)
	{
		*line = ft_strdupgnl("");
		return (0);
	}
	else
		return (gnl_lines(fd, line, hotline));
}

int	get_next_line(int fd, char **line)
{
	static char		*hotline[10000];
	char			buf[BUFFER_SIZE + 1];
	char			*temp;
	int				i;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	i = read(fd, buf, BUFFER_SIZE);
	while (i > 0)
	{
		buf[i] = '\0';
		if (!hotline[fd])
			hotline[fd] = ft_strdupgnl("");
		temp = ft_strjoingnl(hotline[fd], buf);
		free(hotline[fd]);
		hotline[fd] = temp;
		if (ft_strchrgnl(hotline[fd], '\n'))
			break ;
	}
	return (gnl_returns(fd, line, hotline, i));
}
