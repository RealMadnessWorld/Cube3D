/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 14:50:17 by jarsenio          #+#    #+#             */
/*   Updated: 2022/01/02 19:00:58 by fmeira           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/****************************\
*		   Includes 		 *
\****************************/

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <time.h>
# include <fcntl.h>
# include <stdlib.h>
# include "get_next_line.h"
# include "colors.h"
# include "keycode_mac.h"

/****************************\
*		 Text colors		 *
\****************************/

/*
** RED = red
** GRN = green
** YLW = yellow
** BLU = blue
** MGT = magenta
** CYN = cyan
** RST = reset
*/

# define CLR_RED "\x1b[31m"
# define CLR_GRN "\x1b[32m"
# define CLR_YLW "\x1b[33m"
# define CLR_BLU "\x1b[34m"
# define CLR_MGT "\x1b[35m"
# define CLR_CYN "\x1b[36m"
# define CLR_RST "\x1b[0m"

/****************************\
*		  Structures		 *
\****************************/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/****************************\
*		   Functions 	     *
\****************************/

void	*ft_memset(void *str, int c, size_t n);
void	ft_bzero(void *str, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memchr(const void *src, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *string);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int i, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_itoa(int n);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
			void (*del)(void *));
void	ft_error(char *error);
int		find_extention(char *str, char *ext);
char	*chk_img_path(char *path);
int		random_num(int lower, int upper);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin_path(char const *s1, char const *s2, char const *s3);

#endif
