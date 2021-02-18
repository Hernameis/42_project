/*
    추가할 사항

	1. 플레이어가 벽을 통과하지 못하게
	2. 최대 해상도 락
	3. 벽에 이미지 삽입
	4. 스프라이트
	5. 천장, 바닥 표현
	6. 벽 구분


	개선이 필요한 부분

	1. 해상도를 크게하면 너무 느림
	2. 키보드를 계속 누르고 있으면 튕김
	3. 이동 각도가 미세하게 다름 (wa를 누르고 있으면 이동 각도 전환에 지연 발생)
	4. ws 를 동시에 누르면 움직임이 이상해짐 (ad를 동시에 누르면 하나만 적용되는 걸로 봐서는 if문으로 같이 묶은 게 문제인듯)
	6. 벽 통과시 튕김
	7. 벽에 가까이 가면 아래에 이상한 이미지 추가로 출력됨

*/

// gcc -L minilibx_mms -lmlx -framework OpenGL -framework Appkit sunmin_3d_main.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "mlx.h"
// #include "libft.h"

#define _USE_MATH_DEFINES	// 정확한 파이값 사용

#define degree_convert (M_PI/180)

#define screenW		300.0
#define screenH		200.0
#define mapHeight	10.0
#define	mapWidth	10.0

#define key_esc 53
#define key_w 13
#define key_a 0
#define key_s 1
#define key_d 2

typedef struct		s_window
{
	int		**worldmap;

	void	*mlx;
	void	*win;

	int		row_size;
	int		column_size;

	double	player_tall;
	int		player_size;
	int		player_color;
	double	w_p_x;
	double	w_p_y;
	double	player_c_x;
	double	player_c_y;
	double	player_dir;
	double	player_dir_degree;
	double	tan_p;

	int		press_w;
	int		press_s;
	int		press_a;
	int		press_d;
	int		key;
	int		key_size;

	double	k;

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

	int		q_x;
	int		q_y;

	double	distance;
	double	density;
	double	index;
	double	temp;
	double	ray_dir;
	double	wall_h;

	void	*screen_ptr;
	int		*screen_data;
	int		screen_height;
	int		screen_width;
	int		screen_size_l;
	int		screen_bpp;
	int		screen_endian;

	void	*wall_n_ptr;
	int		*wall_n_data;
	int		wall_n_height;
	int		wall_n_width;
	int		wall_n_size_l;
	int		wall_n_bpp;
	int		wall_n_endian;

	int		which_wall;
	int		wall_x_y;

	void	*wall_s_ptr;
	int		*wall_s_data;
	int		wall_s_height;
	int		wall_s_width;
	int		wall_s_size_l;
	int		wall_s_bpp;
	int		wall_s_endian;

	void	*wall_w_ptr;
	int		*wall_w_data;
	int		wall_w_height;
	int		wall_w_width;
	int		wall_w_size_l;
	int		wall_w_bpp;
	int		wall_w_endian;

	void	*wall_e_ptr;
	int		*wall_e_data;
	int		wall_e_height;
	int		wall_e_width;
	int		wall_e_size_l;
	int		wall_e_bpp;
	int		wall_e_endian;
}					t_window;

