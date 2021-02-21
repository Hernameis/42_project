NAME = Cub3d

CC = gcc
LIBS = -L minilibx_mms -lmlx -framework OpenGL -framework Appkit

$(NAME)	:	${OBJS}
	gcc ${LIBS} ${OBJS}

OBJS = ./srcs/*.c

clean :
	rm -f a.out

re : clean $(NAME)
