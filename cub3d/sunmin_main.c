#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "mlx.h"
// #include "libft.h"

#define _USE_MATH_DEFINES
#define degree_convert M_PI / 180

#define key_esc 53
#define key_w 13
#define key_a 0
#define key_s 1
#define key_d 2

#define screenHeight	500
#define screenWidth		300
#define mapHeight	10		// index는 0부터 시작함에 유의 (10칸짜리임)
#define	mapWidth	10

// gcc -L minilibx_mms -lmlx -framework OpenGL -framework Appkit sunmin_main.c

typedef struct		s_window
{
	int		**worldmap;


	void	*mlx_ptr;
	void	*win_ptr;

	int		height;
	int		width;
	int		row_size;

	int		grid_height_num;
	int		grid_width_num;

	int		column_size;
	int		player_size;
	int		player_color;
	double	where_player_x;
	double	where_player_y;
	double	player_center_x;
	double	player_center_y;

	double	player_direction;
	double	player_direction_degree;

	double	tan_p;

	int		press_w;
	int		press_s;
	int		press_a;
	int		press_d;

	int		ray_x;
	int		ray_y;

	int		floor_color;
	int		temp_color;

	int		key;
	int		key_size;

	double	move_x;
	double	move_y;

	int		map_x;
	int		map_y;

	int		grid_size_x;
	int		grid_size_y;

	int		map_flag;

	int		pov;
	int		move_speed_x;
	int		move_speed_y;

	double	density;
	double	index;
	double	temp;
}					t_window;

void	*ft_memcpy(void *dest, const void *src, size_t n);

int		check_map_flag(t_window *window, int pixel_x, int pixel_y);
int		ft_degree(t_window *window);
void	define_player_center(t_window *window);
int		which_quardrant(t_window *window);
int		draw_ray(t_window *window, int color);
int		draw_grid(t_window *window);
int		put_player(t_window *window, int color);
int		convert_degree(t_window *window);
int		key_press(int key, t_window *window);
int		key_release(int key, t_window *window);
int		ft_loop(t_window *window);
int		where_player_to_go(t_window *window);
double	move_tan(t_window *window);
int		if_tan_bigger_than_one(t_window *window);
void	move_xy_zero(t_window *window);

int		if_tan_bigger_than_one(t_window *window)
{
	if (fabs(tan(window->player_direction)) >= 1)
		return (1);
	return (0);
}

double	move_tan(t_window *window)
{
	return (fabs((window->move_y) / (window->move_x)));
}

void	move_xy_zero(t_window *window)
{
	window->move_x = 0;
	window->move_y = 0;
	return ;
}

