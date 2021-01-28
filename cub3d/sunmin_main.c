#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mlx.h"

// gcc -L minilibx_mms -lmlx -framework OpenGL -framework Appkit sunmin_main.c
// w == 13, a == 0, s == 1, d == 2, esc == 53

typedef struct		s_window
{
	void	*mlx_ptr;
	void	*win_ptr;

	int		height;
	int		width;
	int		row_size;
	int		column_size;
	int		where_player_x;
	int		where_player_y;
}					t_window;

int		draw_grid(t_window *window);
int		put_player(t_window *window);

int		press_key(int key, t_window *window)
{
	//esc
	if (key == 53)
	{
		write(1, "Quit.\n", 6);
		exit(0);
	}

	//w
	if (key == 13)
	{
		mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->where_player_x, window->where_player_y, 0x000000);
		window->where_player_y--;
		window->where_player_y--;
		put_player(window);
	}

	//a
	if (key == 0)
	{
		mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->where_player_x, window->where_player_y, 0x000000);
		window->where_player_x--;
		window->where_player_x--;
		put_player(window);
	}

	//s
	if (key == 1)
	{
		mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->where_player_x, window->where_player_y, 0x000000);
		window->where_player_y++;
		window->where_player_y++;
		put_player(window);
	}

	//d
	if (key == 2)
	{
		mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->where_player_x, window->where_player_y, 0x000000);
		window->where_player_x++;
		window->where_player_x++;
		put_player(window);
	}
	return (0);
}

int		draw_grid(t_window *window)
{
	float		j;
	float		i = -1;
	// row
 
	while (i < window->width / window->column_size)
	{
		i++;
		j = -1;
		while (j < window->height)
		{
			j++;
			mlx_pixel_put(window->mlx_ptr, window->win_ptr, j, i * window->column_size, 0xfff5ee);
		}
	}
 
	// column
	i = -1;
	while (i < window->height / window->row_size)
	{
		i++;
		j = -1;
		while (j < window->width)
		{
			j++;
			mlx_pixel_put(window->mlx_ptr, window->win_ptr, i * window->row_size, j, 0xfff5ee);
		}
	}
	return (0);
}

int		put_player(t_window *window)
{
	mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->where_player_x, window->where_player_y, 0x00000ff);
	return (0);
}

int		main(void)
{
	t_window	window;
/*
	char		map_2d[33][33];


	map_2d = "      1111111111111111111111111
		        1000000000110000000000001
		        1011000001110000002000001
				1001000000000000000000001
			  111111111011000001110000000000001
			  100000000011000001110111111111111
			  11110111111111011100000010001
			  11110111111111011101010010001
			  11000000110101011100000010001
			  10002000000000001100000010001
		 	  10000000000000001101010010001
			  11000001110101011111011110N0111
			  11110111 1110101 101111010001
			  11111111 1111111 111111111111"
*/

	window.height = 800;
	window.width = 800;
	window.row_size = window.height / 33;
	window.column_size = window.width / 33;
	window.where_player_x = window.height / 2;
	window.where_player_y = window.width / 2;
	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, window.height, window.width, "42 sunmin");

//	draw_grid(&window);
	mlx_loop_hook(window.mlx_ptr, draw_grid, &window);

	put_player(&window);

	mlx_key_hook(window.win_ptr, press_key, &window);
	mlx_loop(window.mlx_ptr);
}
