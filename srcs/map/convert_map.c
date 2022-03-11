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

void	convert_map(t_data *d)
{
	int	**newmap;
	int	y;
	int	x;

	newmap = (int **)malloc(sizeof(int *) * d->map.height);
	y = 0;
	while (d->map.map[y])
	{
		newmap[y] = (int *)malloc(sizeof(int) * d->map.width);
		x = 0;
		while (d->map.map[y][x])
		{
			if (is_char(d->map.map[y][x], " "))
				newmap[y][x] = 9;
			else if (is_char(d->map.map[y][x], "NSWE"))
			{
				set_player(d, y, x, d->map.map[y][x]);
				newmap[y][x] = 0;
			}
			else
				newmap[y][x] = d->map.map[y][x] - '0';
			x++;
		}
		y++;
	}
	newmap[y] = NULL;
	d->mapito = newmap;
}
