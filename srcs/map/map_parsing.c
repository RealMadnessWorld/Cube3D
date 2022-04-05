/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:39:28 by jarsenio          #+#    #+#             */
/*   Updated: 2022/04/05 18:54:20 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_image(t_data *d, char *str)
{
	if ((str[0] == 'N' || str[0] == 'S' || str[0] == 'E' || str[0] == 'W')
		&& check_texture_identifier(d, str))
		return (1);
	else if (str[0] == 'C')
	{
		if (*(str + 1) != ' ' && *(str + 1) != '	')
			ft_err(d, "Error: Bad configuration of C color parameter");
		return (1);
	}
	else if (str[0] == 'F')
	{
		if (*(str + 1) != ' ' && *(str + 1) != '	')
			ft_err(d, "Error: Bad configuration of F color parameter");
		return (1);
	}
	else if (str[0] != '1' && str[0] != '0' && str[0] != 32
		&& str[0] != 9 && str[0] != 10 && str[0] != 0)
		ft_err(d, "Error: Invalid data/file provided");
	return (0);
}

static int	*save_color(t_data *d, char *str)
{
	char	**split;
	int		*colors;
	int		i;
	int		badrange;

	split = ft_split(str, ',');
	i = 0;
	badrange = 0;
	if (split[3])
		ft_err(d, "Error: Colors have 3 elements (R, G, B)");
	colors = (int *)malloc(sizeof(int) * 3);
	while (i < 3)
	{
		colors[i] = ft_atoi(split[i]);
		free(split[i]);
		if (colors[i] < 0 || colors[i] > 255)
			badrange = 1;
		i++;
	}
	free(split);
	if (badrange)
		ft_err(d, "Error: Color range must be between 0 and 255");
	return (colors);
}

static void	color_saver(t_data *d, int **save, char *str)
{
	int		i;
	char	*idk;

	i = 2;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ',' && str[i] != ' '
			&& str[i] != '	')
			ft_err(d, "Error: Colors are made of positive numbers");
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

	if (d->map.map)
		ft_err(d, "Error: textures must be initialized before the map");
	if (str[0] == 'N')
		load_image(d, d->map.no_img, str, &img);
	else if (str[0] == 'S')
		load_image(d, d->map.so_img, str, &img);
	else if (str[0] == 'W')
		load_image(d, d->map.we_img, str, &img);
	else if (str[0] == 'E')
		load_image(d, d->map.ea_img, str, &img);
	else if (str[0] == 'F')
		color_saver(d, &d->map.f_clr, str);
	else if (str[0] == 'C')
		color_saver(d, &d->map.c_clr, str);
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
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (is_image(d, line))
			img_dealer(d, line);
		else if (ready_to_map(d))
			map_dealer(d, line);
		free(line);
	}
	verify(d);
	square_map(d, d->map.width);
	map_closed(d, d->map.map);
	convert_map(d);
	if (!d->posx || !d->posy)
		ft_err(d, "Error: Missing player starting point");
	d->map.mini_tilesize = 320 / (d->map.width + d->map.height);
	d->map.mini_width = d->map.width * d->map.mini_tilesize;
	d->map.mini_height = d->map.height * d->map.mini_tilesize;
	close(fd);
}
