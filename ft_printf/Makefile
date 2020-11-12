# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 10:49:13 by sunmin            #+#    #+#              #
#    Updated: 2020/11/12 12:01:58 by sunmin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a
FLAGS		 = -Wall -Wextra -Werror

LIBFT       = lib
SRC_DIR		= src
OBJ_DIR		= obj
HEADER		= header

LIBFT_LIB   = libft.a

SRC			= ft_printf.c \
			  check.c \
			  parcel.c \
			  ft_itoa_base.c \
			  c_proccess.c \
			  d_proccess.c \
			  p_proccess.c \
			  s_proccess.c \
			  u_proccess.c \
			  x_proccess.c \
			  per_proccess.c

SRCS		= $(addprefix $(SRC_DIR)/,$(SRC))
OBJS		= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(HEADER)/printf.h
	mkdir -p obj
	$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean :
	rm -f $(OBJS)
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY: all clean fclean re
