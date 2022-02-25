#include "cub3d.h"

//y1 = drawStart
//y2 = drawEnd

void    my_mlx_pixel_puta(t_data *img, int y, int x, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_lenght + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ver_line(t_calc *c, t_data *d, int x)
{
	int	y;

	y = c->drawStart;
	while (y <= c->drawEnd)
	{
		mlx_pixel_put(d->cube, d->window, x, y, c->color);
		y++;
	}
}

int	visuals(t_data *d)
{
	calcs(d);
	return (0);
}