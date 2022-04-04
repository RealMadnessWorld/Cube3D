/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:07:24 by jarsenio          #+#    #+#             */
/*   Updated: 2022/04/04 18:54:07 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_data *d)
{
	int	i;

	i = 0;
	if (d->map.map)
	{
		while (i < d->map.height)
			free(d->map.map[i++]);
		free(d->map.map);
	}
}

void	be_free(t_data *d)
{
	if (d->map.c_clr)
		free(d->map.c_clr);
	if (d->map.f_clr)
		free(d->map.f_clr);
	if (d->map.no_img)
		free(d->map.no_img);
	if (d->map.so_img)
		free(d->map.so_img);
	if (d->map.we_img)
		free(d->map.we_img);
	if (d->map.ea_img)
		free(d->map.ea_img);
	free_map(d);
}
