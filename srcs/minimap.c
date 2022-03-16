// #include "../includes/cub3d.h"

// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <string.h>

// #define X_EVENT_KEY_PRESS		2
// #define X_EVENT_KEY_EXIT		17 //Exit program key code


// # define TILE_SIZE 32
// # define ROWS 11
// # define COLS 15
// # define WIDTH COLS * TILE_SIZE
// # define HEIGHT ROWS * TILE_SIZE
// # define PI 3.14159265359

// # define TO_COORD(X, Y) ((int)floor(Y) * WIDTH + (int)floor(X))

// typedef struct	s_img
// {
// 	void	*img;
// 	int		*d;

// 	int		size_l;
// 	int		bpp;
// 	int		endian;
// }				t_img;

// typedef struct	s_game
// {
// 	void	*mlx;
// 	void	*win;
// 	t_img	img;
// 	double	p_x;
// 	double	p_y;
// 	double	p_dx;
// 	double	p_dy;
// 	int		p_angle;
// 	char		map[ROWS][COLS];
// }				t_game;

// //Draw the line by DDA algorithm
// void	draw_line(t_game *game, double x1, double y1, double x2, double y2)
// {
// 	double	deltaX;
// 	double	deltaY;
// 	double	step;

// 	deltaX = x2 - x1;
// 	deltaY = y2 - y1;
// 	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
// 	deltaX /= step;
// 	deltaY /= step;
// 	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
// 	{
// 		game->img.d[TO_COORD(x1, y1)] = 0xb3b3b3;
// 		x1 += deltaX;
// 		y1 += deltaY;
// 	}
// }

// void 	draw_lines(t_game *game)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	while (i < COLS)
// 	{
// 		draw_line(game, i * TILE_SIZE, 0, i * TILE_SIZE, HEIGHT);
// 		i++;
// 	}
// 	draw_line(game, COLS * TILE_SIZE - 1, 0, COLS * TILE_SIZE - 1, HEIGHT);
// 	j = 0;
// 	while (j < ROWS)
// 	{
// 		draw_line(game, 0, j * TILE_SIZE, WIDTH, j * TILE_SIZE);
// 		j++;
// 	}
// 	draw_line(game, 0, ROWS * TILE_SIZE - 1, WIDTH, ROWS * TILE_SIZE - 1);
// }

// void	draw_rectangle(t_game *game, int x, int y)
// {
// 	int i;
// 	int j;

// 	x *= TILE_SIZE;
// 	y *= TILE_SIZE;
// 	i = 0;
// 	while (i < TILE_SIZE)
// 	{
// 		j = 0;
// 		while (j < TILE_SIZE)
// 		{
// 			game->img.d[(y + i) * WIDTH + x + j] = 0x0000FF;
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int	is_circle(double i, double j, double x, double y, double radius)
// {
// 	double dist;

// 	dist = sqrt(powf(j - x, 2.) + powf(i - y, 2.));
// 	if (dist <= radius)
// 		return (1);
// 	return (0);
// }

// void	draw_player(t_game *game, double x, double y)
// {
// 	double radius = 4;
// 	double 	i;
// 	double	j;

//  	i = 0;
// 	while (i < HEIGHT)
// 	{
// 		j = 0;
// 		while (j < WIDTH)
// 		{
// 			if (is_circle(i, j, x, y, radius))
// 				game->img.d[(int)i * WIDTH + (int)j] = 0xFFFF00;
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	draw_minimap(t_game *game)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	while (i < ROWS)
// 	{
// 		j = 0;
// 		while (j < COLS)
// 		{
// 			if (game->map[i][j] == '1')
// 				draw_rectangle(game, j, i);

// 			else if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
// 						|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
// 			{
// 				game->p_x = (j * TILE_SIZE + TILE_SIZE/2);
// 				game->p_y = (i * TILE_SIZE + TILE_SIZE/2);
// 				// game->p_ = game->map[i][j];
// 				draw_player(game, game->p_x, game->p_y);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	draw_lines(game);
// }

