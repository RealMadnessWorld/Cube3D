/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:30:25 by jarsenio          #+#    #+#             */
/*   Updated: 2021/11/16 17:57:11 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*chk_img_path(char *path)
{
	if (open((path), O_RDONLY) < 0)
		ft_error(CLR_RED "You're lacking the images... focus please\n" CLR_RST);
	return (path);
}
