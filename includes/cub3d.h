/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 19:20:48 by jarsenio          #+#    #+#             */
/*   Updated: 2021/05/05 19:20:50 by jarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "colors.h"
# include "keycode_mac.h"
# include <mlx.h>
# include <stdio.h>

/****************************\
*		  Defenitions		 *
\****************************/

# define TITLE "principle vagina"
# define WIN_H 800
# define WIN_W 1200
# define KEYPRESS 2
# define KEYRELEASE 3
# define X_EVENT_KEY_EXIT 17

# define KEY_ESCAPE 53

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
}				t_map;

typedef struct	s_my_d
{
	t_map	map;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_data;

/****************************\
*		  Functions			 *
\****************************/

/*
** Map functions
*/

void	create_map(char	*map, t_data *d);


#endif