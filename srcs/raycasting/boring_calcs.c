#include "cub3d.h"

void	init_calcs(t_calc *c, t_data *d)
{
	c->rayDirY = 0;
	c->sideDistX = 0;
	c->sideDistY = 0;
	c->perpWallDist = 0;
	c->stepX = 0;
	c->stepY = 0;
	c->side = 0;
	c->dirX = -1;
	c->dirY = 0;
	c->planeX = 0;
	c->planeY = 0.66;
	c->moveSpeed = 0.05;
	c->rotSpeed = 0.05;
	c->posX = d->map.play_x;
	c->posY = d->map.play_y;
}

void	set_things(t_calc *c, int x)
{
	c->cameraX = 2 * x / (double)WIN_W - 1;
	c->rayDirX = c->dirX + c->planeX * c->cameraX;
	c->rayDirY = c->dirY + c->planeY * c->cameraX;
	c->mapX = (int)c->posX;
	c->mapY = (int)c->posY;
	c->deltaDistX = fabs(1 / c->rayDirX);
	c->deltaDistY = fabs(1 / c->rayDirY);
	c->hit = 0;
}

void	direction_calc(t_calc *c)
{
	if (c->rayDirX < 0)
	{
		c->stepX = -1;
		c->sideDistX = (c->posX - c->mapX) * c->deltaDistX;
	}
	else
	{
		c->stepX = 1;
		c->sideDistX = (c->mapX + 1.0 - c->posX) * c->deltaDistX;
	}
	if (c->rayDirY < 0)
	{
		c->dirY = -1;
		c->sideDistY = (c->posY - c->mapY) * c->deltaDistY;
	}
	else
	{
		c->stepY = 1;
		c->sideDistY = (c->mapY + 1.0 - c->posY) * c->deltaDistY;
	}
}

void	calcs(t_data *d)
{
	int		x;
	t_calc	c;

	x = 0;
	init_calcs(&c, d);
	while (x < WIN_W)
	{
		set_things(&c, x);
		direction_calc(&c);

		while (c.hit == 0)
		{
			if (c.sideDistX < c.sideDistY)
			{
				c.sideDistX =+ c.deltaDistX;
				c.mapX =+ c.stepX;
				c.side = 0;
			}
			else
			{
				c.sideDistY =+ c.deltaDistY;
				c.mapY =+ c.stepY;
				c.side = 1;
			}
			if (d->map.map[c.mapY][c.mapX] > 0)
				c.hit = 1;
		}
		if (c.side == 0)
			c.perpWallDist = (c.mapX - c.posX + (1 - c.stepX) / 2) / c.rayDirX;
		else
			c.perpWallDist = (c.mapY - c.posY + (1 - c.stepY) / 2) / c.rayDirY;

		c.lineHeight = (int)(WIN_H / c.perpWallDist);
		c.drawStart = -c.lineHeight / 2 + WIN_H / 2;
		if (c.drawStart < 0)
			c.drawStart = 0;
		c.drawEnd = c.lineHeight / 2 + WIN_H / 2;
		if (c.drawEnd < 0)
			c.drawEnd = WIN_H - 1;
		if (d->map.map[c.mapY][c.mapX] == 1)
			c.color = 0xFF0000;
		else if (d->map.map[c.mapY][c.mapX] == 2)
			c.color = 0x00FF00;
		else if (d->map.map[c.mapY][c.mapX] == 3)
			c.color = 0x0000FF;
		else if (d->map.map[c.mapY][c.mapX] == 4)
			c.color = 0xFFFFFF;
		else
			c.color= 0xFFFF00;

		if (c.side == 1)
			c.color = c.color / 2;
		ver_line(&c, d, x);
		x++;
	}
}