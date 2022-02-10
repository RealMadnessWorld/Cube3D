#include "cub3d.h"

void	free_map(t_data *d)
{
	int	i;

	i = 0;
	while (d->map.map[i])
		free(d->map.map[i]);
	free(d->map.map);
	free(d->map.no_img);
	free(d->map.so_img);
	free(d->map.we_img);
	free(d->map.ea_img);
	free(d->map.c_img);
	free(d->map.f_img);
}

void	be_free(t_data *d)
{
	free_map(d);
}