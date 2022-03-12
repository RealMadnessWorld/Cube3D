#include "../../includes/cub3d.h"

int	is_image(char *str)
{
	if (str[0] == 'N' && str[1] == 'O')
		return (1);
	else if (str[0] == 'S' && str[1] == 'O')
		return (1);
	else if (str[0] == 'W' && str[1] == 'E')
		return (1);
	else if (str[0] == 'E' && str[1] == 'A')
		return (1);
	else if (str[0] == 'C')
		return (1);
	else if (str[0] == 'F')
		return (1);
	else
		return (0);
}

static int	*save_color(t_data *d, char *str)
{
	char	**split;
	int		*colors;
	int		i;

	i = 0;
	split = ft_split(str, ',');
	if (split[3])
		ft_err(d, "Error: Colors have 3 elements (R, G, B)");
	colors = (int *)malloc(sizeof(int) * 3);
	while (i < 3)
	{
		colors[i] = ft_atoi(split[i]);
		if (colors[i] < 0 || colors[i] > 255)
			ft_err(d, "Error: Color range must be between 0 and 255");
		free(split[i]);
		i++;
	}
	return (colors);
}

static void	color_saver(t_data *d, int **save, char *str)
{
	int		i;
	char	*idk;

	i = 2;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ',')
			ft_err(d, "Error: Colors are made of numbers... weird I know!");
		i++;
	}
	if (!*save)
	{
		idk = ft_strchr(str, str[2]);
		*save = save_color(d, idk);
	}
	else
		ft_err(d, "Error: twice the same color for roof or floor? 🤔");
}

void	img_dealer(t_data *d, char *str)
{
	t_img	img;

	if (str[0] == 'N')
		load_image(d, d->map.no_img, (str), &img);
	else if (str[0] == 'S')
		load_image(d, d->map.so_img, (str), &img);
	else if (str[0] == 'W')
		load_image(d, d->map.we_img, (str), &img);
	else if (str[0] == 'E')
		load_image(d, d->map.ea_img, (str), &img);
	else if (str[0] == 'F')
		color_saver(d, &d->map.f_color, str);
	else if (str[0] == 'C')
		color_saver(d, &d->map.c_color, str);
	else
		ft_err(d, "Error: Please use a valid identifier (NO,SO,WE,EA,C,F)");
}

void	create_map(char	*map, t_data *d)
{
	int		ret;
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	ret = 1;
	while(ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (is_image(line))
			img_dealer(d, line);
		else if (ready_to_map(d))
			map_dealer(d, line);
	}
	square_map(d, d->map.width);
	map_closed(d, d->map.map);
	verify(d);
}
