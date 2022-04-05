/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:39:07 by jarsenio          #+#    #+#             */
/*   Updated: 2022/04/04 22:31:22 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_player(t_data *d, int y, int x, char c)
{
	d->posX = (double)x + 0.5;
	d->posY = (double)y + 0.5;
	if (c == 'S')
		rotate(1, d, S_DIR);
	else if (c == 'E')
		rotate(1, d, E_DIR);
	else if (c == 'W')
		rotate(1, d, W_DIR);
}

static void	p_pos_err(t_data *d, int y, int x, int **newmap)
{
	if (d->posX && d->posY)
		ft_err(d, "this is a single player game. ONE starting position");
	set_player(d, y, x, d->map.map[x][y]);
	newmap[x][y] = 0;
}

void	convert_map(t_data *d)
{
	int	**newmap;
	int	x;
	int	y;

	newmap = (int **)malloc(sizeof(int *) * d->map.height);
	x = 0;
	while (d->map.map[x])
	{
		newmap[x] = (int *)malloc(sizeof(int) * d->map.width);
		y = 0;
		while (d->map.map[x][y])
		{
			if (is_char(d->map.map[x][y], " "))
				newmap[x][y] = 9;
			else if (is_char(d->map.map[x][y], "NSWE"))
				p_pos_err(d, y, x, newmap);
			else
				newmap[x][y] = d->map.map[x][y] - '0';
			y++;
		}
		x++;
	}
	if (!d->posX || !d->posY)
		ft_err(d, "Error: Missing player starting point");
	d->mapito = newmap;
}

void	map_dealer(t_data *d, char *str)
{
	int	tabs;

	tabs = 0;
	if (d->empty > 0 && !is_empty(str))
		ft_err(d, "empty line in the middle of the map?");
	if (is_empty(str))
	{
		if (d->map.map)
			d->empty = 1;
		return ;
	}
	if (!check_chars(str, "	 10NEWS"))
		ft_err(d, "Error: Weird symbol in the map...");
	str = fix_tabs(str, &tabs);
	if ((int)ft_strlen(str) > d->map.width)
		d->map.width = (int)ft_strlen(str);
	d->map.height += 1;
	start_map(d);
	d->map.map[d->map.height - 1] = ft_strdup(str);
	if (tabs)
		free(str);
	d->map.map[d->map.height] = NULL;
}