typedef	struct		s_img
{
	void		*ptr;
	int			*data;
	int			height;
	int			width;

	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

void	*ft_memcpy(void *dest, const void *src, size_t n);

int		wall_dir(t_window *window, double x, double y);
double	ray_distance(t_window *window, int x, int y);
int		draw_wall(t_window *window);
int		check_map(t_window *window, int pixel_x, int pixel_y);
int		ft_degree(t_window *window);
void	define_player_center(t_window *window);
int		which_quardrant(t_window *window);
int		draw_pix(t_window *window, int color);
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
	if (fabs(tan(window->player_dir)) >= 1)
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
	draw_pix(window, 0x000000);		// erase_ray
	if (window->press_w || window->press_s)
	{
		put_player(window, 0x000000);
		if (window->press_w || window->press_s)		// w or s key
		{
			which_quardrant(window);
				if (window->press_w)
				{
					if (move_tan(window) > fabs(tan(window->player_dir)))
					{
						window->move_x += (window->q_x);
						window->w_p_x += (window->q_x) * window->move_speed_x;
					}
					else
					{
						window->move_y += window->q_y;
						window->w_p_y += (window->q_y) * window->move_speed_y;;
					}
				}
				if (window->press_s)
				{
					if (move_tan(window) > fabs(tan(window->player_dir)))
					{
						window->move_x -= (window->q_x);
						window->w_p_x -= (window->q_x) * window->move_speed_x;
					}
					else
					{
						window->move_y -= window->q_y;
						window->w_p_y -= (window->q_y) * window->move_speed_y;
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
			window->player_dir -= degree_convert * window->key_size;
		else
			window->player_dir += degree_convert * window->key_size;
		printf("%fl\n", window->player_dir / degree_convert);		//
//		printf("%fl\n", degree_convert);
	}
	convert_degree(window);
	put_player(window, 0xfff5ee);
	draw_pix(window, 0x82eefd);
	return (0);
}

int		draw_wall(t_window *window)
{
	int		i;
	int		j;

	i = 0;
	while (i < screenH)
	{
		j = 0;
		while (j < screenW)
		{
			if (check_map(window, j, i) == 1)
			{
				mlx_pixel_put(window->mlx, window->win, j, i, 0xe5645c);
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
 
	while (i < screenH / window->column_size)
	{
		i++;
		j = -1;
		while (j < screenW)
		{
			j++;
			mlx_pixel_put(window->mlx, window->win, j, i * window->column_size, 0x757c88);
		}
	}

	// column
	i = -1;
	while (i < screenW / window->row_size)
	{
		i++;
		j = -1;
		while (j < screenH)
		{
			j++;
			mlx_pixel_put(window->mlx, window->win, i * window->row_size, j, 0xfff5ee);
		}
	}
	return (0);
}

int		put_player(t_window *window, int color)			// 플레이어의 좌표 정보 포함
{
	int		index_row;
	int		index_col;

	index_row = 0;

	while (index_row < window->player_size)
	{
		if (check_map(window, window->w_p_x, window->w_p_y) != 1)
		{
			index_col = 0;
			while (index_col < window->player_size)
			{
				mlx_pixel_put(window->mlx, window->win, window->w_p_x + index_row, window->w_p_y + index_col, color);
				if (check_map(window, window->w_p_x, window->w_p_y) != 1)
				{
					index_col++;
				}
			}
			if (check_map(window, window->w_p_x, window->w_p_y) != 1)
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



int		draw_pix(t_window *window, int color)
{
	double		x;
	double		y;
	double		screen_w_i;
	double		j;
	double		wall_h_pix;
	double		diff;
	int			none;
	int			dir;
	double		floor;
	double		degree_per_pix;
	double		wall_h_ratio;

	diff = window->pov * -1 / 2;
	degree_per_pix = (double)window->pov / (double)screenW;
	screen_w_i = 0;
	while (diff < window->pov * 1 / 2)	//&& check_map(window, window->player_c_x, window->player_c_y != 1))
	{
//		window->which_wall = 0;
//		window->wall_x_y = 0;
		window->temp = window->player_dir; 	
		window->player_dir += diff * M_PI / 180;
		convert_degree(window);
		none = which_quardrant(window);		// b 를 활용하지는 않음
			x = 0;
			y = 0;
			while (window->player_c_x + (window->q_x * x) >= 0 && window->player_c_x + (window->q_x) * x < screenW && window->player_c_y + (window->q_y) * y >= 0 && window->player_c_y + (window->q_y) * y < screenH)
			{
				if (check_map(window, window->player_c_x + (window->q_x) * x, window->player_c_y + (window->q_y) * y) == 0)
				{
					if (y / x >= fabs(tan(window->player_dir)))
					{
						x++;
//						window->which_wall = window->q_x * 1;
//						window->wall_x_y = 1;
					}
					else
					{
						y++;
//						window->which_wall = window->q_y * 1;
//						window->wall_x_y = 2;
					}
				}
				else
				{
		//			printf("%fl, %fl\n", x, y);	//
					break;
				}
			}
			window->distance = cos(-1 * diff * degree_convert) * ray_distance(window, x, y);			// 어안렌즈 제거 
			window->wall_h = (1 / window->distance) * window->wall_size * (screenH);
			wall_h_pix = 0;
			while (wall_h_pix < window->wall_h)
			{
				dir = wall_dir(window, window->w_p_x + (window->q_x) * x, window->w_p_y + (window->q_y) * y);
				if (check_map(window, window->w_p_x + (window->q_x) * x, window->w_p_y + (window->q_y) * y) != 0)		// 이부분도 추가해야함
				{
					if (1) //window->which_wall == 1)
					{		// 벽의 방향이 바뀌면 x, y 바꾸어야 함
						wall_h_ratio = window->wall_n_width / window->wall_h;
						mlx_pixel_put(window->mlx, window->win, (int)screen_w_i, (screenH / 2) - window->wall_h / 2 + wall_h_pix, window->wall_n_data[(int)(wall_h_pix * wall_h_ratio) * window->wall_n_width + (int)((window->q_x * x) * window->wall_n_width / window->row_size)]);		// 형변환 잘못해주면 세그폴트 뜸

					}
//					else if (dir == 2)
//					else if (dir ==3)
//					else
				}
					wall_h_pix++;
			}
		window->player_dir = window->temp;
		double degree_per_pix = (double)window->pov / (double)screenW;
		screen_w_i++;

		diff += degree_per_pix;
	}
	return (0);
}

int		ft_degree(t_window *window)
{
	window->player_dir_degree = window->player_dir * degree_convert;
	return (0);
}


int		convert_degree(t_window *window)
{
	while (window->player_dir < 0)
	{
		window->player_dir += degree_convert * 360;
	}
	while (window->player_dir > degree_convert * 360)
	{
		window->player_dir -= degree_convert * 360;
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

int		ft_floor(t_window *window)
{
	int i;
	int j;

	int		color_ceil;
	int		color_floo;

	color_floo = 0xf7f7f7;
	color_ceil = 0xbfefff;
	i = 0;
	while (i < screenH / 2)
	{
		j = 0;
		while (j < screenW)
		{
			mlx_pixel_put(window->mlx, window->win, j, i, color_ceil);
			j++;
		}
		i++;
	}
	while (i < screenH)
	{
		j = 0;
		while (j < screenW)
		{
			mlx_pixel_put(window->mlx, window->win, j, i, color_floo);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_loop(t_window *window)
{
// grid를 loop으로 실행하지 않으면 플레이어가 지나가면 사라지는 일회성 격자가 됨.
// 아래쪽에 있는 코드일수록 우선순위 있음
//	draw_wall(window);
//	draw_grid(window);
	ft_floor(window);
	press_key(window);
	return (0);
}

int		which_quardrant(t_window *window)
{
	if (window->player_dir >= degree_convert * 0 && window->player_dir < degree_convert * 90)
	{
		window->q_x = 1;
		window->q_y = 1;
		return (1);
	}
	if (window->player_dir >= degree_convert * 90 && window->player_dir < degree_convert * 180)
	{
		window->q_x = -1;
		window->q_y = 1;
		return (2);
	}
	if (window->player_dir >= degree_convert * 180 && window->player_dir < degree_convert * 270)
	{
		window->q_x = -1;
		window->q_y = -1;
		return (3);
	}
	else
	{
		window->q_x = 1;
		window->q_y = -1;
		return (4);
	}
	return (0);
}



void	define_player_center(t_window *window)
{
	window->player_c_x = window->w_p_x + window->player_size / 2;
	window->player_c_y = window->w_p_y + window->player_size / 2;
	return ;
}

int		check_map(t_window *window, int pixel_x, int pixel_y)
{
	double	num;

	window->map_x = pixel_x / window->row_size;
	window->map_y = pixel_y / window->column_size;
	return (window->worldmap[window->map_y][window->map_x]);
}

int		which_cub(t_window *window, int x, int y)
{
	if (window->worldmap[x / window->row_size][y / window->column_size] == 1)
		return (1);
	return (0);
}

int		wall_dir(t_window *window, double d_x, double d_y)		// 벽을 만나는 좌표 가져옴.
{
	int	x;
	int	y;
	int	x_p_1;
	int	y_p_1;
	int	x_m_1;
	int	y_m_1;

	x = (int)d_x;
	y = (int)d_y;
	x_p_1 = (int)(d_x + 1);
	y_p_1 = (int)(d_y + 1);
	x_m_1 = (int)(d_x - 1);
	y_m_1 = (int)(d_y - 1);


	return (1);

	if (window->player_dir / degree_convert >= 0 && window->player_dir / degree_convert < 90)
		return (1);
	else if (window->player_dir / degree_convert >= 90 && window->player_dir / degree_convert < 180)
		return (2);
	else if (window->player_dir / degree_convert >= 180 && window->player_dir / degree_convert < 270)
		return (3);
	else
		return (4);



	if (which_cub(window, x_p_1, y_p_1) && which_cub(window, x_p_1, y_p_1))
	{
		return (1);
	}
	else if (which_cub(window, x_p_1, y_m_1) && which_cub(window, x_m_1, y_m_1))
	{
		return (2);
	}
	else if (which_cub(window, x_p_1, y_p_1) && which_cub(window, x_p_1, y_m_1))
	{
		return (3);
	}
	else
	{
		return (4);
	}
						// 차라리 그냥 플레이어 각도 기반으로 해볼까?? 동쪽으로 볼때는 동쪽벽을 볼 수 없다
						// x변화 남북, y변화 동서
	return (0);
}

int		converted_location(int x, int y)
{
	int		img_width;
	int		img_height;

	

	return (0);
}

int		main(void)
{
	t_window	window;

	window.row_size = screenW / mapHeight;
	window.column_size = screenH / mapWidth;
	window.player_size = 10;
	window.player_color = 0xfff5ee;
	window.w_p_x = screenW / 2;
	window.w_p_y = screenH / 2;
	define_player_center(&window);

	window.player_dir = 0 * degree_convert;
	window.mlx = mlx_init();
	window.win = mlx_new_window(window.mlx, screenW, screenH, "42 sunmin");

	window.floor_color = 0x000000;
	
	window.key_size = 5;
	window.move_speed_x = 3;
	window.move_speed_y = 3;

	window.pov = 40;
	window.density = 1;

	window.press_w = 0;
	window.press_s = 0;
	window.press_a = 0;
	window.press_d = 0;

	window.player_tall = 1.7;

	window.move_x = 0;
	window.move_y = 0;

	window.wall_size = 20;

	int cub3d_map[(int)mapWidth][(int)mapHeight] = 
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


	window.wall_n_ptr = mlx_xpm_file_to_image(window.mlx, "wall/wall_n.xpm", &window.wall_n_width, &window.wall_n_height);
	window.wall_n_data = (int *)mlx_get_data_addr(window.wall_n_ptr, &window.wall_n_bpp, &window.wall_n_size_l, &window.wall_n_endian);

	window.wall_s_ptr = mlx_xpm_file_to_image(window.mlx, "./wall/wall_s.xpm", &window.wall_s_width, &window.wall_s_height);
	window.wall_s_data = (int *)mlx_get_data_addr(window.wall_s_ptr, &window.wall_s_bpp, &window.wall_s_size_l, &window.wall_s_endian);

	window.wall_w_ptr = mlx_xpm_file_to_image(window.mlx, "./wall/wall_w.xpm", &window.wall_w_width, &window.wall_w_height);
	window.wall_w_data = (int *)mlx_get_data_addr(window.wall_w_ptr, &window.wall_w_bpp, &window.wall_w_size_l, &window.wall_w_endian);

	window.wall_e_ptr = mlx_xpm_file_to_image(window.mlx, "./wall/wall_e.xpm", &window.wall_e_width, &window.wall_e_height);
	window.wall_e_data = (int *)mlx_get_data_addr(window.wall_e_ptr, &window.wall_e_bpp, &window.wall_e_size_l, &window.wall_e_endian);

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
	
	


	mlx_loop_hook(window.mlx, ft_loop, &window);


	draw_pix(&window, 0xfff5ee);

	put_player(&window, window.player_color);

	mlx_hook(window.win, 2, 1L<<0, key_press, &window);
	mlx_hook(window.win, 3, 1L<<1, key_release, &window);


//	t_img img;

//	img.ptr = mlx_new_image(mlx, screenW, screenH);
//	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.line_l, &img.endian);




	mlx_loop(window.mlx);

	return (0);
}

double	ray_distance(t_window *window, int x, int y)
{
	double	distance;

	return (distance = sqrt(x * x + y * y));
}
