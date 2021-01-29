#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "mlx.h"

#define PI 3.14159265359

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
	int		player_size;
	int		player_color;
	double	where_player_x;
	double	where_player_y;
	double	player_center_x;
	double	player_center_y;

	double	player_direction;

	int		ray_x;
	int		ray_y;

	int		floor_color;
	int		temp_color;

	int		key;
	int		key_size;

	int		pov;
	int		move_speed;

	double	density;
	double	index;
}					t_window;

int		draw_ray(t_window *window);
int		erase_ray(t_window *window);
int		draw_grid(t_window *window);
int		put_player(t_window *window);

int		press_key(int key, t_window *window)
{

	window->key = key;
	//esc
	if (window->key == 53)
	{
		write(1, "Quit.\n", 6);
		exit(0);
	}

	erase_ray(window);

	//w
	if (window->key == 13)
	{
		window->index = 0;
		while (window->index < window->move_speed)
		{
			window->temp_color = window->player_color;
			window->player_color = window->floor_color;
			put_player(window);
			window->where_player_x++;
			window->where_player_y += tan(window->player_direction);
			window->player_center_x++;
			window->player_center_y += tan(window->player_direction);
			window->player_color = window->temp_color;

			window->index++;
		}
	}

	//s
	if (window->key == 1)
	{
		window->index = 0;
		while (window->index < window->move_speed)
		{
			window->temp_color = window->player_color;
			window->player_color = window->floor_color;
			put_player(window);
			window->where_player_x--;
			window->where_player_y -= tan(window->player_direction);
			window->player_center_x--;
			window->player_center_y -= tan(window->player_direction);
			window->player_color = window->temp_color;
			
			window->index++;
		}
	}

	//a
	if (window->key == 0)
	{
		window->player_direction += (PI / 360) * window->key_size;
	}

	//d
	if (window->key == 2)
	{
		window->player_direction -= (PI / 360) * window->key_size;
	}

			put_player(window);
	draw_ray(window);
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
	int		index_row;
	int		index_col;

	index_row = 0;
	while (index_row < window->player_size)
	{
		index_col = 0;
		while (index_col < window->player_size)
		{
			mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->where_player_x + index_row, window->where_player_y + index_col, window->player_color);
			index_col++;
		}
		index_row++;
	}
//	mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->where_player_x, window->where_player_y, 0x00);
	return (0);
}

int		draw_ray(t_window *window)
{
	int		x;
	int		y;
	double	tan_p;

	tan_p = tan(window->player_direction);

	window->index = 0;
	while (window->index < window->pov / 2)
	{
		x = 1;
		y = 1;
		while (x + window->player_center_x < window->height && y + window->player_center_y < window->width)
		{
			mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->player_center_x + x, window->player_center_y + y, 0xfff5dd);
			if (y / x >= tan_p)
				x++;
			else
				y++;
		}
		window->index += 1 / window->density;
		tan_p += window->index;
	}
	return (0);
//	mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->ray_x, window->ray_y, 0xfff5ee);
}

int		erase_ray(t_window *window)
{
	int		x;
	int		y;
	double	tan_p;

	tan_p = tan(window->player_direction);

	window->index = 0;
	while (window->index < window->pov / 2)
		{
		x = 1;
		y = 1;
		while (x + window->player_center_x < window->height && y + window->player_center_y < window->width)
		{
			mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->player_center_x + x, window->player_center_y + y, 0x000000);
			if (y / x >= tan_p)
				x++;
			else
				y++;
		}
		window->index += 1 / window->density;
		tan_p += window->index;
	}
	return (0);
//	mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->ray_x, window->ray_y, 0xfff5ee);
}



/*
int		draw_ray(t_window *window)
{
	int		x;
	int		y;
	double	tan_x;

	tan_x = tan(window->player_direction);

	window->player_direction = PI / 5;
	window->ray_x = window->player_center_x;
	window->ray_y = window->player_center_y;
	if (tan_x >= 1)		// 기울기가 1보다 크면 x를 기준으로 y를 움직임
	{
		;//while (window->ray_x < 
	}
	else	// 기울기가 1보다 작으면 y좌표를 기준으로 x를 움직임
	{
		y = 0;
		while (y < 10)
		{
			x = 0;
			while (x < 1 && x < window->height)
			{
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->ray_x + x, window->ray_x + y, 0xfff5ee);
				x = x + tan_x;
			}
			y++;
		}
	}
	mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->ray_x, window->ray_y, 0xfff5ee);

	return (0);
}
*/


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

	window.height = 900;
	window.width = 500;
	window.row_size = window.height / 33;
	window.column_size = window.width / 14;
	window.player_size = 5;
	window.player_color = 0xfff5ee;
	window.where_player_x = window.height / 2;
	window.where_player_y = window.width / 2;
	window.player_center_x = window.where_player_x + window.player_size / 2;
	window.player_center_y = window.where_player_y + window.player_size / 2;

	window.player_direction = PI / 6;
	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, window.height, window.width, "42 sunmin");

	window.floor_color = 0x000000;
	
	window.key_size = 10;
	window.move_speed = 2;

	window.pov = 90;
	window.density = 3;

	// 만약에 grid를 mlx_loop_hook으로 실행하지 않으면 플레이어가 지나가면 사라지는 일회성 격자가 됨.
//	draw_grid(&window);
//	mlx_loop_hook(window.mlx_ptr, draw_grid, &window);

	draw_ray(&window);
//	mlx_loop_hook(window.mlx_ptr, draw_ray, &window);

	put_player(&window);

	mlx_key_hook(window.win_ptr, press_key, &window);
	mlx_loop(window.mlx_ptr);

	return (0);
}
