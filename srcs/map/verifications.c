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
			x++;
		}
		y++;
	}
}

void	verify(t_data *d)
{
	printf ("no %d\n", *d->map.no_img);
	printf ("so %d\n", *d->map.so_img);
	printf ("we %d\n", *d->map.we_img);
	printf ("ea %d\n", *d->map.ea_img);

	if ((*d->map.ea_img) == -1 || (*d->map.so_img) == -1
			|| (*d->map.we_img) == -1 || (*d->map.no_img) == -1)
		ft_err(d, "Error: Missing texture(s)\n");
	else if (!d->map.c_color || !d->map.f_color)
		ft_err(d, "Error: Missing color(s)\n");
	else if (!d->map.map)
		ft_err(d, "Error: Where's the map?\n");
}
