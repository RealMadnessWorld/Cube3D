/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:14:05 by fmeira            #+#    #+#             */
/*   Updated: 2022/04/04 18:15:13 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	move(int direction, t_data *d)
{
	if (direction == 1)
	{
		if (!d->mapito[(int)(d->posX + d->dirX * d->moveSpeed)][(int)(d->posY)])
			d->posX += d->dirX * d->moveSpeed;
		if (!d->mapito[(int)(d->posX)][(int)(d->posY + d->dirY * d->moveSpeed)])
			d->posY += d->dirY * d->moveSpeed;
	}
	else if (direction == -1)
	{
		if (!d->mapito[(int)(d->posX - d->dirX * d->moveSpeed)][(int)(d->posY)])
			d->posX -= d->dirX * d->moveSpeed;
		if (!d->mapito[(int)(d->posX)][(int)(d->posY - d->dirY * d->moveSpeed)])
			d->posY -= d->dirY * d->moveSpeed;
	}
}

void	rotate(int direction, t_data *d, double rotSpeed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = d->dirX;
	old_plane_x = d->planeX;
	if (direction == 1)
	{
		d->dirX = d->dirX * cos(-rotSpeed) - d->dirY * sin(-rotSpeed);
		d->dirY = old_dir_x * sin(-rotSpeed) + d->dirY * cos(-rotSpeed);
		d->planeX = d->planeX * cos(-rotSpeed) - d->planeY * sin(-rotSpeed);
		d->planeY = old_plane_x * sin(-rotSpeed) + d->planeY * cos(-rotSpeed);
	}
	else if (direction == -1)
	{
		d->dirX = d->dirX * cos(rotSpeed) - d->dirY * sin(rotSpeed);
		d->dirY = old_dir_x * sin(rotSpeed) + d->dirY * cos(rotSpeed);
		d->planeX = d->planeX * cos(rotSpeed) - d->planeY * sin(rotSpeed);
		d->planeY = old_plane_x * sin(rotSpeed) + d->planeY * cos(rotSpeed);
	}
}

int	key_release(int key, t_data *d)
{
	if (key == W_KEY)
		d->keys.key_w = 0;
	if (key == S_KEY)
		d->keys.key_s = 0;
	if (key == A_KEY)
		d->keys.key_a = 0;
	if (key == D_KEY)
		d->keys.key_d = 0;
	if (key == KEY_ARR_RIGHT)
		d->keys.key_right = 0;
	if (key == KEY_ARR_LEFT)
		d->keys.key_left = 0;
	if (key == ESC_KEY)
		d->keys.key_esc = 0;
	return (0);
}

int	key_press(int key, t_data *d)
{
	if (key == W_KEY)
		d->keys.key_w = 1;
	if (key == S_KEY)
		d->keys.key_s = 1;
	if (key == A_KEY)
		d->keys.key_a = 1;
	if (key == D_KEY)
		d->keys.key_d = 1;
	if (key == KEY_ARR_RIGHT)
		d->keys.key_right = 1;
	if (key == KEY_ARR_LEFT)
		d->keys.key_left = 1;
	if (key == ESC_KEY)
		d->keys.key_esc = 1;
	return (0);
}

int	key_hook(t_data *d)
{
	if (d->keys.key_w)
		move(1, d);
	if (d->keys.key_s)
		move(-1, d);
	if (d->keys.key_d || d->keys.key_right)
		rotate(1, d, d->rotSpeed);
	if (d->keys.key_a || d->keys.key_left)
		rotate(-1, d, d->rotSpeed);
	if (d->keys.key_esc)
		finish(d);
	return (0);
}
