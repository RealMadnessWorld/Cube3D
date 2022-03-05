#include "../includes/cub3d.h"

int mapito[mapWidth][mapHeight] =
	{
		{8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 4, 6, 4, 4, 6, 4, 6, 4, 4, 4, 6, 4},
		{8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
		{8, 0, 3, 3, 0, 0, 0, 0, 0, 8, 8, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
		{8, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
		{8, 0, 3, 3, 0, 0, 0, 0, 0, 8, 8, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
		{8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 4, 0, 0, 0, 0, 0, 6, 6, 6, 0, 6, 4, 6},
		{8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 4, 4, 4, 4, 4, 4, 6, 0, 0, 0, 0, 0, 6},
		{7, 7, 7, 7, 0, 7, 7, 7, 7, 0, 8, 0, 8, 0, 8, 0, 8, 4, 0, 4, 0, 6, 0, 6},
		{7, 7, 0, 0, 0, 0, 0, 0, 7, 8, 0, 8, 0, 8, 0, 8, 8, 6, 0, 0, 0, 0, 0, 6},
		{7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 6, 0, 0, 0, 0, 0, 4},
		{7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 6, 0, 6, 0, 6, 0, 6},
		{7, 7, 0, 0, 0, 0, 0, 0, 7, 8, 0, 8, 0, 8, 0, 8, 8, 6, 4, 6, 0, 6, 6, 6},
		{7, 7, 7, 7, 0, 7, 7, 7, 7, 8, 8, 4, 0, 6, 8, 4, 8, 3, 3, 3, 0, 3, 3, 3},
		{2, 2, 2, 2, 0, 2, 2, 2, 2, 4, 6, 4, 0, 0, 6, 0, 6, 3, 0, 0, 0, 0, 0, 3},
		{2, 2, 0, 0, 0, 0, 0, 2, 2, 4, 0, 0, 0, 0, 0, 0, 4, 3, 0, 0, 0, 0, 0, 3},
		{2, 0, 0, 0, 0, 0, 0, 0, 2, 4, 0, 0, 0, 0, 0, 0, 4, 3, 0, 0, 0, 0, 0, 3},
		{1, 0, 0, 0, 0, 0, 0, 0, 1, 4, 4, 4, 4, 4, 6, 0, 6, 3, 3, 0, 0, 0, 3, 3},
		{2, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 1, 2, 2, 2, 6, 6, 0, 0, 5, 0, 5, 0, 5},
		{2, 2, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 2, 2, 0, 5, 0, 5, 0, 0, 0, 5, 5},
		{2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 5, 0, 5, 0, 5, 0, 5, 0, 5},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
		{2, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 5, 0, 5, 0, 5, 0, 5, 0, 5},
		{2, 2, 0, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 2, 2, 0, 5, 0, 5, 0, 0, 0, 5, 5},
		{2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5}};


static void set_distances(t_rc *rc, int x, t_data *info)
{
	if (rc->rayDirX < 0)
	{
		rc->stepX = -1;
		rc->sideDistX = (info->posX - rc->mapX) * rc->deltaDistX;
	}
	else
	{
		rc->stepX = 1;
		rc->sideDistX = (rc->mapX + 1.0 - info->posX) * rc->deltaDistX;
	}
	if (rc->rayDirY < 0)
	{
		rc->stepY = -1;
		rc->sideDistY = (info->posY - rc->mapY) * rc->deltaDistY;
	}
	else
	{
		rc->stepY = 1;
		rc->sideDistY = (rc->mapY + 1.0 - info->posY) * rc->deltaDistY;
	}
}

static void	loop_till_hit(t_rc *rc, t_data *info)
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
		if (mapito[rc->mapX][rc->mapY] > 0)
		rc->hit = 1;
	}
	if (rc->side == 0)
		rc->perpWallDist = (rc->mapX - info->posX + (1 - rc->stepX) / 2) / rc->rayDirX;
	else
		rc->perpWallDist = (rc->mapY - info->posY + (1 - rc->stepY) / 2) / rc->rayDirY;
}

static void calculate_textures(t_rc *rc, t_data *info)
{
	rc->lineHeight = (int)(HEIGHT / rc->perpWallDist);
	rc->drawStart = -rc->lineHeight / 2 + HEIGHT / 2;
	if (rc->drawStart < 0)
		rc->drawStart = 0;
	rc->drawEnd = rc->lineHeight / 2 + HEIGHT / 2;
	if (rc->drawEnd >= HEIGHT)
		rc->drawEnd = HEIGHT - 1;
	rc->texNum = mapito[rc->mapX][rc->mapY] - 1;
	if (rc->side == 0)
		rc->wallX = info->posY + rc->perpWallDist * rc->rayDirY;
	else
		rc->wallX = info->posX + rc->perpWallDist * rc->rayDirX;
	rc->wallX -= floor(rc->wallX);
	rc->texX = (int)(rc->wallX * (double)texWidth);
	if (rc->side == 0 && rc->rayDirX > 0)
		rc->texX = texWidth - rc->texX - 1;
	if (rc->side == 1 && rc->rayDirY < 0)
		rc->texX = texWidth - rc->texX - 1;
	rc->step = 1.0 * texHeight / rc->lineHeight;
	rc->texPos = (rc->drawStart - HEIGHT / 2 + rc->lineHeight / 2) * rc->step;
}

static void set_textures_coords(t_rc *rc, t_data *info, int x)
{
	int y;

	y = rc->drawStart;
	while (y < rc->drawEnd)
	{
		rc->texY = (int)rc->texPos & (texHeight - 1);
		rc->texPos += rc->step;
		rc->color = info->texture[rc->texNum][texHeight * rc->texY + rc->texX];
		if (rc->side == 1)
			rc->color = (rc->color >> 1) & 8355711;

		info->buf[y][x] = rc->color;
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

void	draw_floor(t_rc *rc, t_data *info, int x)
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
		rc->currentFloorX = rc->weight * rc->floorXWall + (1.0 - rc->weight) * info->posX;
		rc->currentFloorY = rc->weight * rc->floorYWall + (1.0 - rc->weight) * info->posY;
		rc->floorTexX = (int)(rc->currentFloorX * texWidth) % texWidth;
		rc->floorTexY = (int)(rc->currentFloorY * texHeight) % texHeight;
		rc->checkerBoardPattern = ((int)(rc->currentFloorX) + (int)(rc->currentFloorY)) % 2;
		if (rc->checkerBoardPattern == 0)
			rc->floorTexture = 3;
		else
			rc->floorTexture = 4;
		info->buf[y][x] = (info->texture[rc->floorTexture][texWidth * rc->floorTexY + rc->floorTexX] >> 1) & 8355711;
		info->buf[HEIGHT - y][x] = info->texture[6][texWidth * rc->floorTexY + rc->floorTexX];
		y++;
	}
}

static void init_rc_vars(t_rc *rc, int x, t_data *info)
{
	rc->cameraX = 2 * x / (double)WIDTH - 1;
	rc->rayDirX = info->dirX + info->planeX * rc->cameraX;
	rc->rayDirY = info->dirY + info->planeY * rc->cameraX;
	rc->mapX = (int)info->posX;
	rc->mapY = (int)info->posY;
	rc->deltaDistX = fabs(1 / rc->rayDirX);
	rc->deltaDistY = fabs(1 / rc->rayDirY);
	rc->hit = 0;
}

void calculate(t_data *info)
{
	int		x;
	t_rc	rc;

	x = 0;
	while (x < WIDTH)
	{
		init_rc_vars(&rc, x, info);
		set_distances(&rc, x, info);
		loop_till_hit(&rc,info);
		calculate_textures(&rc, info);
		set_textures_coords(&rc, info, x);
		set_wall_directions(&rc);
		draw_floor(&rc, info, x);
		x++;
	}
}
