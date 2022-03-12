#include "../includes/cub3d.h"

static void move(int direction, t_data *data)
{
	if (direction == 1)
	{
		if (!data->mapito[(int)(data->posX + data->dirX * data->moveSpeed)][(int)(data->posY)])
			data->posX += data->dirX * data->moveSpeed;
		if (!data->mapito[(int)(data->posX)][(int)(data->posY + data->dirY * data->moveSpeed)])
			data->posY += data->dirY * data->moveSpeed;
	}
	else if (direction == -1)
	{
		if (!data->mapito[(int)(data->posX - data->dirX * data->moveSpeed)][(int)(data->posY)])
			data->posX -= data->dirX * data->moveSpeed;
		if (!data->mapito[(int)(data->posX)][(int)(data->posY - data->dirY * data->moveSpeed)])
			data->posY -= data->dirY * data->moveSpeed;
	}
}

void rotate(int direction, t_data *data, double rotSpeed)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = data->dirX;
	oldPlaneX = data->planeX;
	if (direction == 1)
	{
		data->dirX = data->dirX * cos(-rotSpeed) - data->dirY * sin(-rotSpeed);
		data->dirY = oldDirX * sin(-rotSpeed) + data->dirY * cos(-rotSpeed);
		data->planeX = data->planeX * cos(-rotSpeed) - data->planeY * sin(-rotSpeed);
		data->planeY = oldPlaneX * sin(-rotSpeed) + data->planeY * cos(-rotSpeed);
	}
	else if (direction == -1)
	{
		data->dirX = data->dirX * cos(rotSpeed) - data->dirY * sin(rotSpeed);
		data->dirY = oldDirX * sin(rotSpeed) + data->dirY * cos(rotSpeed);
		data->planeX = data->planeX * cos(rotSpeed) - data->planeY * sin(rotSpeed);
		data->planeY = oldPlaneX * sin(rotSpeed) + data->planeY * cos(rotSpeed);
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
		rotate(1, data, data->rotSpeed);
	else if (data->keys.key_a || data->keys.key_left)
		rotate(-1, data, data->rotSpeed);
	else if (data->keys.key_esc)
		finish(data);
	return (0);
}
