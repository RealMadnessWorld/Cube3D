/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:17:55 by fmeira            #+#    #+#             */
/*   Updated: 2022/04/05 16:35:11 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_color(t_data *d, t_rc *rc)
{
	if (rc->side == 0)
	{
		if (d->posx > rc->mapx)
			rc->color = d->map.no_img[TEXHEIGHT * rc->texy + rc->texx];
		else
			rc->color = d->map.so_img[TEXHEIGHT * rc->texy + rc->texx];
	}
	else
	{
		if (d->posy > rc->mapy)
			rc->color = d->map.we_img[TEXHEIGHT * rc->texy + rc->texx];
		else
			rc->color = d->map.ea_img[TEXHEIGHT * rc->texy + rc->texx];
	}
}

void	draw_walls(t_rc *rc, t_data *d, int x)
{
	int	y;

	y = rc->drawstart;
	while (y < rc->drawend)
	{
		rc->texy = (int)rc->texpos & (TEXHEIGHT - 1);
		rc->texpos += rc->step;
		set_color(d, rc);
		d->buf[y][x] = rc->color;
		y++;
	}
}

void	set_floor(t_rc *rc)
{
	if (rc->side == 0 && rc->raydirx > 0)
	{
		rc->flrxwall = rc->mapx;
		rc->flrywall = rc->mapy + rc->wallx;
	}
	else if (rc->side == 0 && rc->raydirx < 0)
	{
		rc->flrxwall = rc->mapx + 1.0;
		rc->flrywall = rc->mapy + rc->wallx;
	}
	else if (rc->side == 1 && rc->raydiry > 0)
	{
		rc->flrxwall = rc->mapx + rc->wallx;
		rc->flrywall = rc->mapy;
	}
	else
	{
		rc->flrxwall = rc->mapx + rc->wallx;
		rc->flrywall = rc->mapy + 1.0;
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

	rc->dstwall = rc->pwalldst;
	rc->distplr = 0.0;
	if (rc->drawend < 0)
		rc->drawend = HEIGHT;
	y = rc->drawend + 1;
	while (y < HEIGHT)
	{
		nrm = HEIGHT - y;
		rc->currdist = HEIGHT / (2.0 * y - HEIGHT);
		rc->weight = (rc->currdist - rc->distplr) / (rc->dstwall - rc->distplr);
		rc->currflrx = rc->weight * rc->flrxwall + (1.0 - rc->weight) * d->posx;
		rc->currflry = rc->weight * rc->flrywall + (1.0 - rc->weight) * d->posy;
		rc->floortexx = (int)(rc->currflrx * TEXWIDTH) % TEXWIDTH;
		rc->floortexy = (int)(rc->currflry * TEXHEIGHT) % TEXHEIGHT;
		rc->chkboardpatrn = ((int)(rc->currflrx) + (int)(rc->currflry)) % 2;
		d->buf[y][x] = rgb(d->map.f_clr[0], d->map.f_clr[1], d->map.f_clr[2]);
		d->buf[nrm][x] = rgb(d->map.c_clr[0], d->map.c_clr[1], d->map.c_clr[2]);
		y++;
	}
}
