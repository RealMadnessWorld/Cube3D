/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_num_gen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 19:22:57 by jarsenio          #+#    #+#             */
/*   Updated: 2021/11/16 17:56:44 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	random_num(int lower, int upper)
{
	int	num;

	srand(time(0));
	num = (rand() % (upper - lower + 1)) + lower;
	return (num);
}
