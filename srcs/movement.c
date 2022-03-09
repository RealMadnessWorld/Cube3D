#include "../includes/cub3d.h"

int mapa[mapWidth][mapHeight] =
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

static void move(int direction, t_data *data)
{
	if (direction == 1)
	{
		if (!mapa[(int)(data->posX + data->dirX * data->moveSpeed)][(int)(data->posY)])
			data->posX += data->dirX * data->moveSpeed;
		if (!mapa[(int)(data->posX)][(int)(data->posY + data->dirY * data->moveSpeed)])
			data->posY += data->dirY * data->moveSpeed;
	}
	else if (direction == -1)
	{
		if (!mapa[(int)(data->posX - data->dirX * data->moveSpeed)][(int)(data->posY)])
			data->posX -= data->dirX * data->moveSpeed;
		if (!mapa[(int)(data->posX)][(int)(data->posY - data->dirY * data->moveSpeed)])
			data->posY -= data->dirY * data->moveSpeed;
	}
}

static void rotate(int direction, t_data *data)
{
	double oldDirX;
	double oldPlaneX;
	oldDirX = data->dirX;
	oldPlaneX = data->planeX;

	if (direction == 1)
	{
		data->dirX = data->dirX * cos(-data->rotSpeed) - data->dirY * sin(-data->rotSpeed);
		data->dirY = oldDirX * sin(-data->rotSpeed) + data->dirY * cos(-data->rotSpeed);
		data->planeX = data->planeX * cos(-data->rotSpeed) - data->planeY * sin(-data->rotSpeed);
		data->planeY = oldPlaneX * sin(-data->rotSpeed) + data->planeY * cos(-data->rotSpeed);
	}
	else if (direction == -1)
	{
		data->dirX = data->dirX * cos(data->rotSpeed) - data->dirY * sin(data->rotSpeed);
		data->dirY = oldDirX * sin(data->rotSpeed) + data->dirY * cos(data->rotSpeed);
		data->planeX = data->planeX * cos(data->rotSpeed) - data->planeY * sin(data->rotSpeed);
		data->planeY = oldPlaneX * sin(data->rotSpeed) + data->planeY * cos(data->rotSpeed);
	}
}

int	key_release(int key, t_data *data)
{
	if (key == W_KEY)
		data->keys.key_w = 0;
	if (key == S_KEY)
		data->keys.key_s = 0;
	if (key == A_KEY)
		data->keys.key_a = 0;
	if (key == D_KEY)
		data->keys.key_d = 0;
	if (key == KEY_ARR_RIGHT)
		data->keys.key_right = 0;
	if (key == KEY_ARR_LEFT)
		data->keys.key_left = 0;
	if (key == ESC_KEY)
		data->keys.key_esc = 0;
	return (0);
}

int	key_press(int key, t_data *data)
{
	if (key == W_KEY)
		data->keys.key_w = 1;
	if (key == S_KEY)
		data->keys.key_s = 1;
	if (key == A_KEY)
		data->keys.key_a = 1;
	if (key == D_KEY)
		data->keys.key_d = 1;
	if (key == KEY_ARR_RIGHT)
		data->keys.key_right = 1;
	if (key == KEY_ARR_LEFT)
		data->keys.key_left = 1;
	if (key == ESC_KEY)
		data->keys.key_esc = 1;
	return (0);
}

int key_hook(t_data *data)
{
	if (data->keys.key_w)
		move(1, data);
	else if (data->keys.key_s)
		move(-1, data);
	else if (data->keys.key_d || data->keys.key_right)
		rotate(1, data);
	else if (data->keys.key_a || data->keys.key_left)
		rotate(-1, data);
	else if (data->keys.key_esc)
		finish(data);
	return (0);
}