int		press_key(t_window *window)
{
	draw_ray(window, 0x000000);		// erase_ray
	if (window->press_w || window->press_s)
	{
		put_player(window, 0x000000);
		if (window->press_w || window->press_s)		// w or s key
		{
			if (which_quardrant(window) == 1)
			{
				if (window->press_w)
				{
					if (move_tan(window) > fabs(tan(window->player_direction)))
					{
						window->move_x++;
						window->where_player_x += window->move_speed_x;
					}
					else
					{
						window->move_y++;
						window->where_player_y += window->move_speed_y;
					}
				}
				if (window->press_s)
				{
					if (move_tan(window) > fabs(tan(window->player_direction)))
					{
						window->move_x--;
						window->where_player_x -= window->move_speed_x;
					}
					else
					{
						window->move_y--;
						window->where_player_y -= window->move_speed_y;
					}
				}
			}
			else if (which_quardrant(window) == 2)
			{
				if (window->press_w)
				{
					if (move_tan(window) > fabs(tan(window->player_direction)))
					{
						window->move_x--;
						window->where_player_x -= window->move_speed_x;
					}
					else
					{
						window->move_y++;
						window->where_player_y += window->move_speed_y;
					}
				}
				if (window->press_s)
				{
					if (move_tan(window) > fabs(tan(window->player_direction)))
					{
						window->move_x++;
						window->where_player_x += window->move_speed_x;
					}
					else
					{
						window->move_y--;
						window->where_player_y -= window->move_speed_y;
					}
				}
			}
			else if (which_quardrant(window) == 3)
			{
				if (window->press_w)
				{
					if (move_tan(window) > fabs(tan(window->player_direction)))
					{
						window->move_x--;
						window->where_player_x -= window->move_speed_x;
					}
					else
					{
						window->move_y--;
						window->where_player_y -= window->move_speed_y;
					}
				}
				if (window->press_s)
				{
					if (move_tan(window) > fabs(tan(window->player_direction)))
					{
						window->move_x++;
						window->where_player_x += window->move_speed_x;
					}
					else
					{
						window->move_y++;
						window->where_player_y += window->move_speed_y;
					}
				}
			}
			else
			{
				if (window->press_w)
				{
					if (move_tan(window) > fabs(tan(window->player_direction)))
					{
						window->move_x++;
						window->where_player_x += window->move_speed_x;
					}
					else
					{
						window->move_y--;
						window->where_player_y -= window->move_speed_y;
					}
				}
				if (window->press_s)
				{
					if (move_tan(window) > fabs(tan(window->player_direction)))
					{
						window->move_x--;
						window->where_player_x -= window->move_speed_x;
					}
					else
					{
						window->move_y++;
						window->where_player_y += window->move_speed_y;
					}
				}
			}
		}
		define_player_center(window);
		put_player(window, 0xfff5ee);
	}
	if (window->press_a || window->press_d)
	{
//		move_xy_zero(window);
		if (window->press_a)
			window->player_direction -= degree_convert * window->key_size;
		else
			window->player_direction += degree_convert * window->key_size;
	}
	convert_degree(window);
	put_player(window, 0xfff5ee);
	draw_ray(window, 0xfff5ee);
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

int		put_player(t_window *window, int color)
{
	int		index_row;
	int		index_col;

	index_row = 0;
	while (index_row < window->player_size)
	{
		index_col = 0;
		while (index_col < window->player_size)
		{
			mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->where_player_x + index_row, window->where_player_y + index_col, color);
			index_col++;
		}
		index_row++;
	}
	return (0);
}

double	ft_tan(double n)
{
	if (tan(n) > 1000)
		return (1000);
	else if (tan(n) < -1000)
		return (-1000);
	else
		return (n);
}

int		draw_ray(t_window *window, int color)
{
	double		x;
	double		y;
	double		i;

	i = window->pov * (-1 / 2);
	while (i < window->pov)
	{
	window->temp = window->player_direction; 	
	window->player_direction += i * degree_convert;
	convert_degree(window);
	if (which_quardrant(window) == 1)							// 1사분면 
	{
		x = 0;
		y = 0;
		while (window->player_center_x + x < window->height && window->player_center_y + y < window->width)
		{
			if (check_map_flag(window, window->player_center_x + x, window->player_center_y + y) == 0)
			{
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->player_center_x + x, window->player_center_y + y, color);
			}
			if (y / x >= fabs(tan(window->player_direction)))
			{
				x++;
			}
			else
				y++;
		}
	}
	else if(which_quardrant(window) == 2)	// 2사분면
	{
		x = 0;
		y = 0;
		while (window->player_center_x - x > 0 && window->player_center_y + y < window->width)
		{
			if (check_map_flag(window, window->player_center_x - x, window->player_center_y + y) == 0)
			{
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->player_center_x - x, window->player_center_y + y, color);
			}
			if (y / x >= fabs(tan(window->player_direction)))
			{
				x++;
			}
			else
				y++;
		}
	}
	else if(which_quardrant(window) == 3)	//3사분면
	{
		x = 0;
		y = 0;
		while (window->player_center_x - x > 0 && window->player_center_y - y >	0)
		{
			if (check_map_flag(window, window->player_center_x - x, window->player_center_y - y) == 0)
			{
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->player_center_x - x, window->player_center_y - y, color);
			}
			if (y / x >= fabs(tan(window->player_direction)))
			{
				x++;
			}
			else
				y++;
		}
	} 
	else			// 4사분면
	{
		x = 0;
		y = 0;
		while (window->player_center_x + x < window->height && window->player_center_y - y > 0)
		{
			if (check_map_flag(window, window->player_center_x + x, window->player_center_y - y) == 0)
			{
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->player_center_x + x, window->player_center_y - y, color);
			}
			if (y / x >= fabs(tan(window->player_direction)))
			{
				x++;
			}
			else
				y++;
		}
	}
	window->player_direction = window->temp;
	i++;
	}
	return (0);
}

int		ft_degree(t_window *window)
{
	window->player_direction_degree = window->player_direction * degree_convert;
	return (0);
}


