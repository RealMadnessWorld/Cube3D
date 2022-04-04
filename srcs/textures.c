/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:17:55 by fmeira            #+#    #+#             */
/*   Updated: 2022/04/04 18:31:19 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_color(t_data *d, t_rc *rc)
{
	if (rc->side == 0)
	{
		if (d->posX > rc->mapX)
			rc->color = d->map.no_img[TEXHEIGHT * rc->texY + rc->texX];
		else
			rc->color = d->map.so_img[TEXHEIGHT * rc->texY + rc->texX];
	}
	else
	{
		if (d->posY > rc->mapY)
			rc->color = d->map.we_img[TEXHEIGHT * rc->texY + rc->texX];
		else
			rc->color = d->map.ea_img[TEXHEIGHT * rc->texY + rc->texX];
	}
}

void	draw_walls(t_rc *rc, t_data *d, int x)
{
	int	y;

	y = rc->drawStart;
	while (y < rc->drawEnd)
	{
		rc->texY = (int)rc->texPos & (TEXHEIGHT - 1);
		rc->texPos += rc->step;
		set_color(d, rc);
		d->buf[y][x] = rc->color;
		y++;
	}
}

void	set_floor(t_rc *rc)
{
	if (rc->side == 0 && rc->rayDirX > 0)
	{
		rc->floorXWall = rc->mapX;
		rc->floorYWall = rc->mapY + rc->wallX;
	}
	else if (rc->side == 0 && rc->rayDirX < 0)
	{
		rc->floorXWall = rc->mapX + 1.0;
		rc->floorYWall = rc->mapY + rc->wallX;
	}
	else if (rc->side == 1 && rc->rayDirY > 0)
	{
		rc->floorXWall = rc->mapX + rc->wallX;
		rc->floorYWall = rc->mapY;
	}
	else
	{
		rc->floorXWall = rc->mapX + rc->wallX;
		rc->floorYWall = rc->mapY + 1.0;
	}
}

void	draw_floor(t_rc *rc, t_data *d, int x)
{
	int	y;

	rc->distWall = rc->pWallDst;
	rc->distPlr = 0.0;
	if (rc->drawEnd < 0)
		rc->drawEnd = HEIGHT;
	y = rc->drawEnd + 1;
	while (y < HEIGHT)
	{
		rc->currDist = HEIGHT / (2.0 * y - HEIGHT);
		rc->weight = (rc->currDist - rc->distPlr) / (rc->distWall - rc->distPlr);
		rc->currFloorX = rc->weight * rc->floorXWall + (1.0 - rc->weight) * d->posX;
		rc->currFloorY = rc->weight * rc->floorYWall + (1.0 - rc->weight) * d->posY;
		rc->floorTexX = (int)(rc->currFloorX * TEXWIDTH) % TEXWIDTH;
		rc->floorTexY = (int)(rc->currFloorY * TEXHEIGHT) % TEXHEIGHT;
		rc->checkBoardPattern = ((int)(rc->currFloorX) + (int)(rc->currFloorY)) % 2;
		//floor
		d->buf[y][x] = (0 << 24 | d->map.f_color[0] << 16 | d->map.f_color[1] << 8 | d->map.f_color[2]);
		//ceiling
		d->buf[HEIGHT - y][x] = (0 << 24 | d->map.c_color[0] << 16 | d->map.c_color[1] << 8 | d->map.c_color[2]);
		y++;
	}
}
