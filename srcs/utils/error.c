/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:07:08 by jarsenio          #+#    #+#             */
/*   Updated: 2022/04/05 20:46:57 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_err(t_data *d, char *error)
{
	ft_putstr_fd(error, 1);
	write(1, "\n", 1);
	be_free(d);
	exit (EXIT_FAILURE);
}

char	*check_img_path(char *path, t_data *d)
{
	if (open((path), O_RDONLY) < 0)
		ft_err(d, CLR_RED "You're lacking the images... focus please\n" CLR_RST);
	return (path);
}

void	check_invalid_line(char *str, t_data *d)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] && ft_isalpha(str[i]))
		ft_err(d, "Error: invalid data provided");
	else if (str[i] && !ready_to_map(d))
		ft_err(d, "Error: invalid data provided");
}
