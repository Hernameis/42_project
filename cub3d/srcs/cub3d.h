/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:15:37 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/15 11:09:34 by sunmin           ###   ########.fr       */
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
# define x_button 17
# define PIXEL_SIZE 3
# define PIXEL_ALIGN 4


//	구조체

typedef struct		s_list
{
	void				*content;
	struct s_list		*prev;
	struct s_list		*next;
}					t_list;

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

	double		dist;

	double		mini_x;
	double		mini_y;

	double		pov;
	double		temp;

	int			i;
	int			s;

	int			floor_color;
	int			ceiling_color;

	int			map_height;
	int			map_width;
	int			minimap_size;
	int			cub_size;
	double		cub_height;
	double		cub_width;
	double		cub_size_w;
	double		cub_size_h;

	char		*wall_n_addr;
	void		*wall_n_ptr;
	int			*wall_n_data;
	int			wall_n_height;
	int			wall_n_width;
	int			wall_n_size_l;
	int			wall_n_bpp;
	int			wall_n_endian;

	char		*wall_s_addr;
	void		*wall_s_ptr;
	int			*wall_s_data;
	int			wall_s_height;
	int			wall_s_width;
	int			wall_s_size_l;
	int			wall_s_bpp;
	int			wall_s_endian;

	char		*wall_w_addr;
	void		*wall_w_ptr;
	int			*wall_w_data;
	int			wall_w_height;
	int			wall_w_width;
	int			wall_w_size_l;
	int			wall_w_bpp;
	int			wall_w_endian;

	char		*wall_e_addr;
	void		*wall_e_ptr;
	int			*wall_e_data;
	int			wall_e_height;
	int			wall_e_width;
	int			wall_e_size_l;
	int			wall_e_bpp;
	int			wall_e_endian;

	char		*sprite_addr;
	void		*sprite_ptr;
	int			*sprite_data;
	int			sprite_height;
	int			sprite_width;
	int			sprite_size_l;
	int			sprite_bpp;
	int			sprite_endian;

	double		wall_dis;

	int			save;
	int			check_map;

	char		*parse_map;
	char		**map;
	int			parse_map_height;
	int			parse_map_width;

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

//	cub3d.c
int		draw_pixel(t_win *win, int x, int y, int color);
int		check_pixel(t_win *win, int x, int y, int color);

int		if_key_pressed(t_win *win);
int		key_press(int key, t_win *win);
int		key_release(int key, t_win *win);
int		if_key_ad(t_win *win);
int		if_key_ws(t_win *win);
int		ft_loop(t_win *win);

//	init.c
void	struct_init(t_win *win);
void	struct_init2(t_win *win);

//	laser.c
void	put_player(t_win *win);
void	put_laser(t_win *win);
void	put_grid(t_win *win);
void	draw_wall(t_win *win, int i, double dis);

//	map.c
char	check_map(t_win *win, double x, double y);

int		mini_x(t_win *win, int x);
int		mini_y(t_win *win, int y);

// calc.c
double	distance(double a, double b);
double	degree_from_xy(double x1, double x2, double y1, double y2);
int		if_pass_wall(t_win *win, int key);
void	within_degree(t_win *win);

//	if_wall
int		if_wall(int k, int height, t_win *win);
int		wall_w_color(double k,int height, t_win *win);
int		wall_e_color(int k,int height, t_win *win);
int		wall_s_color(int k,int height, t_win *win);
int		wall_n_color(int k,int height, t_win *win);
int		which_wall(t_win *win);

//	calc2.c
double	equation_intercept_y(double a, double p, double q);
double	meet_between_segments_x(double a, double b, double c, double d);
double	meet_between_segments_y(double a, double b, double c, double d);
int		check_other_sprite(t_win *win);

int		check_save(char **argv);
void	make_bitmap(t_win *win);
void	put_bitmap(t_win *win);
int		put_bitmap_header(t_win *win, unsigned char *header);

//	libft.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*is_new(char *s, char c);

//	libft
t_list	*ft_lstlast(t_list *lst);					//ft_lstlast
t_list	*ft_lstnew(void *content);					//ft_lstnew
void	ft_lstadd_back(t_list **lst, t_list *new);	//ft_lstadd_back
int		ft_lstsize(t_list *lst);					//ft_lstsize

/*		sprite_atan2.c
void	sprite_pixel(t_win *win, int start, int end, int i);
int		sprite_color(t_win *win, int i, int j);
void	draw_sprite(t_win *win);
void	draw_sprite_pixel(t_win *win, double degree, double dis);
*/

//get_next_line.c
static	int		push_gnl(char **remain, char *temp, char **line);
int				get_next_line(int fd, char **line);

//	ft_split.c
static	int		ft_word_num(char *s, char c);
static	int		chnum(char *s, int index, char c);
static	char	**ft_push_split(char *s, char **split, int num, char c);
char			**ft_split(char const *s, char c);

// parse.c
void	get_cubfile(t_win *win, char **argv);
int		check_cubfile(const char *str);
void	get_word(char *line, t_win *win);
void	get_floor_ceiling_color(char *line, t_win *win);
int		get_map(char *line, t_win *win);
int		check_blank(char *line, t_win *win);
void	init_map(t_win *win);
void	make_map(t_win *win);
int		check_map_effect(t_win *win);
int		check_player(t_win *win);
int		check_map_wall(t_win *win);
int		get_word_num(char **split, t_win *win);

//	ft_atoi.c
int		ft_atoi(const char *str);

int		ft_exit(int key);
// 보너스
void	cub3d_bonus(t_win *win);
void	player_life(t_win *win);
int		player_life_check(t_win *win, int w_idx, int h_dix);

// 지울거
void	ceiling(t_win *win);


#endif
