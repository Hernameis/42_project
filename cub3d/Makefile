# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/21 10:32:58 by sunmin            #+#    #+#              #
#    Updated: 2021/03/21 10:36:54 by sunmin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = cub3d.c	\

CC = gcc

all : $(NAME)

$(NAME) : $(SRCS)
	make -C minilibx_mms
	make -C	minilibx_opengl
	cp mlx_open
