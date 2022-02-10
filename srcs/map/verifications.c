#include "cub3d.h"

void	verify(t_data *d)
{
	if (!d->map.c_img || !d->map.f_img || !d->map.no_img ||
	!d->map.so_img || !d->map.we_img || !d->map.ea_img)
		ft_error("Error: Missing some image");
}
