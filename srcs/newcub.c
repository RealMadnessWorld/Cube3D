/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newcub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 19:53:20 by yohlee            #+#    #+#             */
/*   Updated: 2022/03/04 00:17:25 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void draw(t_data *info)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			info->img.data[y * WIDTH + x] = info->buf[y][x];
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

int main_loop(t_data *info)
{
	calculate(info);
	draw(info);
	return (0);
}

int main(void)
{
	t_data	info;
	int		i;

	i = 0;
	info = init_data();
	while (i < HEIGHT)
	{
		ft_bzero(info.buf[i++], WIDTH);
	}
	info.texture = (int **)malloc(sizeof(int *) * 8);
	if (!info.texture)
		return (-1);
	i = 0;
	while(i < 8)
	{
		info.texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth));
		if (!(info.texture[i]))
			return (-1);
		ft_bzero(info.texture[i++], texHeight * texWidth);
	}
	load_texture(&info);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 1L<<0, &key_press, &info);
	mlx_loop(info.mlx);
	return (0);
}
