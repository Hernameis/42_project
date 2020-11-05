# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 10:49:13 by sunmin            #+#    #+#              #
#    Updated: 2020/11/05 10:55:07 by sunmin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang											# 나중에 다시 만들어봐야 함.

NAME        = libftprintf.a
LIBFT       = libft
LIBFT_LIB   = libft.a

SRCS        = ./ft_printf.c

OBJS        = $(SRCS:.c=.o)
INCS        = .
RM          = rm -f
LIBC        = ar rc
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

fclean : clean
	$(RM) $(NAME) $(bonus)
	make fclean -C $(LIBFT)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

re : fclean all

bonus : all

.PHONY: all clean fclean re bonus .c.o
