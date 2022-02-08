#include "cub3d.h"

int	is_image(char *str)
{
	int	i;

	i = 0;
	if (str[0] == 'N' && str[1] == 'O')
		return (1);
	else if (str[0] == 'S' && str[1] == 'O')
		return (1);
	else if (str[0] == 'W' && str[1] == 'E')
		return (1);
	else if (str[0] == 'E' && str[1] == 'A')
		return (1);
	else
		return (0);
}

int		img_dealer(t_data *d, char *str)
{
	if (!d->map.no_img)
}

void	create_map(char	*map, t_data *d)
{
	int		ret;
	int		fd;
	char	*line;

	fd = open(map, "r");
	ret = get_next_line(fd, &line);
	while(ret == 1)
	{
		if (is_image(line))
			img_dealer(d, line);
	}
}