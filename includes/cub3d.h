/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:20:48 by jarsenio          #+#    #+#             */
/*   Updated: 2022/03/03 21:53:33 by fmeira           ###   ########.fr       */
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

# define TITLE "principle vagina"
# define WIN_H 800
# define WIN_W 1200
# define KEYPRESS 2
# define KEYRELEASE 3
# define ESC_KEY 27
# define W_KEY 119
# define S_KEY 115
# define D_KEY 100
# define A_KEY 97
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define texWidth 64
# define texHeight 64
# define mapWidth 24
# define mapHeight 24
# define WIDTH 640
# define HEIGHT 480
\
/****************************\
*		  Structures		 *
\****************************/

typedef struct	s_map
{
	char	**map;
	char	*no_img;
	char	*so_img;
	char	*we_img;
	char	*ea_img;
	char	*f_img;
	char	*c_img;
	int		width;
	int		height;
	int		play_x;
	int		play_y;
	char	play_dir;
	int		play_starts;
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
		int		texNum;
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

typedef struct s_info
{
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
	int		**texture;
	double	moveSpeed;
	double	rotSpeed;
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

/*
** Inits
*/
void	load_image(t_data *info, int *texture, char *path, t_img *img);
void	load_texture(t_data *info);
t_data	init_data(void);

/*
** Verifications
*/

void	verify(t_data *d);
int		ready_to_map(t_data *d);
int		check_chars(char *str, char *chars);
void	map_closed(t_data *d, char **map);

/*
** Utils
*/

int		is_empty(char *str);
void	be_free(t_data *d);
int		is_char(char c, char *str);
int		is_empty(char *str);

/*
** Movement
*/
int		key_press(int key, t_data *info);

/*
** RayCasting
*/
void calculate(t_data *info);


/*
** DEBBUGING
*/

void	print_map_shit(t_data *d);

#endif