int		convert_degree(t_window *window)
{
	while (window->player_direction < 0)
	{
		window->player_direction += degree_convert * 360;
	}
	while (window->player_direction > degree_convert * 360)
	{
		window->player_direction -= degree_convert * 360;
	}
	return (0);
}

int		key_press(int key, t_window *window)
{
	if (key == 53)
	{
		exit (0);
	}
	else
	{
		move_xy_zero(window);
		if (key == key_w)
		{
			window->press_w = 1;
		}
		else if (key == key_s)
		{
			window->press_s = 1;
		}
		else if (key == key_a)
		{
			window->press_a = 1;
		}
		else if (key == key_d)
		{
			window->press_d = 1;
		}
	}
	return (0);
}

int		key_release(int key, t_window *window)
{
	move_xy_zero(window);
	if (key == key_w)
	{
		window->press_w = 0;
	}
	else if (key == key_s)
	{
		window->press_s = 0;
	}
	else if (key == key_a)
	{
		window->press_a = 0;
	}
	else if (key == key_d)
	{
		window->press_d = 0;
	}
	return (0);
}

int		ft_loop(t_window *window)
{
	// grid를 loop으로 실행하지 않으면 플레이어가 지나가면 사라지는 일회성 격자가 됨.
	draw_grid(window);
	press_key(window);
	return (0);
}

int		which_quardrant(t_window *window)
{
	if (window->player_direction >= degree_convert * 0 && window->player_direction < degree_convert * 90)
		return (1);
	if (window->player_direction >= degree_convert * 90 && window->player_direction < degree_convert * 180)
		return (2);
	if (window->player_direction >= degree_convert * 180 && window->player_direction < degree_convert * 270)
		return (3);
	else
		return (4);
	return (0);
}



void	define_player_center(t_window *window)
{
	window->player_center_x = window->where_player_x + window->player_size / 2;
	window->player_center_y = window->where_player_y + window->player_size / 2;
	return ;
}

int		check_map_flag(t_window *window, int pixel_x, int pixel_y)
{
	double	num;

	window->map_x = pixel_x / window->row_size;
	window->map_y = pixel_y / window->column_size;
	return (window->worldmap[window->map_y][window->map_x]);
}


int		main(void)
{
	t_window	window;

	window.height = 500;
	window.width = 275;


	window.row_size = screenHeight / mapHeight;
	window.column_size = screenWidth / mapWidth;
	window.player_size = 10;
	window.player_color = 0xfff5ee;
	window.where_player_x = window.height / 2;
	window.where_player_y = window.width / 2;
	define_player_center(&window);

	window.player_direction = degree_convert * 60;
	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, window.height, window.width, "42 sunmin");

	window.floor_color = 0x000000;
	
	window.key_size = 5;
	window.move_speed_x = 3;
	window.move_speed_y = 3;

	window.pov = 60;
	window.density = 10;

	window.press_w = 0;
	window.press_s = 0;
	window.press_a = 0;
	window.press_d = 0;

	window.move_x = 0;
	window.move_y = 0;


	int cub3d_map[mapWidth][mapHeight] = 
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};


	window.worldmap = (int **)malloc(sizeof(int *) * (mapWidth));
	int i = 0;
	while (i < mapWidth)
	{
		window.worldmap[i] = (int *)malloc(sizeof(int) * (mapHeight));
		i++;
	}

//	window.worldmap = ft_memcpy(&window.worldmap, &cub3d_map, mapWidth * mapHeight);	// 오류남

	int j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < 5)
		{
			window.worldmap[j][i] = cub3d_map[j][i];
			i++;
		}	
		j++;
	}

	
	mlx_loop_hook(window.mlx_ptr, ft_loop, &window);

	draw_ray(&window, 0xfff5ee);

	put_player(&window, window.player_color);

	mlx_hook(window.win_ptr, 2, 1L<<0, key_press, &window);
	mlx_hook(window.win_ptr, 3, 1L<<1, key_release, &window);

	mlx_loop(window.mlx_ptr);

	return (0);
}



void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long	i;
	char			*str;

	if (dest == NULL && src == NULL)
		return (NULL);
	str = dest;
	i = 0;
	while (i < n)
	{
		*str++ = *(unsigned char *)src++;
		i++;
	}
	return (dest);
}
