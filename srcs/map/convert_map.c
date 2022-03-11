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
			{
				set_player(d, y, x, d->map.map[x][y]);
				newmap[x][y] = 0;
			}
			else
				newmap[x][y] = d->map.map[x][y] - '0';
			y++;
		}
		x++;
	}
	newmap[x] = NULL;
	d->mapito = newmap;
}
