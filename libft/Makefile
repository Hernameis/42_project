# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/12 18:40:21 by sunmin            #+#    #+#              #
#    Updated: 2020/10/13 14:23:29 by sunmin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c\
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

BONUS = 	ft_lstnew.c \
	  		ft_lstadd_front.c \
	  		ft_lstsize.c \
	  		ft_lstlast.c \
	  		ft_lstadd_back.c \
	  		ft_lstdelone.c \
	  		ft_lstclear.c \
	  		ft_lstiter.c \
	  		ft_lstmap.c

SRCS_O = $(subst .c,.o, $(SRCS))
BONUS_O = $(subst .c,.o, $(BONUS))

.c.o : $(SRCS_O)
	$(CC) $(CFLAGS) -c -o $@ $<

SRCS_O : $(SRCS)
	$(CC) $(CFLAGS) -c $^

$(NAME) : $(SRCS_O)
	ar rcs $(NAME) $^

bonus : $(BONUS_O)
	ar rcs $(NAME) $^

clean : $(SRCS_O) $(BONUS_O)
	rm -f $^

fclean : clean
	rm -f $(NAME)

re : clean all

all : $(NAME)
