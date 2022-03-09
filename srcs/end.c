#include "../includes/cub3d.h"

// static void	free_data(t_data *data)
// {
// 	if (data)
// 	{
// 		if (data->map)
// 		{
// 			while (data->y_size >= 0)
// 				free(data->map[data->y_size--]);
// 		}
// 		free(data->map);
// 		data = NULL;
// 	}
// }

// void	die(t_data *data, char *message)
// {
// 	free_struct(data);
// 	terminate(message);
// }

int	finish(t_data *data)
{
	// free_data(data);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (1);
}
