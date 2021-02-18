/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sunmin_3d_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 17:11:31 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/18 15:30:07 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
/*
    **** 추가할 사항
	
	2. 스프라이트

	**** 개선이 필요한 부분


	**** 보충 사항
	1. 키보드 동시 입력
	2. 레이저와 동시에 배경 출력



*/

// gcc -L minilibx_mms -lmlx -framework OpenGL -framework Appkit sunmin_3d_main.c
// make re에 모두 포함

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "mlx.h"

#define _USE_MATH_DEFINES	// 정확한 파이값 사용

// 키보드 대응 숫자
#define key_esc 53
#define key_w 13
#define key_a 0
#define key_s 1
#define key_d 2

// 1도  = M_PI / 180



// 구조체 선언

typedef struct		s_img
{
	void		*ptr;
	int			*data;
	int			height;
	int			width;

	int			size_l;
	int			bpp;
	int			endian;
}					t_img;

typedef struct		s_wall
{
	//
	void		*n_ptr;
	char		*n_data;
	int			n_height;

	int			n_size_l;
	int			n_bpp;
	int			n_endian;


	//
	void		*s_ptr;
	int			*s_data;
	int			s_height;

	int			s_size_l;
	int			s_bpp;
	int			s_endian;

	//
	void		*w_ptr;
	int			*w_data;
	int			w_height;

	int			w_size_l;
	int			w_bpp;
	int			w_endian;

	//
	void		*e_ptr;
	int			*e_data;
	int			e_height;

	int			e_size_l;
	int			e_bpp;
	int			e_endian;
}					t_wall;

typedef struct		s_win
{
	//	필수
	void		*mlx;
	void		*win;

	//	메인 이미지
	void		*img_ptr;
	int			*data;
	int			img_height;

	int			size_l;
	int			bpp;
	int			endian;

	//	화면 
	double		s_w;
	double		s_h;

	double		s_w_per_m;		//		맵 하나당 screen 가로 길이
	double		s_h_per_m;		//		맵 하나당 screen 세로 길이

	//	맵
	int			**map;

	double		m_w;
	double		m_h;

	int			m_wid;
	int			m_hei;

	//	시야각
	double		pov;			// 수평 시야각
	double		pov_v;			// 수직 시야각
	double		pov_degree;		// 각도 기준 수평 시야각

	//	벽
	double		wall_len;		// 벽 길이(화면상 표기되는 것이 아닌 실제 길이)

	//	플레이어
	double		p_d;		// 플레이어가 보고 있는 방향
	double		p_x;		// 플레이어의 x 좌표	(스크린 기준이 아닌 맵 기준)
	double		p_y;		// 플레이어의 y 좌표	(스크린 기준이 아닌 맵 기준)
	double		m_s;		// 움직이는 속도

	// 키보드
	int			press_w;	// w 키가 눌려있으면 1, 아니면 0
	int			press_s;
	int			press_a;
	int			press_d;

	int			key_ws;
	int			key_ad;

	double		m_x;		// 절대값 함수 fabs를 사용해야 해서 double로 선언
	double		m_y;

	// 수학
	int			q_x;
	int			q_y;
	int			q_l_x;
	int			q_l_y;
	double		lens_deg;

	// 기타
	int			idx_pix;	// 가로 인덱스
	double		temp;


}			t_win;



//	함수 프로토타입 선언 

double	within_2_pi_return(double degree);
int		put_change(t_win *win);
double		distance_from_player(t_win *win, int x, int y);		// 두 점 사이의 거리 구하기(플레이어, 점(x, y)
int		fill_grid(t_win *win, int x, int y);
int		draw_grid(t_win *win);
int		ft_pixel_put(t_win *win, int x, int y, int color);
int		init_minimap(t_win *win);
int		cub3d_map(t_win *win, int col, int row);
int		cal_quar(t_win *win);
int		within_2_pi(t_win *win);
int		if_key_pressed(t_win *win);
int		ft_loop(t_win *win);
int		put_player(t_win *win);
int		init_m_xy(t_win *win);
int		put_dir(t_win *win);
int		put_laser(t_win *win);

