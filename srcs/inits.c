#include "../includes/cub3d.h"

void init_textures(t_data *d)
{
	d->map.no_img = (int *)malloc(sizeof(int) * (texHeight * texWidth));
	if (!(d->map.no_img))
		exit(-1);
	ft_be_minus_one(d->map.no_img, texHeight * texWidth);
	d->map.so_img = (int *)malloc(sizeof(int) * (texHeight * texWidth));
	if (!(d->map.so_img))
		exit(-1);
	ft_be_minus_one(d->map.so_img, texHeight * texWidth);
	d->map.we_img = (int *)malloc(sizeof(int) * (texHeight * texWidth));
	if (!(d->map.we_img))
		exit(-1);
	ft_be_minus_one(d->map.we_img, texHeight * texWidth);
	d->map.ea_img = (int *)malloc(sizeof(int) * (texHeight * texWidth));
	if (!(d->map.ea_img))
		exit(-1);
	ft_be_minus_one(d->map.ea_img, texHeight * texWidth);
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

void load_image(t_data *d, int *texture, char *path, t_img *img)
{
	int		y;
	int		x;
	char	*truePath;

	y = 0;
	truePath = get_path(d, path);
	chk_img_path(truePath);
	if (!find_extention(truePath, ".xpm"))
		ft_err(d, "Error: not a \".xpm\" file");
	img->img = mlx_xpm_file_to_image(d->mlx, truePath, &img->img_width, &img->img_height);
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
	d->empty = 0;
	d->map.map = NULL;
	d->dirX = -1.0;
	d->dirY = 0.0;
	d->posX = 0;
	d->posY = 0;
	d->planeX = 0.0;
	d->planeY = 0.66;
	d->moveSpeed = 0.06;
	d->rotSpeed = 0.03;
	d->map.c_color = NULL;
	d->map.f_color = NULL;
	d->map.no_img = NULL;
	d->map.so_img = NULL;
	d->map.we_img = NULL;
	d->map.ea_img = NULL;
	d->map.width = 0;
	d->map.height = 0;
	d->map.play_starts = 0;
	init_keys(&d->keys);
	init_textures(d);
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, "mlx");
	d->img.img = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->img.data = (int *)mlx_get_data_addr(d->img.img, &d->img.bpp, &d->img.size_l, &d->img.endian);
}
