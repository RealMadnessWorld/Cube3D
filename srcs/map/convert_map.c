#include "cub3d.h"

void	convert_map(t_data *d)
{
	int	**map;
	int	y;
	int	x;

	map = (int **)malloc(sizeof(int *) * d->map.height);
	y = 0;
	while (d->map.map[y])
	{
		map[y] = (int *)malloc(sizeof(int) * d->map.width);
		x = 0;
		while (d->map.map[y][x])
		{
			// printf("hi\n");
			if (is_char(d->map.map[y][x], " "))
			{
				// printf("space\n");
				map[y][x] = 9;
			}
			else if (is_char(d->map.map[y][x], "NSWE"))
			{
				// printf("position\n");
				map[y][x] = 2;
			}
			else
			{
				// printf("normal\n");
				map[y][x] = d->map.map[y][x] - '0';
			}
			printf("%i", map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	map[y] = NULL;
	d->mapito = map;
}