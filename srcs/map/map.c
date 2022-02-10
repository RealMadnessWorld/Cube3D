#include "cub3d.h"

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
		d->map.map = (char **)malloc(sizeof(char *) * d->map.height);
	else
		d->map.map = (char **)realloc(d->map.map, sizeof(char *) * d->map.height);
}

// void	square_map(t_data *d, int	width)
// {
// 	int	i;

// 	i = -1;
// 	if ((int)ft_strlen(d->map.map[++i]))
// }

void	map_dealer(t_data *d, char *str)
{
	if (!check_chars(str, " 10NEWS"))
		ft_error("Error: Weird symbol in the map...\n");
	if ((int)ft_strlen(str) > d->map.width)
		d->map.width = ft_strlen(str);
	d->map.height += 1;
	start_map(d);
	d->map.map[d->map.height - 1] = ft_strdup(str);
}