/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:17:55 by fmeira            #+#    #+#             */
/*   Updated: 2022/04/04 19:06:47 by fmeira           ###   ########.fr       */
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
		rc->flrXWall = rc->mapX;
		rc->flrYWall = rc->mapY + rc->wallX;
	}
	else if (rc->side == 0 && rc->rayDirX < 0)
	{
		rc->flrXWall = rc->mapX + 1.0;
		rc->flrYWall = rc->mapY + rc->wallX;
	}
	else if (rc->side == 1 && rc->rayDirY > 0)
	{
		rc->flrXWall = rc->mapX + rc->wallX;
		rc->flrYWall = rc->mapY;
	}
	else
	{
		rc->flrXWall = rc->mapX + rc->wallX;
		rc->flrYWall = rc->mapY + 1.0;
	}
}

static int	rgb(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}

void	draw_floor(t_rc *rc, t_data *d, int x)
{
	int	y;
	int	nrm;

	rc->dstWall = rc->pWallDst;
	rc->distPlr = 0.0;
	if (rc->drawEnd < 0)
		rc->drawEnd = HEIGHT;
	y = rc->drawEnd + 1;
	while (y < HEIGHT)
	{
		nrm = HEIGHT - y;
		rc->currdist = HEIGHT / (2.0 * y - HEIGHT);
		rc->weight = (rc->currdist - rc->distPlr) / (rc->dstWall - rc->distPlr);
		rc->currFlrX = rc->weight * rc->flrXWall + (1.0 - rc->weight) * d->posX;
		rc->currFlrY = rc->weight * rc->flrYWall + (1.0 - rc->weight) * d->posY;
		rc->floorTexX = (int)(rc->currFlrX * TEXWIDTH) % TEXWIDTH;
		rc->floorTexY = (int)(rc->currFlrY * TEXHEIGHT) % TEXHEIGHT;
		rc->chkBoardPatrn = ((int)(rc->currFlrX) + (int)(rc->currFlrY)) % 2;
		d->buf[y][x] = rgb(d->map.f_clr[0], d->map.f_clr[1], d->map.f_clr[2]);
		d->buf[nrm][x] = rgb(d->map.c_clr[0], d->map.c_clr[1], d->map.c_clr[2]);
		y++;
	}
}
