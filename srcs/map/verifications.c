#include "cub3d.h"

int	zero_surr(char **map, int x, int y)
{
	if (is_char(map[y][x], "0NSEW"))
	{
		if (!is_char(map[y - 1][x], "10NSEW"))
			return (0);
		if (!is_char(map[y + 1][x], "10NSEW"))
			return (0);
		if (!is_char(map[y][x - 1], "10NSEW"))
			return (0);
		if (!is_char(map[y][x + 1], "10NSEW"))
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
				ft_error("Map not closed. You can't trick me! I am machine!!\n");
			if (is_char(map[y][x], "EWSN"))
			{
				if (d->map.play_x == -1 && d->map.play_y == -1)
				{
					d->map.play_x = x;
					d->map.play_y = y;
				}
				else
					ft_error("this is a single player game. That means ONE starting position\n");
			}
			x++;
		}
		y++;
	}
}