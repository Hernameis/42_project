/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:15:37 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/21 19:58:21 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define LIBFT_H


//	라이브러리
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include "../minilibx_mms/mlx.h"

# define key_esc 53
# define key_w 13
# define key_a 0
# define key_s 1
# define key_d 2
# define key_q 12
# define key_e 14
# define key_m 46



//	구조체
typedef struct		s_win
{
	void		*mlx;
	void		*win;
	void		*img_ptr;
	int			img_height;

	double		scr_height;
	double		scr_width;

	int			*data;
	int			height;
	int			width;
	int			size_l;
	int			bpp;
	int			endian;

	int			press_w;
	int			press_s;
	int			press_a;
	int			press_d;
	int			press_q;
	int			press_e;
	int			press_m;

	int			key_ad;
	int			key_ws;

	double		player_x;
	double		player_y;
	double		player_dir;

	double		laser_x;
	double		laser_y;
	double		laser_dir;

	double		mini_x;
	double		mini_y;

	double		pov;
	double		temp;

	int			i;

	int			map_height;
	int			map_width;
	int			minimap_size;
	int			cub_size;

	void		*wall_n_ptr;
	int			*wall_n_data;
	int			wall_n_height;
	int			wall_n_width;
	int			wall_n_size_l;
	int			wall_n_bpp;
	int			wall_n_endian;

	void		*wall_s_ptr;
	int			*wall_s_data;
	int			wall_s_height;
	int			wall_s_width;
	int			wall_s_size_l;
	int			wall_s_bpp;
	int			wall_s_endian;

	void		*wall_w_ptr;
	int			*wall_w_data;
	int			wall_w_height;
	int			wall_w_width;
	int			wall_w_size_l;
	int			wall_w_bpp;
	int			wall_w_endian;

	void		*wall_e_ptr;
	int			*wall_e_data;
	int			wall_e_height;
	int			wall_e_width;
	int			wall_e_size_l;
	int			wall_e_bpp;
	int			wall_e_endian;
}					t_win;

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



//	함수 프로토 타입 선언

int		draw_pixel(t_win *win, int x, int y, int color);
int		if_key_pressed(t_win *win);
int		key_press(int key, t_win *win);
int		key_release(int key, t_win *win);
int		if_key_ad(t_win *win);
int		if_key_ws(t_win *win);
int		ft_loop(t_win *win);
void	struct_init(t_win *win);
void	put_player(t_win *win);
void	put_laser(t_win *win);
void	put_grid(t_win *win);
int		check_map(t_win *win, double x, double y);
int		mini_x(t_win *win, int x);
int		mini_y(t_win *win, int y);
double	distance(t_win *win, double a, double b);
void	draw_wall(t_win *win, int i, double dis);
double	degree_from_xy(double x1, double x2, double y1, double y2);
int		wall_color(int k,int height, t_win *win);

// 지울 함수
void	cjswkd(t_win *win);

#endif
