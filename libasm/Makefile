# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/10 09:07:40 by sunmin            #+#    #+#              #
#    Updated: 2021/04/12 13:40:26 by sunmin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# 모든 함수 완성시키고 makefile 다시 만들기
# 현재 make도 제대로 안됨 (.o 파일만 만들어지는 정도)

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

%.o : %.s
	$(NA) $(NA_FLAGS) $<

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean :
	rm -rf (OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

bonus : $(NAME)

.PHONY : all clean fclean re bonus
