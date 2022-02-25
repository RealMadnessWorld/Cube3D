/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:19:17 by jarsenio          #+#    #+#             */
/*   Updated: 2021/05/05 19:19:20 by jarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int main(int argc, char **argv)
{
	t_data d;

	if (argc != 2)
		ft_err(&d, "Error: I need a map. And one map only!\n");
	vars_init(&d);
	create_map(argv[1], &d);
	d.cube = mlx_init();
	d.window = mlx_new_window(d.cube, 600, 600, "\"fuck you\" that's my name");
	d.img = mlx_new_image(d.cube, 600, 600);
	d.addr = mlx_get_data_addr(d.img, &d.bits_per_pixel, &d.line_lenght, &d.endian);
	print_map_shit(&d);
	mlx_loop_hook(d.cube, &visuals, &d);
	mlx_hook(d.window, X_EVENT_KEY_EXIT, 0, &x_click, &d);
	mlx_loop(d.cube);
}





// int main(int argc, char **argv)
// {
// 	void *cube;
// 	void *cube_window;
// 	t_data img;

// 	my_mlx_pixel_puta(&img, 300, 300, 0x00FF0000);
// 	mlx_put_image_to_window(cube, cube_window, d.img, 0, 0);
// 	printf("hi\n");
// }