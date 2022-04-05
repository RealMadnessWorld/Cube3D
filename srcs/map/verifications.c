/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifications.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:39:47 by jarsenio          #+#    #+#             */
/*   Updated: 2022/04/05 17:28:21 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	all_ones(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
	{
		if (str[i] != '1' || str[i] != ' ')
			return (0);
	}
	return (1);
}

int	zero_surr(char **map, int x, int y)
{
	if (is_char(map[y][x], "0NSEW"))
	{
		if (map[y - 1])
			ret_error(map, x, y - 1);
		else if (!all_ones(map[y]))
			return (0);
		if (map[y + 1])
			ret_error(map, x, y + 1);
		else if (!all_ones(map[y]))
			return (0);
		if (map[y][x - 1])
			ret_error(map, x - 1, y);
		if (map[y][x + 1])
			ret_error(map, x + 1, y);
	}
	return (1);
}

int	check_texture_identifier(t_data *d, char *path)
{
	if (ft_strncmp(path, "NO", 2) != 0 && ft_strncmp(path, "SO", 2) != 0
		&& ft_strncmp(path, "WE", 2) != 0 && ft_strncmp(path, "EA", 2) != 0)
	{
		if (path[2] == '1' || path[2] == '0')
			ft_err(d, "Error: Player must not be on map borders");
		ft_err(d, "Error: Bad texture identifier. Use 'NO' 'SO' 'WE' 'EA'");
		return (0);
	}
	if (*(path + 2) != ' ' && *(path + 2) != '	')
	{
		ft_err(d, "Error: Bad configuration of texture identifier");
		return (0);
	}
	return (1);
}

void	map_closed(t_data *d, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (is_char(map[y][x], "0EWSN") && !zero_surr(map, x, y))
				ft_err(d, "Map not closed. You can't trick me! I am machine!!");
			x++;
		}
		y++;
	}
}

void	verify(t_data *d)
{
	if ((*d->map.ea_img) == -1 || (*d->map.so_img) == -1
		|| (*d->map.we_img) == -1 || (*d->map.no_img) == -1)
		ft_err(d, "Error: Missing texture(s)");
	else if (!d->map.c_clr || !d->map.f_clr)
		ft_err(d, "Error: Missing color(s)");
	else if (!d->map.map)
		ft_err(d, "Error: Where's the map?");
}