// int		deal_key(int key_code)
// {
// 	if (key_code == ESC_KEY)
// 		exit(0);
// 	return (0);
// }

// int 	close_it(void)
// {
// 		exit(0);
// }

// void	minimap_init(t_game *game)
// {
// 	char map[ROWS][COLS] = {
// 	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
// 	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
// 	{'1', '0', '0', '0', '1', '0', '1', '0', '0', '0', '0', '0', '1', '0', '1'},
// 	{'1', '1', '1', '1', 'S', '0', '0', '0', '0', '0', '1', '0', '1', '0', '1'},
// 	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1', '0', '1'},
// 	{'1', '0', '0', '0', '0', '0', '1', '0', '1', '1', '1', '1', '1', '0', '1'},
// 	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// 	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// 	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
// 	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
// 	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
// 	};
// 	memcpy(game->map, map, sizeof(char) * ROWS * COLS);
// }

// void	window_init(t_game *game)
// {
// 	game->mlx = mlx_init();
// 	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "mlx 42");
// }

// void	img_init(t_game *game)
// {
// 	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
// 	game->img.d = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
// }

// int		main_loop(t_game *game)
// {
// 	draw_minimap(game);
// 	// draw_lines(game);
// 	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
// 	return (0);
// }
// //---------------------------Draw Rays and Walls--------------------------------
// float distance(ax, ay, bx, by, ang) { return cos(degToRad(ang)) * (bx - ax) - sin(degToRad(ang)) * (by - ay); }

// void drawRays2D(t_game *game)
// {
// 	int r, mx, my, mp, dof, side;
// 	float vx, vy, rx, ry, ra, xo, yo, disV, disH;

// 	ra = FixAng(game->p_angle + 30); // ray set back 30 degrees

// 	for (r = 0; r < 60; r++)
// 	{
// 		//---Vertical---
// 		dof = 0;
// 		side = 0;
// 		disV = 100000;
// 		float Tan = tan(degToRad(ra));
// 		if (cos(degToRad(ra)) > 0.001)
// 		{
// 			rx = (((int)game->p_x >> 6) << 6) + 64;
// 			ry = (game->p_x - rx) * Tan + game->p_y;
// 			xo = 64;
// 			yo = -xo * Tan;
// 		} // looking left
// 		else if (cos(degToRad(ra)) < -0.001)
// 		{
// 			rx = (((int)game->p_x >> 6) << 6) - 0.0001;
// 			ry = (game->p_x - rx) * Tan + game->p_y;
// 			xo = -64;
// 			yo = -xo * Tan;
// 		} // looking right
// 		else
// 		{
// 			rx = game->p_x;
// 			ry = game->p_y;
// 			dof = 8;
// 		} // looking up or down. no hit

// 		while (dof < 8)
// 		{
// 			mx = (int)(rx) >> 6;
// 			my = (int)(ry) >> 6;
// 			mp = my * COLS + mx;
// 			if (mp > 0 && mp < COLS * ROWS && game->map[mp] == 1)
// 			{
// 				dof = 8;
// 				disV = cos(degToRad(ra)) * (rx - game->p_x) - sin(degToRad(ra)) * (ry - game->p_y);
// 			} // hit
// 			else
// 			{
// 				rx += xo;
// 				ry += yo;
// 				dof += 1;
// 			} // check next horizontal
// 		}
// 		vx = rx;
// 		vy = ry;

// 		//---Horizontal---
// 		dof = 0;
// 		disH = 100000;
// 		Tan = 1.0 / Tan;
// 		if (sin(degToRad(ra)) > 0.001)
// 		{
// 			ry = (((int)py >> 6) << 6) - 0.0001;
// 			rx = (py - ry) * Tan + game->p_x;
// 			yo = -64;
// 			xo = -yo * Tan;
// 		} // looking up
// 		else if (sin(degToRad(ra)) < -0.001)
// 		{
// 			ry = (((int)py >> 6) << 6) + 64;
// 			rx = (py - ry) * Tan + game->p_x;
// 			yo = 64;
// 			xo = -yo * Tan;
// 		} // looking down
// 		else
// 		{
// 			rx = game->p_x;
// 			ry = game->p_y;
// 			dof = 8;
// 		} // looking straight left or right

