/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:15:37 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/21 08:57:32 by sunmin           ###   ########.fr       */
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
	int			key_ad;
	int			key_ws;

	double		player_x;
	double		player_y;
	double		player_dir;

	double		laser_x;
	double		laser_y;
	double		laser_dir;

	int			map_height;
	int			map_width;

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

void	draw_pixel(t_win *win, int x, int y, int color);
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

// 지울 함수
void	cjswkd(t_win *win);

#endif
