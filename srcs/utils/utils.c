#include "cub3d.h"

int	is_char(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	verify(t_data *d)
{
	if (!d->map.c_color || !d->map.f_color || !d->texture[0] ||
	!d->texture[1] || !d->texture[2] || !d->texture[3])
		ft_err(d, "Error: Missing some image\n");
	if (d->map.play_x == -1 || d->map.play_y == -1)
		ft_err(d, "Error: Missing player starting point\n");
}

int	ready_to_map(t_data *d)
{
	if (d->map.c_color && d->map.f_color && d->texture[0] &&
	d->texture[1] && d->texture[2] && d->texture[3])
		return (1);
	return (0);
}
