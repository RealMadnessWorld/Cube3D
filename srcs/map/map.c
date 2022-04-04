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
	int		i;
	char	**tmp;

	if (!d->map.map)
	{
		d->map.map = (char **)malloc(sizeof(char *) * (d->map.height + 1));
		if (!d->map.map)
			ft_err(d, "Malloc failed! U did the impossible! Good for you!");
		return ;
	}
	tmp = (char **)malloc(sizeof(char *) * (d->map.height + 1));
	if (!tmp)
		ft_err(d, "Malloc failed! U did the impossible! Good for you!");
	i = 0;
	while(d->map.map[i])
	{
		tmp[i] = ft_strdup(d->map.map[i]);
		free(d->map.map[i]);
		i++;
	}
	free(d->map.map);
	d->map.map = tmp;
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
}

char	*clean_tabs(char *str, int tabs)
{
	char	*tmp;
	int		i;
	int		j;
	int		x;

	tmp =(char *)ft_calloc(((ft_strlen(str) + (tabs * 3)) + 1), sizeof(char));
	i = -1;
	j = 0;
	if (!tmp)
		return (NULL);
	while (str[++i])
	{
		if (str[i] == '\t')
		{
			x = 0;
			while (x < 4)
				tmp[(i + (3 * j)) + x++] = ' ';
			j++;
		}
		else
			tmp[i + (3 * j)] = str[i];
	}
	return (tmp);
}

char	*fix_tabs(char *str, int *ref)
{
	int		i;
	char	*new;
	int		tab;

	i = -1;
	tab = 0;
	new = str;
	if (!str)
		return (NULL);
	while (str[++i])
	{
		if (str[i] == '\t')
			tab++;
	}
	if (tab)
	{
		*ref = 1;
		new = clean_tabs(str, tab);
	}
	return (new);
}

void	map_dealer(t_data *d, char *str)
{
	int	tabs;

	tabs = 0;
	if (d->empty > 0 && !is_empty(str))
		ft_err(d, "empty line in the middle of the map?");
	if (is_empty(str))
	{
		if (d->map.map)
			d->empty = 1;
		return ;
	}
	if (!check_chars(str, "	 10NEWS"))
		ft_err(d, "Error: Weird symbol in the map...\n");
	str = fix_tabs(str, &tabs);
	if ((int)ft_strlen(str) > d->map.width)
		d->map.width = (int)ft_strlen(str);
	d->map.height += 1;
	start_map(d);
	d->map.map[d->map.height - 1] = ft_strdup(str);
	if (tabs)
		free(str);
	d->map.map[d->map.height] = NULL;
}
