/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:10:47 by fmeira            #+#    #+#             */
/*   Updated: 2022/04/04 18:13:35 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_rectangle(t_data *d, int x, int y, int color)
{
	int	i;
	int	j;

	x *= d->map.mini_tilesize;
	y *= d->map.mini_tilesize;
	i = 0;
	while (i < d->map.mini_tilesize)
	{
		j = 0;
		while (j < d->map.mini_tilesize)
		{
			if (color)
				d->img.data[(y + i) * WIDTH + x + j] = 0x0000FF;
			else
				d->img.data[(y + i) * WIDTH + x + j] = 0x000000;
			j++;
		}
		i++;
	}
}

int	is_circle(double i, double j, double x, double y)
{
	double	dist;
	double	radius;

	dist = sqrt(powf(j - x, 2.) + powf(i - y, 2.));
	radius = 2;
	if (dist <= radius)
		return (1);
	return (0);
}

static void	draw_plr(t_data *d, double x, double y)
{
	double	i;
	double	j;

	i = 0;
	while (i < d->map.mini_height)
	{
		j = 0;
		while (j < d->map.mini_width)
		{
			if (is_circle(i, j, x, y))
				d->img.data[(int)i * WIDTH + (int)j] = 0xFFFF00;
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	while (i < d->map.height)
	{
		j = 0;
		while (j < d->map.width)
		{
			if (d->mapito[i][j] == 1)
				draw_rectangle(d, j, i, 1);
			else
				draw_rectangle(d, j, i, 0);
			j++;
		}
		i++;
	}
	draw_plr(d, d->posY * d->map.mini_tilesize, d->posX * d->map.mini_tilesize);
}
