/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:37:06 by fmeira            #+#    #+#             */
/*   Updated: 2022/04/04 20:43:22 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_textures(t_data *d)
{
	d->map.no_img = (int *)malloc(sizeof(int) * (TEXHEIGHT * TEXWIDTH));
	if (!(d->map.no_img))
		exit(-1);
	ft_be_minus_one(d->map.no_img, TEXHEIGHT * TEXWIDTH);
	d->map.so_img = (int *)malloc(sizeof(int) * (TEXHEIGHT * TEXWIDTH));
	if (!(d->map.so_img))
		exit(-1);
	ft_be_minus_one(d->map.so_img, TEXHEIGHT * TEXWIDTH);
	d->map.we_img = (int *)malloc(sizeof(int) * (TEXHEIGHT * TEXWIDTH));
	if (!(d->map.we_img))
		exit(-1);
	ft_be_minus_one(d->map.we_img, TEXHEIGHT * TEXWIDTH);
	d->map.ea_img = (int *)malloc(sizeof(int) * (TEXHEIGHT * TEXWIDTH));
	if (!(d->map.ea_img))
		exit(-1);
	ft_be_minus_one(d->map.ea_img, TEXHEIGHT * TEXWIDTH);
}

char	*get_path(t_data *d, char *path)
{
	int		i;

	i = 0;
	while (path[i])
	{
		if (path[i] == '.')
			return (&(path[i]));
		i++;
	}
	ft_err(d, "Error: Missing path to texture");
	return (NULL);
}

void	load_image(t_data *d, int *texture, char *path, t_img *img)
{
	int		y;
	int		x;
	char	*newpath;
	char	*(*norm)(void *, int *, int *, int *);

	norm = &mlx_get_data_addr;
	y = 0;
	newpath = get_path(d, path);
	chk_img_path(newpath);
	if (!find_extention(newpath, ".xpm"))
		ft_err(d, "Error: not a \".xpm\" file");
	img->img = mlx_xpm_file_to_image(d->mlx, newpath, &img->img_w, &img->img_h);
	img->data = (int *)(*norm)(img->img, &img->b, &img->size_l, &img->e);
	while (y < img->img_h)
	{
		x = 0;
		while (x < img->img_w)
		{
			texture[img->img_w * y + x] = img->data[img->img_w * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(d->mlx, img->img);
}

void	init_keys(t_keys *keys)
{
	keys->key_w = 0;
	keys->key_s = 0;
	keys->key_a = 0;
	keys->key_d = 0;
	keys->key_esc = 0;
	keys->key_right = 0;
	keys->key_left = 0;
}

void	init_data(t_data *d)
{
	char	*(*norm)(void *, int *, int *, int *);

	norm = &mlx_get_data_addr;
	ft_bzero(d, sizeof(*d));
	d->empty = 0;
	d->dirX = -1.0;
	d->planeY = 0.66;
	d->moveSpeed = 0.06;
	d->rotSpeed = 0.03;
	init_keys(&d->keys);
	init_textures(d);
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, "mlx");
	d->img.img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->img.data = (int *)norm(d->img.img, &d->img.b, &d->img.size_l, 	&d->img.e);
}
