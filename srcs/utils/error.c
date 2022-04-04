/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:07:08 by jarsenio          #+#    #+#             */
/*   Updated: 2022/04/04 18:07:10 by jarsenio         ###   ########.fr       */
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
