// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   cub3d.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/05/05 19:19:17 by jarsenio          #+#    #+#             */
// /*   Updated: 2022/02/14 20:01:47 by fmeira           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "cub3d.h"

// void	vars_init(t_data *d)
// {
// 	d->map.c_color = NULL;
// 	d->map.f_color = NULL;
// 	d->map.no_img = NULL;
// 	d->map.so_img = NULL;
// 	d->map.we_img = NULL;
// 	d->map.ea_img = NULL;
// 	d->map.width = 0;
// 	d->map.height = 0;
// 	d->map.play_x = -1;
// 	d->map.play_y = -1;
// 	d->map.play_starts = 0;
// }

// // int main(int argc, char **argv)
// // {
// // 	t_data d;

// // 	if (argc != 2)
// // 		ft_error("Error: I need a map. And one map only!\n");
// // 	vars_init(&d);
// // 	create_map(argv[1], &d);
// // 	print_map_shit(&d);
// // }



// void    my_mlx_pixel_puta(t_data *img, int y, int x, int color)
// {
// 	char *dst;

// 	dst = img->addr + (y * img->line_lenght + x * (img->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// int main(void)
// {
// 	void *cube;
// 	void *cube_window;
// 	t_data img;

// 	cube = mlx_init();
// 	cube_window = mlx_new_window(cube, 600, 600, "fuck you that's my name");
// 	img.img = mlx_new_image(cube, 600, 600);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
// 	my_mlx_pixel_puta(&img, 300, 300, 0x00FF0000);
// 	mlx_put_image_to_window(cube, cube_window, img.img, 0, 0);
// 	mlx_loop(cube);
// 	printf("hi\n");
// }
