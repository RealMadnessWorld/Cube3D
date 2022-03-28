#include "../../includes/cub3d.h"

int	check_chars(char *str, char *chars)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (str[i])
	{
		j = 0;
		flag = 0;
		while (chars[j])
		{
			if (chars[j] == str[i])
				flag = 1;
			j++;
		}
		if (flag != 1)
			return (0);
		i++;
	}
	return (1);
}

void	start_map(t_data *d)
{
	if (!d->map.map)
		d->map.map = (char **)malloc(sizeof(char *) * d->map.height + 1);
	else
		d->map.map = (char **)realloc(d->map.map, sizeof(char *) * d->map.height + 1);
}

void	square_map(t_data *d, int width)
{
	int	i;
	int	j;

	i = 0;
	while(i < d->map.height)
	{
		j = (int)ft_strlen(d->map.map[i]);
		if (j < width)
		{
			d->map.map[i] = realloc(d->map.map[i], width + 1);
			while (j != width)
				d->map.map[i][j++] = ' ';
		}
		d->map.map[i][j] = '\0';
		i++;
	}
	d->map.map[i] = NULL;
}

void	map_dealer(t_data *d, char *str)
{
	if (is_empty(str))
		return ;
	if (!check_chars(str, "	 10NEWS"))
		ft_err(d, "Error: Weird symbol in the map...\n");
	if ((int)ft_strlen(str) > d->map.width)
		d->map.width = (int)ft_strlen(str);
	d->map.height += 1;
	start_map(d);
	d->map.map[d->map.height - 1] = ft_strdup(str);
}
