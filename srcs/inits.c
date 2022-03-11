#include "../includes/cub3d.h"

void load_image(t_data *data, int *texture, char *path, t_img *img)
{
	int y;
	int	x;

	y = 0;
	img->img = mlx_xpm_file_to_image(data->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, img->img);
}

void load_texture(t_data *data)
{
	t_img	img;
	int		i;

	i = 0;
	data->texture = (int **)malloc(sizeof(int *) * 8);
	if (!data->texture)
		exit(-1);
	while (i < 8)
	{
		data->texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth));
		if (!(data->texture[i]))
			exit(-1);
		ft_bzero(data->texture[i++], texHeight * texWidth);
	}
	load_image(data, data->texture[0], "textures/eagle.xpm", &img);
	load_image(data, data->texture[1], "textures/redbrick.xpm", &img);
	load_image(data, data->texture[2], "textures/purplestone.xpm", &img);
	load_image(data, data->texture[3], "textures/greystone.xpm", &img);
	load_image(data, data->texture[4], "textures/bluestone.xpm", &img);
	load_image(data, data->texture[5], "textures/mossy.xpm", &img);
	load_image(data, data->texture[6], "textures/wood.xpm", &img);
	load_image(data, data->texture[7], "textures/colorstone.xpm", &img);
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

void	init_data(t_data *data)
{
	init_keys(&data->keys);
	data->dirX = -1.0;
	data->dirY = 0.0;
	data->planeX = 0.0;
	data->planeY = 0.66;
	data->moveSpeed = 0.03;
	data->rotSpeed = 0.03;
	data->map.c_img = NULL;
	data->map.f_img = NULL;
	data->map.no_img = NULL;
	data->map.so_img = NULL;
	data->map.we_img = NULL;
	data->map.ea_img = NULL;
	data->map.width = 0;
	data->map.height = 0;
	data->map.play_x = -1;
	data->map.play_y = -1;
	data->map.play_starts = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "mlx");
	data->img.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->img.data = (int *)mlx_get_data_addr(data->img.img, &data->img.bpp, &data->img.size_l, &data->img.endian);
}
