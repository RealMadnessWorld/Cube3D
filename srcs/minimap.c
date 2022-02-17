#include "cub3d.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_EXIT		17 //Exit program key code

#define KEY_ESC			53

# define TILE_SIZE 32
# define ROWS 11
# define COLS 15
# define WIDTH COLS * TILE_SIZE
# define HEIGHT ROWS * TILE_SIZE

# define TO_COORD(X, Y) ((int)floor(Y) * WIDTH + (int)floor(X))

typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_img	img;

	char		map[ROWS][COLS];
}				t_game;

//Draw the line by DDA algorithm
void	draw_line(t_game *game, double x1, double y1, double x2, double y2)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		game->img.data[TO_COORD(x1, y1)] = 0xb3b3b3;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void 	draw_lines(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < COLS)
	{
		draw_line(game, i * TILE_SIZE, 0, i * TILE_SIZE, HEIGHT);
		i++;
	}
	draw_line(game, COLS * TILE_SIZE - 1, 0, COLS * TILE_SIZE - 1, HEIGHT);
	j = 0;
	while (j < ROWS)
	{
		draw_line(game, 0, j * TILE_SIZE, WIDTH, j * TILE_SIZE);
		j++;
	}
	draw_line(game, 0, ROWS * TILE_SIZE - 1, WIDTH, ROWS * TILE_SIZE - 1);
}

void	draw_rectangle(t_game *game, int x, int y)
{
	int i;
	int j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			game->img.data[(y + i) * WIDTH + x + j] = 0x0000FF;
			j++;
		}
		i++;
	}
}

int	is_circle(double i, double j, double x, double y, double radius)
{
	double dist;

	dist = sqrt(powf(j - x, 2.) + powf(i - y, 2.));
	if (dist <= radius)
	{
		if (radius - dist < 1.00000000)
			return (0);
		return (1);
	}
	return (0);
}

void	draw_player(t_game *game, double x, double y)
{
	int 	i;
	int		j;
	double	x1;
	double 	y1;

	x1 = x;
	y1 = y;
	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			if (is_circle((double)i, (double)j, (x1 + (TILE_SIZE / 2 )), (y1 + (TILE_SIZE / 2 )), 8))
				game->img.data[((int)y + (int)i) * WIDTH + (int)x + (int)j] = 0xFFFF00;
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < ROWS)
	{
		j = 0;
		while (j < COLS)
		{
			if (game->map[i][j] == '1')
				draw_rectangle(game, j, i);
			else if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
						|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
				draw_player(game, j, i);
			j++;
		}
		i++;
	}
}

int		deal_key(int key_code)
{
	if (key_code == KEY_ESC)
		exit(0);
	return (0);
}

int 	close_it(void)
{
		exit(0);
}

void	minimap_init(t_game *game)
{
	char map[ROWS][COLS] = {
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
	{'1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '1', '1', 'E', '1', '1', '1', '1', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
	};
	memcpy(game->map, map, sizeof(char) * ROWS * COLS);
}

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "mlx 42");
}

void	img_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
}

int		main_loop(t_game *game)
{
	draw_minimap(game);
	// draw_lines(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

int		main(void)
{
	t_game game;

	minimap_init(&game);
	window_init(&game);
	img_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close_it, &game);

	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}
