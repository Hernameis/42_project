/*
    추가할 사항

	1. 플레이어가 벽을 통과하지 못하게(현재 벽 통과시 튕김)
	2. 최대 해상도 락


	개선이 필요한 부분

	1. 해상도를 크게하면 너무 느림
	2. 키보드를 계속 누르고 있으면 튕김
	3. 이동 각도가 미세하게 다름 (wa를 누르고 있으면 이동 각도 전환에 지연 발생)
	4. ws 를 동시에 누르면 움직임이 이상해짐 (ad를 동시에 누르면 하나만 적용되는 걸로 봐서는 if문으로 같이 묶은 게 문제인듯)
	5. 어안렌즈 효과 (벽이 둥글게 보임)

*/

// gcc -L minilibx_mms -lmlx -framework OpenGL -framework Appkit sunmin_3d_main.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "mlx.h"
// #include "libft.h"

#define _USE_MATH_DEFINES	// 정확한 파이값 사용

#define degree_convert M_PI / 180

#define screenHeight	300
#define screenWidth		200
#define mapHeight	10
#define	mapWidth	10

#define key_esc 53
#define key_w 13
#define key_a 0
#define key_s 1
#define key_d 2

typedef struct		s_window
{
	int		**worldmap;

	void	*mlx_ptr;
	void	*win_ptr;

	int		row_size;
	int		column_size;

	double	player_tall;
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
	int		key;
	int		key_size;

	int		ray_x;
	int		ray_y;

	int		floor_color;
	int		temp_color;

	double	move_x;
	double	move_y;
	int		move_speed_x;
	int		move_speed_y;

	int		map_x;
	int		map_y;
	int		map_flag;

	int		pov;

	int		wall_size;

	int		quar_x;
	int		quar_y;

	double	distance;
	double	density;
	double	index;
	double	temp;
	double	sight_wall;
}					t_window;

void	*ft_memcpy(void *dest, const void *src, size_t n);

double	ray_distance(t_window *window, int x, int y);
int		draw_wall(t_window *window);
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
			which_quardrant(window);
				if (window->press_w)
				{
					if (move_tan(window) > fabs(tan(window->player_direction)))
					{
						window->move_x += (window->quar_x);
						window->where_player_x += (window->quar_x) * window->move_speed_x;
					}
					else
					{
						window->move_y += window->quar_y;
						window->where_player_y += (window->quar_y) * window->move_speed_y;
					}
				}
				if (window->press_s)
				{
					if (move_tan(window) > fabs(tan(window->player_direction)))
					{
						window->move_x -= (window->quar_x);
						window->where_player_x -= (window->quar_x) * window->move_speed_x;
					}
					else
					{
						window->move_y -= window->quar_y;
						window->where_player_y -= (window->quar_y) * window->move_speed_y;
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
	draw_ray(window, 0x82eefd);
	return (0);
}

int		draw_wall(t_window *window)
{
	int		i;
	int		j;

	i = 0;
	while (i < screenWidth)
	{
		j = 0;
		while (j < screenHeight)
		{
			if (check_map_flag(window, j, i) == 1)
			{
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, j, i, 0xe5645c);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		draw_grid(t_window *window)
{
	float		j;
	float		i = -1;
	// row
 
	while (i < screenWidth / window->column_size)
	{
		i++;
		j = -1;
		while (j < screenHeight)
		{
			j++;
			mlx_pixel_put(window->mlx_ptr, window->win_ptr, j, i * window->column_size, 0x757c88);
		}
	}

	// column
	i = -1;
	while (i < screenHeight / window->row_size)
	{
		i++;
		j = -1;
		while (j < screenWidth)
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
		if (check_map_flag(window, window->where_player_x, window->where_player_y) != 1)
		{
			index_col = 0;
			while (index_col < window->player_size)
			{
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->where_player_x + index_row, window->where_player_y + index_col, color);
				if (check_map_flag(window, window->where_player_x, window->where_player_y) != 1)
				{
					index_col++;
				}
			}
			if (check_map_flag(window, window->where_player_x, window->where_player_y) != 1)
			{
				index_row++;
			}
		}
		else
			break;
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
	double		j;
	int			a;
	double		put_i;
	int			b;


	put_i = window->pov * (-1 / 2);
	i = 0;
	while (i < screenHeight && check_map_flag(window, window->player_center_x, window->player_center_y != 1))
	{
		window->temp = window->player_direction; 	
		window->player_direction += put_i * degree_convert;
		convert_degree(window);
		b = which_quardrant(window);
			x = 0;
			y = 0;
			while (window->player_center_x + (window->quar_x) * x < screenHeight && window->player_center_y + (window->quar_y) * y < screenWidth)
			{
				if (check_map_flag(window, window->player_center_x + (window->quar_x) * x, window->player_center_y + (window->quar_y) * y) == 0)
				{
					if (y / x >= fabs(tan(window->player_direction)))
					{
						x++;
					}
					else
						y++;
				}
				else
					break;
			}
			window->distance = ray_distance(window, x, y);
			window->sight_wall = (1 / window->distance) * window->wall_size * (screenWidth / 2);
			window->index = 0;
			a = 0;
			while (a < window->sight_wall)
			{
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, (int)i, (screenWidth / 2) - a, color);
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, (int)i, (screenWidth / 2) + a / 2, color);
				a++;
			}
		window->player_direction = window->temp;
		i++;
		double de = (double)window->pov / (double)screenHeight;
		put_i += de;
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
	draw_wall(window);
	return (0);
}

int		which_quardrant(t_window *window)
{
	if (window->player_direction >= degree_convert * 0 && window->player_direction < degree_convert * 90)
	{
		window->quar_x = 1;
		window->quar_y = 1;
		return (1);
	}
	if (window->player_direction >= degree_convert * 90 && window->player_direction < degree_convert * 180)
	{
		window->quar_x = -1;
		window->quar_y = 1;
		return (2);
	}
	if (window->player_direction >= degree_convert * 180 && window->player_direction < degree_convert * 270)
	{
		window->quar_x = -1;
		window->quar_y = -1;
		return (3);
	}
	else
	{
		window->quar_x = 1;
		window->quar_y = -1;
		return (4);
	}
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


	window.row_size = screenHeight / mapHeight;
	window.column_size = screenWidth / mapWidth;
	window.player_size = 10;
	window.player_color = 0xfff5ee;
	window.where_player_x = screenHeight / 2;
	window.where_player_y = screenWidth / 2;
	define_player_center(&window);

	window.player_direction = degree_convert * 60;
	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, screenHeight, screenWidth, "42 sunmin");

	window.floor_color = 0x000000;
	
	window.key_size = 5;
	window.move_speed_x = 3;
	window.move_speed_y = 3;

	window.pov = 60;
	window.density = 1;

	window.press_w = 0;
	window.press_s = 0;
	window.press_a = 0;
	window.press_d = 0;

	window.player_tall = 1.7;

	window.move_x = 0;
	window.move_y = 0;

	window.wall_size = 20;

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


	int j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
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

double	ray_distance(t_window *window, int x, int y)
{
	double	distance;

	return (distance = sqrt(x * x + y * y));
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
