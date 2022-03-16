#include "../../includes/cub3d.h"

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

int	check_texture_identifier(t_data *d, char *path)
{
	if (ft_strncmp(path, "NO", 2) != 0 && ft_strncmp(path, "SO", 2) != 0
		&& ft_strncmp(path, "WE", 2) != 0 && ft_strncmp(path, "EA", 2) != 0)
	{
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
				ft_err(d, "Map not closed. You can't trick me! I am machine!!\n");
			if (is_char(map[y][x], "EWSN"))
			{
				if (d->map.play_x == -1 && d->map.play_y == -1)
				{
					d->map.play_x = x;
					d->map.play_y = y;
				}
				else
					ft_err(d, "this is a single player game. That means ONE starting position\n");
			}
			x++;
		}
		printf("aqui\n");
		y++;
	}
}
