#include <stdio.h>
/*
    추가할 사항

	1. 플레이어가 벽을 통과하지 못하게
	2. 최대 해상도 락
	3. 벽에 이미지 삽입
	6. 스프라이트
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


}			t_win;



//	함수 프로토타입 선언 

int		draw_gird(t_win *win, int x, int y);
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

//

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
	return (win->map[(int)(y / win->s_h_per_m)][(int)(x / win->s_w_per_m)]);
}

int		ft_loop(t_win *win)
{
//	draw_grid(win);
	ceiling_and_floor(win);		// 바닥, 천장 그리는 야매 함수
	if_key_pressed(win);
	put_player(win);
	put_laser(win);
	put_dir(win);
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
		win->key_ad = 1;
		return (1);
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
	if (win->press_w || win->press_s)
	{
//		if(check_grid(win, (win->p_x * win->s_w_per_m), (win->p_y) * win->s_h_per_m) != 1)		// 축지법으로 확인
//		{
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
//		}
	printf("%.2f\n%.2f, %.2f\n%.2f, %.2f\n\n", (win->p_d * 180 / M_PI), win->p_x, win->p_y, win->p_x * win->s_w_per_m, win->p_y * win->s_h_per_m);
	}
	if (win->press_a || win->press_d)
	{
		if_key_ad(win);
		win->p_d += (win->key_ad) * degree;		// 방향 전환
		within_2_pi(win);
		cal_quar(win);
	printf("%.2f\n%.2f, %.2f\n%.2f, %.2f\n", (win->p_d * 180 / M_PI), win->m_x, win->m_y, win->p_x, win->p_y);
	}
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


int		put_laser(t_win *win)		// put multi-ray
{
	double		x;
	double		y;

	x = 0.00001;
	y = 0.00001;
	while (1)
	{
		if (fabs(tan(win->p_d)) < fabs(y / x))
				x += 1;
		else
				y += 1;
		ft_pixel_put(win, (int)(win->p_x * win->s_w_per_m + x * win->q_x), (int)(win->p_y * win->s_h_per_m + y * win->q_y), 0xffff00);
	if (win->map[(int)((win->p_x * win->s_w_per_m + x * win->q_x) / win->s_w_per_m)][(int)((win->p_y * win->s_h_per_m + y * win->q_y) / win->s_h_per_m)] == 1)
		break;
	}

	return (0);
}

int		put_dir(t_win *win)		// single ray
{
	double		x;
	double		y;

	x = 0.00001;
	y = 0.00001;
	while (sqrt(x * x + y * y) < 25)
	{
		if (fabs(tan(win->p_d)) < fabs(y / x))
				x += 1;
		else
				y += 1;
		ft_pixel_put(win, (int)(win->p_x * win->s_w_per_m + x * win->q_x), (int)(win->p_y * win->s_h_per_m + y * win->q_y), 0xff0000);
	}
	return (0);
}

int		cal_quar(t_win *win)
{
	if (win->p_d >= 0 && win->p_d < M_PI / 2)
	{
		win->q_x = 1;
		win->q_y = 1;
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
	else
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
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
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
	sprite->ptr = mlx_xpm_file_to_image(win->mlx, "wall/wall_s.xpm", &sprite->width, &sprite->height);		// 경로는 실행파일 기준
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
