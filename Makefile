NAME	= cube3D
OS		= $(shell uname)

MAKEFLAGS	+= -s

CC		= gcc
#FLAGS	= -Wall -Werror -Wextra -g
RM		= rm -rf

# directories
SRCDIR	= ./srcs
OBJDIR	= ./objs
INCDIR	= ./includes/

# files
SRCS	= ${wildcard srcs/*.c}
SRCS	+= ${wildcard srcs/*/*.c}
OBJ		= $(SRCS:.c=.o)

# libft
LIBFT	= ./libft/libft.a
LIB_INC	= -I ./includes/libft

# mlx library
ifeq ($(OS), Linux)
	LIBS	= -lm -L./libft -lft -lmlx -lX11 -lbsd -lXext
	_RED	= \e[31;5;184m
	_GREEN	= \e[38;5;46m
	_YELLOW	= \e[38;5;184m
	_RESET	= \e[0m
else
	LIBS	= -lm -L./libft -lft -lmlx -framework OpenGL -framework AppKit
	_RED	= \x1b[31m
	_GREEN	= \x1b[32m
	_YELLOW	= \x1b[33m
	_RESET	= \x1b[0m
endif

%.o: %.c
		@$(CC) $(FLAGS) -c $< -o $@ -I $(INCDIR) $(LIB_INC)

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJ)
		@$(CC) -o $(NAME) $(FLAGS) -I $(INCDIR) $(OBJ) $(LIBFT) $(LIBS)
		@mkdir -p objs
		@mv ${OBJ} objs
		@echo "$(_GREEN)Like Ghandi once said: \"IT'S ALIVEEEEE\"$(_RESET)"

$(LIBFT):
		@${MAKE} bonus -C libft

clean:
		@$(RM) $(OBJDIR)
		@${MAKE} clean -C libft
		@echo "$(_YELLOW)No, no, no, no, no... Consuela not home!$(_RESET)"

fclean:
		@$(RM) $(OBJDIR)
		@${MAKE} clean -C libft
		@$(RM) $(NAME)
		@$(RM) *.bpm
		@${MAKE} fclean -C libft
		@echo "$(_RED)______________________________________________________________________________$(_RESET)"
		@echo "$(_RED) Farewell! Someone is really going to miss you. But, it's not going to be me! $(_RESET)"
		@echo "$(_RED)‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾$(_RESET)"

re: fclean all

.PHONY: all, clean, fclean, re, obj
