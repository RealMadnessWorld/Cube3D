/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:20:48 by jarsenio          #+#    #+#             */
/*   Updated: 2022/04/04 17:07:28 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "colors.h"
# include "keycode_mac.h"
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>

/****************************\
*		  Definitions		 *
\****************************/

# define IS_OS_MAC		1

# define TITLE "principle vagina"
# define KEYPRESS 2
# define KEYRELEASE 3
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define texWidth 64
# define texHeight 64
# define mapWidth 24
# define mapHeight 24
# define WIDTH 1000
# define HEIGHT 600
# define S_DIR 3.1415907
# define E_DIR 1.57079
# define W_DIR -1.57079

# if IS_OS_MAC == 1
# define ESC_KEY 53
# define KEY_ARR_LEFT 123
# define KEY_ARR_RIGHT 124
# define W_KEY 13
# define S_KEY 1
# define D_KEY 2
# define A_KEY 0
# else
# define ESC_KEY 65307
# define KEY_ARR_LEFT 65361
# define KEY_ARR_RIGHT 65363
# define W_KEY 119
# define S_KEY 115
# define D_KEY 100
# define A_KEY 97
# endif

/****************************\
*		  Structures		 *
\****************************/

typedef struct s_keys
{
	int	key_w;
	int	key_s;
	int	key_a;
	int	key_d;
	int	key_esc;
	int	key_right;
	int	key_left;
}	t_keys;

typedef struct	s_map
{
	char	**map;
	int		*no_img;
	int		*so_img;
	int		*we_img;
	int		*ea_img;
	int		*f_color;
	int		*c_color;
	int		width;
	int		height;
	int		play_x;
	int		play_y;
	char	play_dir;
	int		play_starts;
	int		mini_tilesize;
	int		mini_width;
	int		mini_height;
}				t_map;

typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
} t_img;

typedef struct s_rc
{
		double	cameraX;
		double	rayDirX;
		double	rayDirY;
		int		mapX;
		int		mapY;
		double	sideDistX;
		double	sideDistY;
		double	deltaDistX;
		double	deltaDistY;
		double	perpWallDist;
		int		stepX;
		int		stepY;
		int		hit;
		int		side;
		int		lineHeight;
		int		drawStart;
		int		drawEnd;
		double	wallX;
		int		texX;
		double	step;
		double	texPos;
		int		texY;
		int		color;
		double	floorXWall;
		double	floorYWall;
		double	distWall;
		double	distPlayer;
		double	currentDist;
		double	weight;
		double	currentFloorX;
		double	currentFloorY;
		int 	floorTexX;
		int		floorTexY;
		int		checkerBoardPattern;
		int		floorTexture;
} t_rc;

typedef struct s_data
{
	t_keys	keys;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	void	*mlx;
	void	*win;
	t_map	map;
	t_img	img;
	int		buf[HEIGHT][WIDTH];
	double	moveSpeed;
	double	rotSpeed;
	int		**mapito;
	int		empty;
} t_data;

/****************************\
*		  Functions			 *
\****************************/

/*
** Map functions
*/

void	create_map(char	*map, t_data *d);
void	map_dealer(t_data *d, char *str);
void	square_map(t_data *d, int	width);
void	draw_minimap(t_data *d);

/*
** Inits
*/
void	load_image(t_data *data, int *texture, char *path, t_img *img);
void	init_textures(t_data *data);
void	init_data(t_data *data);

/*
** Verifications
*/

void	verify(t_data *d);
int		ready_to_map(t_data *d);
int		check_chars(char *str, char *chars);
void	map_closed(t_data *d, char **map);
void	convert_map(t_data *d);
int		check_texture_identifier(t_data *data, char *path);

/*
** Utils
*/

int		is_empty(char *str);
void	be_free(t_data *d);
int		is_char(char c, char *str);
int		is_empty(char *str);
void	ft_err(t_data *d, char *error);
char	*check_img_path(char *path, t_data *d);
void	ft_be_minus_one(void *str, size_t len);
void	free_map(t_data *d);

/*
** Movement
*/
int		key_press(int key, t_data *data);
int		key_release(int key, t_data *data);
int		key_hook(t_data *data);
void 	rotate(int direction, t_data *data, double rotSpeed);

/*
** RayCasting
*/
void	calculate(t_data *data);
void	draw_floor(t_rc *rc, t_data *data, int x);
void	set_floor(t_rc *rc);
void	draw_walls(t_rc *rc, t_data *data, int x);

/*
** End
*/

int		finish(t_data *data);

/*
** DEBBUGING
*/

void	print_map_shit(t_data *d);

#endif
