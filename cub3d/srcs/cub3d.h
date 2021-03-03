/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:15:37 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/03 17:22:52 by sunmin           ###   ########.fr       */
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
	double		screen_height;
	double		screen_width;

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
	double		player_move_speed;

	double		laser_x;
	double		laser_y;
	double		laser_dir;

	double		mini_x;
	double		mini_y;

	double		pov;
	double		temp;

	int			i;
	int			s;

	int			map_height;
	int			map_width;
	int			minimap_size;
	int			cub_size;
	double		cub_height;
	double		cub_width;
	double		cub_size_w;
	double		cub_size_h;

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

	void		*sprite_ptr;
	int			*sprite_data;
	int			sprite_height;
	int			sprite_width;
	int			sprite_size_l;
	int			sprite_bpp;
	int			sprite_endian;

	int			start_end;
	int			start;
	int			end;


	//		보너스
	double		player_life;
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
int		check_pixel(t_win *win, int x, int y, int color);
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
int		if_wall(int k, int height, t_win *win);
int		wall_w_color(double k,int height, t_win *win);
int		wall_e_color(int k,int height, t_win *win);
int		wall_s_color(int k,int height, t_win *win);
int		wall_n_color(int k,int height, t_win *win);
int		which_wall(t_win *win);
int		if_pass_wall(t_win *win, int key);
void	within_degree(t_win *win);
void	check_sprite_center(t_win *win);
int		if_sprite_plane(t_win *win);
void	draw_sprite_plane(t_win *win);
void	draw_sprite(t_win *win);
void	put_laser_sprite(t_win *win);
int		sprite_color(t_win *win, int j, int start, int height);

int		first_sprite(t_win *win);
int		last_sprite(t_win *win);
int		sprite_check_map(t_win *win, double x, double y);
int		call_sprite_idx_first(t_win *win);
int		call_sprite_idx_last(t_win *win);
int		left_right_from_sprite(t_win *win);
void	idx_between_sprite_center(t_win *win);

//	calc2.c
double	equation_intercept_y(double a, double p, double q);
double	meet_between_segments_x(double a, double b, double c, double d);
double	meet_between_segments_y(double a, double b, double c, double d);
int		check_other_sprite(t_win *win);


/*		sprite_atan2.c
void	sprite_pixel(t_win *win, int start, int end, int i);
int		sprite_color(t_win *win, int i, int j);
void	draw_sprite(t_win *win);
void	draw_sprite_pixel(t_win *win, double degree, double dis);
*/

// 보너스
void	cub3d_bonus(t_win *win);
void	player_life(t_win *win);
int		player_life_check(t_win *win, int w_idx, int h_dix);

// 지울거
void	ceiling(t_win *win);


#endif
