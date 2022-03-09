#include "../includes/cub3d.h"

void	set_textures_coords(t_rc *rc, t_data *data, int x)
{
	int y;

	y = rc->drawStart;
	while (y < rc->drawEnd)
	{
		rc->texY = (int)rc->texPos & (texHeight - 1);
		rc->texPos += rc->step;
		rc->color = data->texture[rc->texNum][texHeight * rc->texY + rc->texX];
		if (rc->side == 1)
			rc->color = (rc->color >> 1) & 8355711;

		data->buf[y][x] = rc->color;
		y++;
	}
}

void	set_wall_directions(t_rc *rc)
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

void	draw_floor(t_rc *rc, t_data *data, int x)
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
		rc->currentFloorX = rc->weight * rc->floorXWall + (1.0 - rc->weight) * data->posX;
		rc->currentFloorY = rc->weight * rc->floorYWall + (1.0 - rc->weight) * data->posY;
		rc->floorTexX = (int)(rc->currentFloorX * texWidth) % texWidth;
		rc->floorTexY = (int)(rc->currentFloorY * texHeight) % texHeight;
		rc->checkerBoardPattern = ((int)(rc->currentFloorX) + (int)(rc->currentFloorY)) % 2;
		if (rc->checkerBoardPattern == 0)
			rc->floorTexture = 3;
		else
			rc->floorTexture = 4;
		data->buf[y][x] = (data->texture[rc->floorTexture][texWidth * rc->floorTexY + rc->floorTexX] >> 1) & 8355711;
		data->buf[HEIGHT - y][x] = data->texture[6][texWidth * rc->floorTexY + rc->floorTexX];
		y++;
	}
}
