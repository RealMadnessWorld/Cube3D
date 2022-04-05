/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:15:27 by fmeira            #+#    #+#             */
/*   Updated: 2022/04/05 16:35:36 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	cast_rays(t_rc *rc, t_data *d)
{
	if (rc->raydirx < 0)
	{
		rc->stepx = -1;
		rc->sidedistx = (d->posx - rc->mapx) * rc->deltadistx;
	}
	else
	{
		rc->stepx = 1;
		rc->sidedistx = (rc->mapx + 1.0 - d->posx) * rc->deltadistx;
	}
	if (rc->raydiry < 0)
	{
		rc->stepy = -1;
		rc->sidedisty = (d->posy - rc->mapy) * rc->deltadisty;
	}
	else
	{
		rc->stepy = 1;
		rc->sidedisty = (rc->mapy + 1.0 - d->posy) * rc->deltadisty;
	}
}

static void	calc_distance(t_rc *rc, t_data *d)
{
	while (rc->hit == 0)
	{
		if (rc->sidedistx < rc->sidedisty)
		{
			rc->sidedistx += rc->deltadistx;
			rc->mapx += rc->stepx;
			rc->side = 0;
		}
		else
		{
			rc->sidedisty += rc->deltadisty;
			rc->mapy += rc->stepy;
			rc->side = 1;
		}
		if (d->mapito[rc->mapx][rc->mapy] > 0)
			rc->hit = 1;
	}
	if (rc->side == 0)
		rc->pwalldst = (rc->mapx - d->posx + (1 - rc->stepx) / 2) / rc->raydirx;
	else
		rc->pwalldst = (rc->mapy - d->posy + (1 - rc->stepy) / 2) / rc->raydiry;
}

static void	calc_height(t_rc *rc, t_data *d)
{
	rc->lineheight = (int)(HEIGHT / rc->pwalldst);
	rc->drawstart = -rc->lineheight / 2 + HEIGHT / 2;
	if (rc->drawstart < 0)
		rc->drawstart = 0;
	rc->drawend = rc->lineheight / 2 + HEIGHT / 2;
	if (rc->drawend >= HEIGHT)
		rc->drawend = HEIGHT - 1;
	if (rc->side == 0)
		rc->wallx = d->posy + rc->pwalldst * rc->raydiry;
	else
		rc->wallx = d->posx + rc->pwalldst * rc->raydirx;
	rc->wallx -= floor(rc->wallx);
	rc->texx = (int)(rc->wallx * (double)TEXWIDTH);
	if (rc->side == 0 && rc->raydirx > 0)
		rc->texx = TEXWIDTH - rc->texx - 1;
	if (rc->side == 1 && rc->raydiry < 0)
		rc->texx = TEXWIDTH - rc->texx - 1;
	rc->step = 1.0 * TEXHEIGHT / rc->lineheight;
	rc->texpos = (rc->drawstart - HEIGHT / 2 + rc->lineheight / 2) * rc->step;
}

static void	init_rc_vars(t_rc *rc, int x, t_data *d)
{
	rc->camera_x = 2 * x / (double)WIDTH - 1;
	rc->raydirx = d->dirx + d->planex * rc->camera_x;
	rc->raydiry = d->diry + d->planey * rc->camera_x;
	rc->mapx = (int)d->posx;
	rc->mapy = (int)d->posy;
	rc->deltadistx = fabs(1 / rc->raydirx);
	rc->deltadisty = fabs(1 / rc->raydiry);
	rc->hit = 0;
}

void	calculate(t_data *d)
{
	int		x;
	t_rc	rc;

	x = 0;
	while (x < WIDTH)
	{
		init_rc_vars(&rc, x, d);
		cast_rays(&rc, d);
		calc_distance(&rc, d);
		calc_height(&rc, d);
		draw_walls(&rc, d, x);
		set_floor(&rc);
		draw_floor(&rc, d, x);
		x++;
	}
}
