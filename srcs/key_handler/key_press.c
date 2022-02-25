#include "cub3d.h"

int	key_press(int key, t_data *d, t_calc *c)
{
	double	oldDirX;
	double	oldPlaneX;

	if (key == K_W) //W
	{
		if (!d->map.map[(int)(c->posY + c->dirY * c->moveSpeed)][(int)(c->posX)])
			c->posX += c->dirX * c->moveSpeed;
		if (!d->map.map[(int)(c->posY)][(int)(c->posX + c->dirX * c->moveSpeed)])
			c->posY += c->dirY * c->moveSpeed;
	}
	if (key == K_A) //A
	{
		if (!d->map.map[(int)(c->posY - c->dirY * c->moveSpeed)][(int)(c->posX)])
			c->posX -= c->dirX * c->moveSpeed;
		if (!d->map.map[(int)(c->posY)][(int)(c->posX - c->dirX * c->moveSpeed)])
			c->posY -= c->dirY * c->moveSpeed;
	}
	if (key == K_S) //S
	{
		oldDirX = c->dirX;
		c->dirX = c->dirX * cos(-c->rotSpeed) - c->dirY * sin(-c->rotSpeed);
		c->dirY = oldDirX * sin(-c->rotSpeed) + c->dirY * cos(-c->rotSpeed);
		oldPlaneX = c->planeX;
		c->planeX = c->planeX * cos(-c->rotSpeed) - c->planeY * sin(-c->rotSpeed);
		c->planeY = oldPlaneX * sin(-c->rotSpeed) + c->planeY * cos(-c->rotSpeed);
	}
	if (key == K_D) //D
	{
		oldDirX = c->dirX;
		c->dirX = c->dirX * cos(c->rotSpeed) - c->dirY * sin(c->rotSpeed);
		c->dirY = oldDirX * sin(c->rotSpeed) + c->dirY * cos(c->rotSpeed);
		oldPlaneX = c->planeX;
		c->planeX = c->planeX * cos(c->rotSpeed) - c->planeY * sin(c->rotSpeed);
		c->planeY = oldPlaneX * sin(c->rotSpeed) + c->planeY * cos(c->rotSpeed);
	}
	if (key == K_ESC) //ESC
		x_click(d);
	return (0);
}