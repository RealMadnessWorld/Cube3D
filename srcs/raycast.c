#include "../includes/cub3d.h"

static void cast_rays(t_rc *rc, t_data *d)
{
	if (rc->rayDirX < 0)
	{
		rc->stepX = -1;
		rc->sideDistX = (d->posX - rc->mapX) * rc->deltaDistX;
	}
	else
	{
		rc->stepX = 1;
		rc->sideDistX = (rc->mapX + 1.0 - d->posX) * rc->deltaDistX;
	}
	if (rc->rayDirY < 0)
	{
		rc->stepY = -1;
		rc->sideDistY = (d->posY - rc->mapY) * rc->deltaDistY;
	}
	else
	{
		rc->stepY = 1;
		rc->sideDistY = (rc->mapY + 1.0 - d->posY) * rc->deltaDistY;
	}
}

static void	calc_distance(t_rc *rc, t_data *d)
{
	while (rc->hit == 0)
	{
		if (rc->sideDistX < rc->sideDistY)
		{
			rc->sideDistX += rc->deltaDistX;
			rc->mapX += rc->stepX;
			rc->side = 0;
		}
		else
		{
			rc->sideDistY += rc->deltaDistY;
			rc->mapY += rc->stepY;
			rc->side = 1;
		}
		if (d->mapito[rc->mapX][rc->mapY] > 0)
			rc->hit = 1;

	}
	if (rc->side == 0)
		rc->perpWallDist = (rc->mapX - d->posX + (1 - rc->stepX) / 2) / rc->rayDirX;
	else
		rc->perpWallDist = (rc->mapY - d->posY + (1 - rc->stepY) / 2) / rc->rayDirY;
}

static void calc_height(t_rc *rc, t_data *d)
{
	rc->lineHeight = (int)(HEIGHT / rc->perpWallDist);
	rc->drawStart = -rc->lineHeight / 2 + HEIGHT / 2;
	if (rc->drawStart < 0)
		rc->drawStart = 0;
	rc->drawEnd = rc->lineHeight / 2 + HEIGHT / 2;
	if (rc->drawEnd >= HEIGHT)
		rc->drawEnd = HEIGHT - 1;
	if (rc->side == 0)
		rc->wallX = d->posY + rc->perpWallDist * rc->rayDirY;
	else
		rc->wallX = d->posX + rc->perpWallDist * rc->rayDirX;
	rc->wallX -= floor(rc->wallX);
	rc->texX = (int)(rc->wallX * (double)TEXWIDTH);
	if (rc->side == 0 && rc->rayDirX > 0)
		rc->texX = TEXWIDTH - rc->texX - 1;
	if (rc->side == 1 && rc->rayDirY < 0)
		rc->texX = TEXWIDTH - rc->texX - 1;
	rc->step = 1.0 * TEXHEIGHT / rc->lineHeight;
	rc->texPos = (rc->drawStart - HEIGHT / 2 + rc->lineHeight / 2) * rc->step;
}

static void init_rc_vars(t_rc *rc, int x, t_data *d)
{
	rc->cameraX = 2 * x / (double)WIDTH - 1;
	rc->rayDirX = d->dirX + d->planeX * rc->cameraX;
	rc->rayDirY = d->dirY + d->planeY * rc->cameraX;
	rc->mapX = (int)d->posX;
	rc->mapY = (int)d->posY;
	rc->deltaDistX = fabs(1 / rc->rayDirX);
	rc->deltaDistY = fabs(1 / rc->rayDirY);
	rc->hit = 0;
}

void calculate(t_data *d)
{
	int		x;
	t_rc	rc;

	x = 0;
	while (x < WIDTH)
	{
		init_rc_vars(&rc, x, d);
		cast_rays(&rc, d);
		calc_distance(&rc,d);
		calc_height(&rc, d);
		draw_walls(&rc, d, x);
		set_floor(&rc);
		draw_floor(&rc, d, x);
		x++;
	}
}
