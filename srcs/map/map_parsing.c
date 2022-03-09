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

void	color_saver(t_data *d, char **save, char *str)
{
	int		i;
	char	*idk;

	i = 2;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ',')
			ft_err(d, "Error: Colors are made of numbers... weird I know!\n");
		i++;
	}
	if (!*save)
	{
		idk = ft_strchr(str, str[2]);
		*save = ft_strdup(ft_strnstr(str, idk, ft_strlen(str)));
	}
	else
		ft_err(d, "Error: twice the same color for roof or floor? 🤔\n");
}

void	img_saver(t_data *d, char **save, char *str)
{
	if (!*save)
		*save = ft_strdup(ft_strnstr(str, "./", ft_strlen(str)));
	else
		ft_err(d, "Error: twice the same image direction? 🤔\n");
	chk_img_path(*save);
}

void	img_dealer(t_data *d, char *str)
{
	if (str[0] == 'N' && str[1] == 'O')
		img_saver(d, &d->map.no_img, str);
	if (str[0] == 'S' && str[1] == 'O')
		img_saver(d, &d->map.so_img, str);
	if (str[0] == 'W' && str[1] == 'E')
		img_saver(d, &d->map.we_img, str);
	if (str[0] == 'E' && str[1] == 'A')
		img_saver(d, &d->map.ea_img, str);
	if (str[0] == 'F')
		color_saver(d, &d->map.f_img, str);
	if (str[0] == 'C')
		color_saver(d, &d->map.c_img, str);
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
	d->map.map[d->map.height] = NULL;
	square_map(d, d->map.width);
	map_closed(d, d->map.map);
	verify(d);
}
