/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newcub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:53:20 by yohlee            #+#    #+#             */
/*   Updated: 2022/03/11 00:03:55 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

	i = 0;
	if (argc != 2)
		ft_error("Error: I need a map. And one map only!\n");
	init_data(&data);
	create_map(argv[1], &data);
	convert_map(&data);
	// print_map_shit(&data);
	while (i < HEIGHT)
		ft_bzero(data.buf[i++], WIDTH);
	load_texture(&data);
	mlx_loop_hook(data.mlx, &main_loop, &data);
	mlx_hook(data.win, X_EVENT_KEY_PRESS, 1L<<0, &key_press, &data);
	mlx_hook(data.win, KEYRELEASE, 1L<<1, &key_release, &data);
	mlx_hook(data.win, 17, 1L << 17, &finish, &data);
	mlx_loop(data.mlx);
	return (0);
}
