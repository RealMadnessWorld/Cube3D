# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmeira <fmeira@student.42lisboa.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/19 18:48:01 by jarsenio          #+#    #+#              #
#    Updated: 2021/11/07 02:10:40 by fmeira           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Werror -Wextra

# directories
SRCDIR		= ./srcs/
INCDIR		= ./includes/

SRCS		=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
				ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
				ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
				ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c \
				ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_atoi.c ft_strdup.c \
				ft_calloc.c  ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_putstr_fd.c ft_split.c ft_strjoin.c ft_strtrim.c \
				ft_substr.c ft_strmapi.c ft_itoa.c get_next_line.c \
				ft_error.c find_ext.c check_img_path.c random_num_gen.c \
				gnl_func.c ft_strcmp.c
HEADERS		= ft_printf.h get_next_line.h libft.h

OBJS = $(SRCS:.c=.o)

BONUS		=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
				ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c \
				ft_lstiter.c ft_lstmap.c

BONUS_OBJS	= $(BONUS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADER)
				@ar rcs $(NAME) $(OBJS)
				@rm -rf $(OBJDIR)
				@$(RM) $(OBJS) $(BONUS_OBJS)
				@rm -f *.o

%.o:$(SRCDIR)/%.c
				@$(CC) $(CFLAGS) -I $(INCDIR) $(INCPRINTF) -o $@ -c $<

clean:
				@rm -rf $(OBJDIR)
				@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
				@$(RM) $(NAME)

re:			fclean $(NAME)

bonus:		$(OBJS) $(BONUS_OBJS)
				@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:		all clean fclean re bonus obj
