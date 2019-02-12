# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achoquel <achoquel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 12:01:01 by achoquel          #+#    #+#              #
#    Updated: 2019/02/12 16:55:12 by achoquel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY	:	all clean fclean re

NAME	=	fractol

SRCS	=	srcs/fractal/mandelbrot.c	\
			srcs/fractal/julia.c		\
			srcs/fractal/burning.c		\
			srcs/fractal/evileye.c		\
			srcs/fractal/douady.c		\
			srcs/fractal/dendrite.c		\
			srcs/events/errors.c		\
			srcs/events/event_handler.c	\
			srcs/events/event_handler2.c\
			srcs/main/palette.c			\
			srcs/main/main.c

OBJS	= 	$(SRCS:.c=.o)

CC		=	@gcc

CFLAGS	+=	-Wall -Wextra -Werror

LIB		=	-L./srcs/libft/ -lft -L/usr/local/lib/ -lmlx -lm

FW		= 	-framework OpenGL -framework AppKit

RM		=	@/bin/rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			@make  -C srcs/libft/
			$(CC) -o $(NAME) $(OBJS) $(LIB) $(FW)
			@echo "\033[32m[✓] fractol compiled !\033[0m"

clean	:
			@make -C srcs/libft/ clean
			$(RM) $(OBJS)
			@echo "\033[32m[✓] objects cleaned !\033[0m"

fclean	:	clean
			$(RM) $(NAME)
			$(RM) srcs/libft/libft.a
			@echo "\033[32m[✓] objects, libraries and binaries cleaned !\033[0m"

re		:	fclean all
