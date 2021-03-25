# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/21 10:32:58 by sunmin            #+#    #+#              #
#    Updated: 2021/03/25 08:40:19 by sunmin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = srcs/bitmap.c		\
	   srcs/calc.c			\
	   srcs/calc2.c			\
	   srcs/calc3.c			\
	   srcs/cub3d.c			\
	   srcs/ft_atoi.c		\
	   srcs/ft_split.c		\
	   srcs/get_next_line.c	\
	   srcs/init.c			\
	   srcs/key.c			\
	   srcs/key2.c			\
	   srcs/laser.c			\
	   srcs/laser2.c		\
	   srcs/libft.c			\
	   srcs/map.c			\
	   srcs/parse.c			\
	   srcs/parse2.c		\
	   srcs/parse3.c		\
	   srcs/parse4.c		\
	   srcs/parse5.c		\
	   srcs/parse6.c		\
	   srcs/parse7.c		\
	   srcs/parse8.c		\
	   srcs/pixel.c			\
	   srcs/sprite.c		\
	   srcs/sprite2.c		\
	   srcs/wall.c			\
	   srcs/wall2.c			\

CC = gcc

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRCS)
	make -C minilibx_mms
	make -C	minilibx_opengl
	cp minilibx_mms/libmlx.dylib ./
	cp minilibx_opengl/libmlx.a ./
	gcc $(FLAGS) -L ./minilibx_mms -lmlx -framework openGL -framework Appkit	$(SRCS) -o $(NAME) -O3 -O2

clean : 
	make -C minilibx_mms clean
	make -C minilibx_opengl clean

fclean : clean
	rm -f libmlx.dylib
	rm -f libmlx.a
	rm -f $(NAME)

re : fclean all

bonus : all

.PHONY : all clean fclean re bonus
