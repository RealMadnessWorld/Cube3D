/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newcub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:53:20 by yohlee            #+#    #+#             */
/*   Updated: 2022/03/12 19:53:18 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void draw(t_data *d)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			d->img.data[y * WIDTH + x] = d->buf[y][x++];
		y++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img.img, 0, 0);
}

int main_loop(t_data *d)
{
	calculate(d);
	draw(d);
	key_hook(d);
	return (0);
}

int main(int argc, char **argv)
{
	t_data	d;
	int		i;

	i = 0;
	if (argc != 2)
		ft_error("Error: I need a map. And one map only!\n");
	init_data(&d);
	load_textures(&d);
	create_map(argv[1], &d);
	convert_map(&d);
	while (i < HEIGHT)
		ft_bzero(d.buf[i++], WIDTH);
	mlx_loop_hook(d.mlx, &main_loop, &d);
	mlx_hook(d.win, X_EVENT_KEY_PRESS, 1L<<0, &key_press, &d);
	mlx_hook(d.win, KEYRELEASE, 1L<<1, &key_release, &d);
	mlx_hook(d.win, 17, 1L << 17, &finish, &d);
	mlx_loop(d.mlx);
	return (0);
}
