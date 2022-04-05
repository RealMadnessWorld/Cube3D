/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stupid_norminette.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:28:32 by jarsenio          #+#    #+#             */
/*   Updated: 2022/04/05 19:28:33 by jarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	all_ones(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
	{
		if (str[i] != '1' || str[i] != ' ')
			return (0);
	}
	return (1);
}

int	verify_top(char **map, int x, int y)
{
	if (y != 0 && map[y - 1])
	{
		if (!is_char(map[y - 1][x], "10NSEW"))
			return (0);
	}
	else if (!all_ones(map[y]))
		return (0);
	if (map[y + 1])
	{
		if (!is_char(map[y + 1][x], "10NSEW"))
			return (0);
	}
	else if (!all_ones(map[y]))
		return (0);
	return (1);
}

int	verify_sides(char **map, int x, int y)
{
	int	i;

	i = ft_strlen(map[y]);
	if (x != 0 && map[y][x - 1])
	{
		if (!is_char(map[y][x - 1], "10NSEW"))
			return (0);
	}
	else if (map[y][0] != '1' || map[y][0] != ' ')
		return (0);
	if (map[y][x + 1])
	{
		if (!is_char(map[y][x + 1], "10NSEW"))
			return (0);
	}
	else if (map[y][i] != '1' || map[y][i] != ' ')
		return (0);
	return (1);
}
