#include "../includes/cub3d.h"

// int mapito[10][10] =
// 	{
// 		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
// 		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
// 		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
// 		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
// 		{1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
// 		{1, 1, 0, 0, 0, 0, 0, 0, 1, 1},
// 		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};


static void set_distances(t_rc *rc, int x, t_data *data)
{
	if (rc->rayDirX < 0)
	{
		rc->stepX = -1;
		rc->sideDistX = (data->posX - rc->mapX) * rc->deltaDistX;
	}
	else
	{
		rc->stepX = 1;
		rc->sideDistX = (rc->mapX + 1.0 - data->posX) * rc->deltaDistX;
	}
	if (rc->rayDirY < 0)
	{
		rc->stepY = -1;
		rc->sideDistY = (data->posY - rc->mapY) * rc->deltaDistY;
	}
	else
	{
		rc->stepY = 1;
		rc->sideDistY = (rc->mapY + 1.0 - data->posY) * rc->deltaDistY;
	}
}

static void	calc_distance(t_rc *rc, t_data *data)
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
	// printf("mapX = %d\tmapY = %d\n", rc->mapX, rc->mapY);
		if (data->mapito[rc->mapX][rc->mapY] > 0)
			rc->hit = 1;
	// printf("BBB\n");

	}
	if (rc->side == 0)
		rc->perpWallDist = (rc->mapX - data->posX + (1 - rc->stepX) / 2) / rc->rayDirX;
	else
		rc->perpWallDist = (rc->mapY - data->posY + (1 - rc->stepY) / 2) / rc->rayDirY;
}

static void calc_height(t_rc *rc, t_data *data)
{
	rc->lineHeight = (int)(HEIGHT / rc->perpWallDist);
	rc->drawStart = -rc->lineHeight / 2 + HEIGHT / 2;
	if (rc->drawStart < 0)
		rc->drawStart = 0;
	rc->drawEnd = rc->lineHeight / 2 + HEIGHT / 2;
	if (rc->drawEnd >= HEIGHT)
		rc->drawEnd = HEIGHT - 1;
	if (rc->side == 0)
		rc->wallX = data->posY + rc->perpWallDist * rc->rayDirY;
	else
		rc->wallX = data->posX + rc->perpWallDist * rc->rayDirX;
	rc->wallX -= floor(rc->wallX);
	rc->texX = (int)(rc->wallX * (double)texWidth);
	if (rc->side == 0 && rc->rayDirX > 0)
		rc->texX = texWidth - rc->texX - 1;
	if (rc->side == 1 && rc->rayDirY < 0)
		rc->texX = texWidth - rc->texX - 1;
	rc->step = 1.0 * texHeight / rc->lineHeight;
	rc->texPos = (rc->drawStart - HEIGHT / 2 + rc->lineHeight / 2) * rc->step;
}

static void init_rc_vars(t_rc *rc, int x, t_data *data)
{
	rc->cameraX = 2 * x / (double)WIDTH - 1;
	rc->rayDirX = data->dirX + data->planeX * rc->cameraX;
	rc->rayDirY = data->dirY + data->planeY * rc->cameraX;
	rc->mapX = (int)data->posX;
	rc->mapY = (int)data->posY;
	rc->deltaDistX = fabs(1 / rc->rayDirX);
	rc->deltaDistY = fabs(1 / rc->rayDirY);
	rc->hit = 0;
}

void calculate(t_data *data)
{
	int		x;
	t_rc	rc;

	x = 0;
	while (x < WIDTH)
	{
		init_rc_vars(&rc, x, data);
		set_distances(&rc, x, data);
		calc_distance(&rc,data);
		calc_height(&rc, data);
		draw_walls(&rc, data, x);
		set_floor(&rc);
		draw_floor(&rc, data, x);
		x++;
	}
}
