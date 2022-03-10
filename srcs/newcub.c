/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newcub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:53:20 by yohlee            #+#    #+#             */
/*   Updated: 2022/03/09 19:16:28 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	vars_init(t_data *d)
{
	d->map.c_img = NULL;
	d->map.f_img = NULL;
	d->map.no_img = NULL;
	d->map.so_img = NULL;
	d->map.we_img = NULL;
	d->map.ea_img = NULL;
	d->map.width = 0;
	d->map.height = 0;
	d->map.play_x = -1;
	d->map.play_y = -1;
	d->map.play_starts = 0;
}

static void draw(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			data->img.data[y * WIDTH + x] = data->buf[y][x++];
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

int main_loop(t_data *data)
{
	calculate(data);
	draw(data);
	key_hook(data);
	return (0);
}

int main(int argc, char **argv)
{
	t_data	data;
	int		i;

	if (argc != 2)
		ft_error("Error: I need a map. And one map only!\n");
	i = 0;
	vars_init(&data);
	create_map(argv[1], &data);
	convert_map(&data);
	print_map_shit(&data);
	data = init_data();
	printf("C\n");
	while (i < HEIGHT)
		ft_bzero(data.buf[i++], WIDTH);
	data.texture = (int **)malloc(sizeof(int *) * 8);
	if (!data.texture)
		return (-1);
	i = 0;
	while(i < 8)
	{
		data.texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth));
		if (!(data.texture[i]))
			return (-1);
		ft_bzero(data.texture[i++], texHeight * texWidth);
	}
	load_texture(&data);
	mlx_loop_hook(data.mlx, &main_loop, &data);
	mlx_hook(data.win, X_EVENT_KEY_PRESS, 1L<<0, &key_press, &data);
	mlx_hook(data.win, KEYRELEASE, 1L<<1, &key_release, &data);
	mlx_hook(data.win, 17, 1L << 17, &finish, &data);
	mlx_loop(data.mlx);
	return (0);
}