int		ceiling_and_floor(t_win *win)		// 바닥, 천장 그리는 함수
{
	int i;
	int j;

	int color;
	int	ceil_color;
	int	floor_color;

	ceil_color = 0x87ceeb;
	floor_color = 0x888888;
	color = ceil_color;
	i = 0;
	while (i < win->s_h)
	{
		if (i > win->s_h / 2)
			color = floor_color;
		j = 0;
		while (j < win->s_w)
		{
			ft_pixel_put(win, j, i, color);
	//		win->data[(win->size_l / (win->bpp / 8) * i) + j] = color;
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_pixel_put(t_win *win, int x, int y, int color)
{
		win->data[(win->size_l / (win->bpp / 8) * y) + x] = color;
		return (0);
}

int		check_grid(t_win *win, int x, int y)
{
	return (win->map[(int)((y) / (win->s_h_per_m))][(int)((x) / (win->s_w_per_m))]);
}

int		ft_loop(t_win *win)
{
//	ceiling_and_floor(win);		// 바닥, 천장 그리는 야매 함수

	if_key_pressed(win);
	


//	put_player(win);
//	put_laser(win);
//	put_dir(win);

	mlx_put_image_to_window(win->mlx, win->win, win->img_ptr, 0, 0);
	return (0);
}

int		key_release(int key, t_win *win)
{
	init_m_xy(win);
	if (key == key_w || key == key_s)
	{

		if (key == key_w)
		{
			win->press_w = 0;
		}
		else if (key == key_s)
		{
			win->press_s = 0;
		}
	}
	else if (key == key_a)
	{
		win->press_a = 0;
	}
	else if (key == key_d)
	{
		win->press_d = 0;
	}
	return (0);
}

int		if_key_ws(t_win *win)
{
	if (win->press_w && !win->press_s)
	{
		win->key_ws = 1;
		return (1);
	}
	else if (win->press_s && !win->press_w)
	{
		win->key_ws = -1;
		return (-1);
	}
	win->key_ws = 0;
	return (0);
}

int		if_key_ad(t_win *win)
{
	if (win->press_d && !win->press_a)
	{
		win->key_ad = +1;
		return (+1);
	}
	else if (win->press_a && !win->press_d)
	{
		win->key_ad = -1;
		return (-1);
	}
	win->key_ad = 0;
	return (0);
}

int		if_key_pressed(t_win *win)
{
	
	double	degree;
	double	degree_convert;
	double	sense;

	double	ray_x;
	double	ray_y;

	sense = 5;
	degree_convert = M_PI / 180;
	degree = degree_convert * sense;
	within_2_pi(win);
	cal_quar(win);
	if (win->press_w || win->press_s)
	{
		if(check_grid(win, (win->p_x * (win->s_w_per_m + win->q_x * win->key_ws)), (win->p_y) * (win->s_h_per_m + win->q_y * win->key_ws)) != 1)		// 축지법으로 확인
		{
			if_key_ws(win);		
			if (fabs(tan(win->p_d)) < fabs(win->m_y / win->m_x))
			{
				if (win->p_x + (win->key_ws) * 1 / win->s_w_per_m >= 0 && win->p_x + (win->key_ws) * 1 / win->s_w_per_m <= win->m_w)		// 맵 가로 끝에서 못 움직이게
				{
						win->p_x += (win->q_x) * (win->key_ws) * 1 / win->s_w_per_m;
				}
				win->m_x += (win->q_x) * (win->key_ws) * 1;
			}
			else
			{
				if (win->p_x + (win->key_ws) * 1 / win->s_w_per_m >= 0 && win->p_x + (win->key_ws) * 1 / win->s_w_per_m <= win->m_w)		// 맵 세로  끝에서 못 움직이게
				{
					win->p_y += (win->q_y) * (win->key_ws) * 1 / win->s_h_per_m;
				}
				win->m_y += (win->q_y) * (win->key_ws) * 1;
			}
		}
//	printf("%.2f\n%.2f, %.2f\n%.2f, %.2f\n\n", (win->p_d * 180 / M_PI), win->p_x, win->p_y, win->p_x * win->s_w_per_m, win->p_y * win->s_h_per_m);
	}
	if (win->press_a || win->press_d)
	{
		if_key_ad(win);
		win->p_d += (win->key_ad) * M_PI / 180; //* degree;		// 방향 전환


//	printf("%.2f\n%.2f, %.2f\n%.2f, %.2f\n", (win->p_d * 180 / M_PI), win->m_x, win->m_y, win->p_x, win->p_y);
	}
//	printf("dir %.2f\n", win->p_d);
	put_change(win);
	return (0);
}

int		put_change(t_win *win)
{


	put_laser(win);
	put_dir(win);
	put_player(win);

	draw_grid(win);


	return (0);
}

/*
double		move_to_next(t_win *win, double x_or_y)	/// 수정중
{
	if (check_grid(win, x, y) != 1)
	{
		;
	}
	return (0);
}
*/

int		key_press(int key, t_win *win)
{
	if (key == key_esc)
	{
		exit (0);
	}
	else
	{
		if (key == key_w)
		{
			win->press_w = 1;
		}
		else if (key == key_s)
		{
			win->press_s = 1;
		}
		else if (key == key_a)
		{
			win->press_a = 1;
		}
		else if (key == key_d)
		{
			win->press_d = 1;
		}
	}
	return (0);
}

int		init_m_xy(t_win *win)
{
	win->m_x = 0.000001;
	win->m_y = 0.000001;
	return (0);
}

int		put_player(t_win *win)		// 플레이어 위치 점으로 표시
{
	int i;		// 가로 인덱스
	int j;		// 세로 인덱스
	int p_x_on_scr;
	int	p_y_on_scr;
	// 맵 아래쪽으로 가면 튕김 && 그냥 맵에서 판단하는 걸로

	p_x_on_scr = (int)(win->p_x * win->s_w_per_m);		// 플레이어의 맵상 좌표를 스크린상좌표로 전환
	p_y_on_scr = (int)(win->p_y * win->s_h_per_m);
	i = -3;
	while (++i < 3)
	{
		j = -3;
		while (++j < 3)
		{
			ft_pixel_put(win, p_x_on_scr + i, p_y_on_scr + j, 0x9999ff);
		}
	}
	return (0);
}

int		draw_sprite(t_win *win)
{
	return (0);
}

int		draw_wall(t_win *win, double dis) // 벽 한 줄기 그리기 
{
	double	wall_height_half;		// 벽길이 반쪽
	int		idx;		// 세로 인덱스
	int		start;
	int		end;
	double	deg_per_pix;

	deg_per_pix = win->pov / win->s_h;
//	printf("%.2f\n", dis);
	wall_height_half = (win->pov_v / 2) * tan((win->pov_v * 180 / M_PI) / 2) * win->wall_len / (dis / 10); //  * fabs(cos(win->p_d));
	start = (win->s_h / 2) - (int)wall_height_half;
	if (start < 0)
	{
		start = 0;
	}
	end = (int)(wall_height_half) + (int)(win->s_h / 2);
	if (end > win->s_h)
	{
		end = win->s_h;
	}
//	printf("%.2f %d %d\n", wall_height_half, start, end);

	idx = 0;		// 배경까지 같이 출력
//	idx = start;		// 벽 그리기 시작하는 높이
	while (idx < win->s_h)
	{
		if (idx >= start && idx < end)
		{
			ft_pixel_put(win, win->idx_pix, idx, 0xb22222);
		}
		else
		{
			if (idx < win->s_h / 2)
			{
				ft_pixel_put(win, win->idx_pix, idx, 0x50bcdf);
			}
			else
			{
				ft_pixel_put(win, win->idx_pix, idx, 0xc68a12);
			}
		}
		idx++;
	}

//	*/
	return (0);
}


double		distance_from_player(t_win *win, int x, int y)		// 두 점 사이의 거리 구하기(플레이어, 점(x, y))
{															// 여기서 벽 그리는 함수까지 호출
	int		height;
	int		width;
	double	result;

	height = fabs(win->p_x - x);
	width = fabs(win->p_y - y);
	result = sqrt(height * height + width * width);
	draw_wall(win, result);		//벽 그리는 부분
//	printf("%.2f\n", result);
	return (result);
}

int		draw_grid(t_win *win)
{
	int		row;
	int		col;

	col = 0;
	while (col < win->s_h)
	{
		row = 0;
		while (row < win->s_w)
		{
	//		printf("%d %d\n", row, col);
			if (row % (int)win->s_h_per_m  == 0 || col % (int)win->s_w_per_m  == 0)
			{
				if (check_grid(win, row, col) == 1)
				{
					ft_pixel_put(win, row, col, 0xfff5ee);
				}
			}
//			fill_grid(win, row, col);
			row++;
		}
		col++;
	}
	return (0);
}

int		fill_grid(t_win *win, int x, int y)
{
	if (check_grid(win, x, y))
	{
		ft_pixel_put(win, x, y, 0xc1c1c1);
	}
	return (0);
}

int		put_laser(t_win *win)		// put multi-ray	레이저 쏘는데서 바로 거리까지 계산		&& 레이저가 엉망으로 나감
{
	double		x;
	double		y;
	double		start_degree;
	double		end_degree;
	double		deg_per_pix;
	double		deg_index;
	double		abc;

	win->temp = win->p_d;


	//					  레이저 시작 각도 , 끝 각도 지정
	start_degree = within_2_pi_return(win->p_d - (win->pov / 2));
	end_degree = within_2_pi_return(win->p_d + (win->pov / 2));
	//

	deg_index = start_degree;
	deg_per_pix = win->pov / win->s_h;

	win->p_d = start_degree;				////
	win->idx_pix = 0;
while (win->idx_pix < win->s_h)
{

	within_2_pi(win);
	cal_quar(win);
	x = 0.00000;
	y = 0.00000;
	while (1)
	{
		if (fabs(tan(win->p_d)) < fabs(y / x))
				x += 1;
		else
				y += 1;
		ft_pixel_put(win, (int)(win->p_x * win->s_h_per_m + x * win->q_x), (int)(win->p_y * win->s_w_per_m + y * win->q_y), 0xffff00);
		if (check_grid(win, (int)(win->p_x * win->s_h_per_m + x * win->q_x), (int)(win->p_y * win->s_w_per_m + y * win->q_y)) == 1)
		{
			abc = distance_from_player(win, win->s_h_per_m + (win->q_x) * x, win->s_w_per_m + (win->q_y) * y);
//			if (win->idx_pix == 0)
//				printf("%.2f\n", abc);
			break;
		}

	}
	win->p_d = win->p_d + deg_per_pix;		/////// 각도 전역변수 하나 만들면 될듯
	win->idx_pix++;
}
	win->p_d = win->temp;
	return (0);
}

int		put_dir(t_win *win)		// single ray
{
	double		x;
	double		y;
	cal_quar(win);
	x = 0;		// 0.001;
	y = 0;		// 0.001;
	while (sqrt(x * x + y * y) < 25)
	{
		if (fabs(tan(win->p_d)) < fabs(y / x))
				x += win->q_x;
		else
				y += win->q_y;
		ft_pixel_put(win, (int)(win->p_x * win->s_w_per_m + x), (int)(win->p_y * win->s_h_per_m + y), 0xff0000);
	}
	return (0);
}


int		cal_l_quar(t_win *win)
{
	if (win->p_d >= 0 && win->p_d < M_PI / 2)
	{
		win->q_l_x = 1;
		win->q_l_y = 1;
	}
	else if (win->p_d >= M_PI / 2 && win->p_d < M_PI)
	{
		win->q_l_x = -1;
		win->q_l_y = 1;
	}
	else if (win->p_d >= M_PI && win->p_d < M_PI * 3 / 2)
	{
		win->q_l_x = -1;
		win->q_l_y = -1;
	}
	else
	{
		win->q_l_x = 1;
		win->q_l_y = -1;
	}
	return (0);
}

int		cal_quar(t_win *win)
{
	if (win->p_d >= 0 && win->p_d < M_PI / 2)
	{
		win->q_x = +1;
		win->q_y = +1;
	}
	else if (win->p_d >= M_PI / 2 && win->p_d < M_PI)
	{
		win->q_x = -1;
		win->q_y = 1;
	}
	else if (win->p_d >= M_PI && win->p_d < M_PI * 3 / 2)
	{
		win->q_x = -1;
		win->q_y = -1;
	}
	else // if (win->p_d >= M_PI * 3 / 2 && win->p_d < 2 * M_PI)
	{
		win->q_x = 1;
		win->q_y = -1;
	}
	return (0);
}

int		within_2_pi(t_win *win)
{
	while (win->p_d < 0 || win->p_d > 2 * M_PI)
	{
		if (win->p_d < 0)
		{
			win->p_d += 2 * M_PI;
		}
		else
		{
			win->p_d -= 2 * M_PI;
		}
	}
	return (0);
}

double	within_2_pi_return(double degree)
{
	while (degree < 0 || degree > 2 * M_PI)
	{
		if (degree < 0)
		{
			return(degree += 2 * M_PI);
		}
		else
		{
			return(degree -= 2 * M_PI);
		}
	}
	return (degree);
}


int		cub3d_map(t_win *win, int col, int row)
{
	int width;
	int	height;

	width = (int)win->m_w;
	height = (int)win->m_h;
	int total_map[10][10] =			// 10, 10 자리를 변수로 처리하면 오류 발생
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 1, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 0, 0, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	return (total_map[col][row]);
}



int		init_minimap(t_win *win)
{
	int col;
	int	row;

	win->map = (int **)malloc(sizeof(int *) * win->m_w);
	col = 0;
	while (col < (int)win->m_w)
	{
		win->map[col] = (int *)malloc(sizeof(int) * (int)win->m_h);
		col++;
	}

	col = 0;
	while (col < (int)win->m_wid)
	{
		row = 0;
		while (row < (int)win->m_hei)
		{
			win->map[col][row] = cub3d_map(win, col, row);
			row++;
		}
		col++;
	}
	
	return (0);
}

int		init_img(t_win *win, t_wall *wall, t_img *sprite)
{
	sprite->ptr = mlx_xpm_file_to_image(win->mlx, "wall/sprite.xpm", &sprite->width, &sprite->height);		// 경로는 실행파일 기준
	sprite->data = (int *)mlx_get_data_addr(sprite->ptr, &sprite->bpp, &sprite->size_l, &sprite->endian);
	return (0);
}

int		init_cub3d(t_win *win)		// 변수 초기화하는 함수
{
	// 플레이어
	win->p_d = 0;
	win->p_x = 5.0;		// 맵상 좌표
	win->p_y = 5.0;
	win->m_s = 5;

	init_m_xy(win);

	// 사분면
	within_2_pi(win);
	cal_quar(win);

	// 키보드 플래그
	win->press_w = 0;
	win->press_s = 0;
	win->press_a = 0;
	win->press_d = 0;

	win->key_ws = 0;


	// 화면
	win->s_w = 500;
	win->s_h = 500;

	// 맵
	win->m_w = 10.0;
	win->m_h = 10.0;

	win->m_wid = (int)(win->m_w);
	win->m_hei = (int)(win->m_h);

	init_minimap(win);

	// 화면 맵 비율
	win->s_w_per_m = win->s_w / win->m_w;
	win->s_h_per_m = win->s_h / win->m_h;

	// 수평 시야각
	win->pov_degree = 100;
	win->pov = win->pov_degree * (M_PI / 180);
	win->pov_v = win->pov * (win->s_h / win->s_w);

	// 벽
	win->wall_len = 1000;

	// 기타
	return (0);
}

int		main(void)
{
	//윈도우
	t_win	win;

	// 사용할 이미지들
	t_img	scr_img;	// 메인 이미지
	t_img	sprite;

	t_wall	wall;

	//구조체 변수 초기화
	init_cub3d(&win);

	//mlx 시작
	win.mlx = mlx_init();
	
	//	윈도우 크기의 이미지 만듦	 mlx 시작 위로 올리면 세그폴트
	win.img_ptr =mlx_new_image(win.mlx, win.s_w, win.s_h);		// img_ptr에 넣어줘야 사용가능
	win.data = (int *)mlx_get_data_addr(win.img_ptr, &win.bpp, &win.size_l, &win.endian);

	//img 변수 초기화
	init_img(&win, &wall, &sprite);		//	 세그폴트뜸 



	//init_wall();

	// s_w * s_h 크기의 스크린 만듦
	win.win = mlx_new_window(win.mlx, win.s_w, win.s_h, "42 sunmin");

	// 실시간으로 변경되는 부분 체크하는 함수가 들어있음
	mlx_loop_hook(win.mlx, ft_loop, &win);

	// 키를 누르고 뗴는 동작을 실시간으로 감시하는 함수
	mlx_hook(win.win, 2, 1L<<0, key_press, &win);
	mlx_hook(win.win, 3, 1L<<1, key_release, &win);

	// 윈도우 창을 계속 띄우는 함수
	mlx_loop(win.mlx);

	return (0);
}
