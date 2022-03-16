#include "cub3d.h"

void	free_map(t_data *d)
{
	int	i;

	i = 0;
	if (d && &d->map)
	{
		if (d->map.map)
		{
			while (d->map.map[i])
				free(d->map.map[i++]);
			free(d->map.map);
		}
		if (d->map.c_color)
			free(d->map.c_color);
		if (d->map.f_color)
			free(d->map.f_color);
		if (d->map.no_img)
			free(d->map.no_img);
		if (d->map.so_img)
			free(d->map.so_img);
		if (d->map.we_img)
			free(d->map.we_img);
		if (d->map.ea_img)
			free(d->map.ea_img);
	}
}

void	be_free(t_data *d)
{
	free_map(d);
}
