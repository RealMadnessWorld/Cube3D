/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newcub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:53:20 by yohlee            #+#    #+#             */
/*   Updated: 2022/03/09 01:25:09 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void draw(t_data *data)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			data->img.data[y * WIDTH + x] = data->buf[y][x];
		}
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
	data = init_data();
	while (i < HEIGHT)
	{
		ft_bzero(data.buf[i++], WIDTH);
	}
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
