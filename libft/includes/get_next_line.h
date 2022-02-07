/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarsenio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:54:14 by jarsenio          #+#    #+#             */
/*   Updated: 2021/03/22 14:11:56 by jarsenio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

# define BUFFER_SIZE 500

char		*ft_strjoingnl(char const *s1, char const *s2);
int			get_next_line(int fd, char **line);
size_t		ft_strlengnl(const char *str);
char		*ft_strdupgnl(const char *str);
char		*ft_strchrgnl(const char *s, int c);
char		*ft_substrgnl(char const *s, unsigned int start, size_t len);

#endif
