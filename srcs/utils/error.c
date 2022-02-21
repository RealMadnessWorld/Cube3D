#include "cub3d.h"

void	ft_err(t_data *d, char *error)
{
	ft_putstr_fd(error, 1);
	write(1, "\n", 1);
	be_free(d);
	exit (EXIT_FAILURE);
}
