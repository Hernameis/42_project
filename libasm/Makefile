# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/10 09:07:40 by sunmin            #+#    #+#              #
#    Updated: 2021/04/12 12:23:39 by sunmin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

CC = gcc
C_FLAGS = -Wall -Wextra -Werror
NA = nasm
NA_FLAGS = -f macho64

SRCS = srcs/ft_strlen.s\
	   srcs/ft_strcpy.s\
	   srcs/ft_strcmp.s\
	   srcs/ft_write.s\
	   srcs/ft_read.s\
	   srcs/ft_strdup.s\

OBJS = $(SRCS:.s=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	$(NA) $(NA_FLAGS) $(SRCS)

clean :
	rm -rf (OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

bonus : $(NAME)

.PHONY : all clean fclean re bonus