// 		while (dof < 8)
// 		{
// 			mx = (int)(rx) >> 6;
// 			my = (int)(ry) >> 6;
// 			mp = my * COLS + mx;
// 			if (mp > 0 && mp < COLS * ROWS && game->map[mp] == 1)
// 			{
// 				dof = 8;
// 				disH = cos(degToRad(ra)) * (rx - game->p_x) - sin(degToRad(ra)) * (ry - game->p_y);
// 			} // hit
// 			else
// 			{
// 				rx += xo;
// 				ry += yo;
// 				dof += 1;
// 			} // check next horizontal
// 		}

// 		glColor3f(0, 0.8, 0);
// 		if (disV < disH)
// 		{
// 			rx = vx;
// 			ry = vy;
// 			disH = disV;
// 			glColor3f(0, 0.6, 0);
// 		} // horizontal hit first
// 		glLineWidth(2);
// 		glBegin(GL_LINES);
// 		glVertex2i(game->p_x, py);
// 		glVertex2i(rx, ry);
// 		glEnd(); // draw 2D ray

// 		int ca = FixAng(game->p_a - ra);
// 		disH = disH * cos(degToRad(ca)); // fix fisheye
// 		int lineH = (mapS * 320) / (disH);
// 		if (lineH > 320)
// 		{
// 			lineH = 320;
// 		}								  // line height and limit
// 		int lineOff = 160 - (lineH >> 1); // line offset

// 		glLineWidth(8);
// 		glBegin(GL_LINES);
// 		glVertex2i(r * 8 + 530, lineOff);
// 		glVertex2i(r * 8 + 530, lineOff + lineH);
// 		glEnd(); // draw vertical wall

// 		ra = FixAng(ra - 1); // go to next ray
// 	}
// } //-----------------------------------------------------------------------------

// int FixAng(int a)
// {
// 	if(a > 359)
// 		a -= 360;
// 	if(a < 0)
// 		a += 360;
// 	return (a);
// }

// double degToRad(int a)
// {
// 	return (a * PI / 180.0);
// }

// void Buttons(int key, t_game *game)
// {
// 	if (key == A_KEY)
// 	{
// 		game->p_angle += 5;
// 		game->p_angle = FixAng(game->p_angle);
// 		game->p_dx = cos(degToRad(game->p_angle));
// 		game->p_dy = -sin(degToRad(game->p_angle));
// 	}
// 	if (key == D_KEY)
// 	{
// 		game->p_angle -= 5;
// 		game->p_angle = FixAng(game->p_angle);
// 		game->p_dx = cos(degToRad(game->p_angle));
// 		game->p_dy = -sin(degToRad(game->p_angle));
// 	}
// 	if (key == W_KEY)
// 	{
// 		game->p_x += game->p_dx * 5;
// 		game->p_y += game->p_dy * 5;
// 	}
// 	if (key == S_KEY)
// 	{
// 		game->p_x -= game->p_dx * 5;
// 		game->p_y -= game->p_dy * 5;
// 	}

// int	move(int key_code, t_game *game)
// {
// 	if (key_code == ESC_KEY)
// 		exit(0);
// 	if (key_code == W_KEY || key_code == S_KEY || key_code == A_KEY || key_code == D_KEY)
// 	{
// 		if (can_move(key_code, game))
// 		{
// 			update_pos(key_code, game);
// 			draw_player(game, game->p_x, game->p_y);
// 		}
// 	}
// 	return (0);
// }


// int		main(void)
// {
// 	t_game game;

// 	minimap_init(&game);
// 	window_init(&game);
// 	img_init(&game);
// 	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
// 	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close_it, &game);
// 	// mlx_key_hook(game.win, &move, &game);
// 	mlx_loop_hook(game.mlx, &main_loop, &game);
// 	mlx_loop(game.mlx);
// }
