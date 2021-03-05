NAME = Cub3d

CC = gcc -Wall -Wextra -Werror
LIBS = -L minilibx_mms -lmlx -framework OpenGL -framework Appkit

$(NAME)	:	${OBJS}
	${CC} ${LIBS} ${OBJS}

OBJS = ./srcs/*.c

clean :
	rm -f a.out

re : clean $(NAME)
