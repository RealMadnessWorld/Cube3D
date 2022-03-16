#include "../includes/cub3d.h"

static void	set_color(t_data *d, t_rc *rc)
{
	if (rc->side == 0)
	{
		if (d->posX > rc->mapX)
			rc->color = d->map.no_img[texHeight * rc->texY + rc->texX];
		else
			rc->color = d->map.so_img[texHeight * rc->texY + rc->texX];
	}
	else
	{
		if (d->posY > rc->mapY)
			rc->color = d->map.we_img[texHeight * rc->texY + rc->texX];
		else
			rc->color = d->map.ea_img[texHeight * rc->texY + rc->texX];
	}
}
void	draw_walls(t_rc *rc, t_data *d, int x)
{
	int y;

	y = rc->drawStart;
	while (y < rc->drawEnd)
	{
		rc->texY = (int)rc->texPos & (texHeight - 1);
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

	rc->distWall = rc->perpWallDist;
	rc->distPlayer = 0.0;
	if (rc->drawEnd < 0)
		rc->drawEnd = HEIGHT;
	y = rc->drawEnd + 1;
	while (y < HEIGHT)
	{
		rc->currentDist = HEIGHT / (2.0 * y - HEIGHT);
		rc->weight = (rc->currentDist - rc->distPlayer) / (rc->distWall - rc->distPlayer);
		rc->currentFloorX = rc->weight * rc->floorXWall + (1.0 - rc->weight) * d->posX;
		rc->currentFloorY = rc->weight * rc->floorYWall + (1.0 - rc->weight) * d->posY;
		rc->floorTexX = (int)(rc->currentFloorX * texWidth) % texWidth;
		rc->floorTexY = (int)(rc->currentFloorY * texHeight) % texHeight;
		rc->checkerBoardPattern = ((int)(rc->currentFloorX) + (int)(rc->currentFloorY)) % 2;
		//floor
		d->buf[y][x] = (0 << 24 | d->map.f_color[0] << 16 | d->map.f_color[1] << 8 | d->map.f_color[2]);
		//ceiling
		d->buf[HEIGHT - y][x] = (0 << 24 | d->map.c_color[0] << 16 | d->map.c_color[1] << 8 | d->map.c_color[2]);
		y++;
	}
}
