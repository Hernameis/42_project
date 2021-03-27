/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:15:37 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/27 10:31:44 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include "../minilibx_mms/mlx.h"

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			123
# define KEY_S			1
# define KEY_D			124
# define KEY_Q			0
# define KEY_E			2
# define KEY_M			46
# define X_BUTTON		17
# define PIXEL_SIZE		3
# define PIXEL_ALIGN	4

typedef struct			s_list
{
	void				*content;
	struct s_list		*prev;
	struct s_list		*next;
}						t_list;

typedef	struct			s_sprite
{
	double				center_x;
	double				center_y;
	double				distance;
	double				degree;
}						t_sprite;

typedef struct			s_win
{
	void				*mlx;
	void				*win;
	void				*img_ptr;
	int					img_height;

	double				scr_height;
	double				scr_width;
	double				screen_height;
	double				screen_width;

	int					*data;
	int					height;
	int					width;
	int					size_l;
	int					bpp;
	int					endian;

	int					press_w;
	int					press_s;
	int					press_a;
	int					press_d;
	int					press_q;
	int					press_e;
	int					press_m;

	int					key_ad;
	int					key_ws;

	double				player_x;
	double				player_y;
	double				player_dir;
	double				player_move_speed;

	double				laser_x;
	double				laser_y;
	double				laser_dir;

	double				dist;

	double				mini_x;
	double				mini_y;

	double				pov;
	double				temp;

	int					i;
	int					s;

	int					floor_color;
	int					ceiling_color;

	int					map_height;
	int					map_width;
	int					minimap_size;
	int					cub_size;
	double				cub_height;
	double				cub_width;
	double				cub_size_w;
	double				cub_size_h;

	char				*wall_n_addr;
	void				*wall_n_ptr;
	int					*wall_n_data;
	int					wall_n_height;
	int					wall_n_width;
	int					wall_n_size_l;
	int					wall_n_bpp;
	int					wall_n_endian;

	char				*wall_s_addr;
	void				*wall_s_ptr;
	int					*wall_s_data;
	int					wall_s_height;
	int					wall_s_width;
	int					wall_s_size_l;
	int					wall_s_bpp;
	int					wall_s_endian;

	char				*wall_w_addr;
	void				*wall_w_ptr;
	int					*wall_w_data;
	int					wall_w_height;
	int					wall_w_width;
	int					wall_w_size_l;
	int					wall_w_bpp;
	int					wall_w_endian;

	char				*wall_e_addr;
	void				*wall_e_ptr;
	int					*wall_e_data;
	int					wall_e_height;
	int					wall_e_width;
	int					wall_e_size_l;
	int					wall_e_bpp;
	int					wall_e_endian;

	char				*sprite_addr;
	void				*sprite_ptr;
	int					*sprite_data;
	int					sprite_height;
	int					sprite_width;
	int					sprite_size_l;
	int					sprite_bpp;
	int					sprite_endian;

	double				wall_dis;
	double				*dis_for_check;

	int					save;
	int					check_map;

	char				*old_map;
	char				*new_map;
	char				*parse_map;
	char				**map;
	int					parse_map_height;
	int					parse_map_width;
	int					check_height;
	int					check_width;
	int					check;

	int					sprite_num;
	double				sprite_size;
	t_sprite			*sprite;

	int					r_check;
	int					no_check;
	int					so_check;
	int					we_check;
	int					ea_check;
	int					s_check;
	int					f_check;
	int					c_check;
	char				*temp_map;
	char				*index;
	double				k;
	int					j;
	int					color;
	double				half_height;
	double				center;
	int					start;
	int					end;
	int					start_w;
	int					end_w;
	double				half;
	int					pad_size;

	int					size_x;
	int					size_y;
}						t_win;

typedef struct			s_img
{
	void				*ptr;
	int					*data;
	int					height;
	int					width;
	int					size_l;
	int					bpp;
	int					endian;
}						t_img;

int						draw_pixel(t_win *win, int x, int y, int color);
int						check_pixel(t_win *win, int x, int y, int color);
void					get_image_data(t_win *win);
void					get_image_data2(t_win *win);

int						ft_loop(t_win *win);
void					parse_argv(t_win *win, int argc, char **argv);
void					ft_bitmap(t_win *win, int argc, char **argv);

int						if_key_pressed(t_win *win);
int						key_press(int key, t_win *win);
int						key_release(int key, t_win *win);
int						if_key_ad(t_win *win);
int						if_key_ws(t_win *win);

void					key_pressed_ws(t_win *win);
void					key_pressed_qe(t_win *win);
void					key_pressed_ad(t_win *win);

void					struct_init(t_win *win);
void					struct_init2(t_win *win);
void					struct_init3(t_win *win);
void					sprite_init(t_win *win);
void					sprite_init2(t_win *win);

void					put_laser(t_win *win);
void					draw_wall(t_win *win, int i, double dis);
void					move_laser(t_win *win);

int						check_sprite(t_win *win, int num);
void					put_sprite(t_win *win);
void					draw_sprite(t_win *win);
void					sprite_pixel(t_win *win, int num);
int						sprite_color(t_win *win, int i,
		int j, int width);
void					compare_sprite(t_win *win, int num);

char					check_map(t_win *win, double x, double y);

int						mini_x(t_win *win, int x);
int						mini_y(t_win *win, int y);

double					distance(double a, double b);
double					degree_from_xy(double x1, double x2,
		double y1, double y2);
int						if_pass_wall(t_win *win, int key);
void					within_degree(t_win *win);
double					within_degree_double(double degree);

int						if_wall(int k, double height, t_win *win);
int						wall_w_color(double k, double height, t_win *win);
int						wall_e_color(int k, double height, t_win *win);
int						wall_s_color(int k, double height, t_win *win);
int						wall_n_color(int k, double height, t_win *win);
int						which_wall(t_win *win);
int						which_wall2(t_win *win);

double					equation_intercept_y(double a, double p, double q);
double					meet_between_segments_x(double a, double b,
		double c, double d);
double					meet_between_segments_y(double a, double b,
		double c, double d);
int						check_other_sprite(t_win *win);

int						check_save(char **argv);
void					make_bitmap(t_win *win);
void					put_bitmap(t_win *win);
int						put_bitmap_header(t_win *win, unsigned char *header);
void					set_bitmap_header(unsigned char *header, int height,
		int width, int size);

int						ft_strncmp(const char *s1, const char *s2, size_t n);
size_t					ft_strlen(const char *str);
char					*ft_strdup(const char *s);
char					*ft_strjoin(char const *s1, char const *s2);
char					*is_new(char *s, char c);

int						get_next_line(int fd, char **line);

char					**ft_split(char const *s, char c);

void					get_cubfile(t_win *win, char **argv);
int						check_cubfile(const char *str);
void					get_word(char *line, t_win *win);
void					get_floor_ceiling_color(char *line, t_win *win);
int						get_map(char *line, t_win *win);
int						check_blank(char *line);
void					init_map(t_win *win);
void					make_map(t_win *win);
int						check_map_effect(t_win *win);
int						check_player(t_win *win);
void					check_player2(t_win *win, int dir);
int						check_map_wall(t_win *win);
int						get_word_num(char **split);
void					free_split(char **split);
void					check_resolution(t_win *win);
void					get_floor_color(t_win *win, char **split,
		char **split2, int num);
void					swap_map(t_win *win, char *line);
int						ft_atoi(const char *str);
void					sprite_start(t_win *win, int num);

void					wall_pixel(t_win *win, double start, double end, int i);
double					res_double(double a, double b);
void					parse_gnl(t_win *win, int fd);
int						ft_exit(int key);
void					parse_r(t_win *win, char **split, int num);
void					parse_no(t_win *win, char **split, int num);
void					parse_s(t_win *win, char **split, int num);
void					parse_we(t_win *win, char **split, int num);
void					parse_ea(t_win *win, char **split, int num);

void					invalid_map1(t_win *win, int i, int j, int check);
void					invalid_map2(t_win *win, int i, int j, int check);
void					invalid_map3(t_win *win, int i, int j, int check);
void					invalid_map4(t_win *win, int i, int j, int check);
void					invalid_map5(t_win *win, int i, int j, int check);
void					invalid_map6(t_win *win, int i, int j, int check);
void					invalid_map7(t_win *win, int i, int j, int check);
void					invalid_map8(t_win *win, int i, int j, int check);
void					set_invalid_map(t_win *win, int i, int j);
void					check_comma(t_win *win, char *line);

void					wall_n_location_fix(t_win *win);
void					wall_s_location_fix(t_win *win);
void					wall_w_location_fix(t_win *win);
void					wall_e_location_fix(t_win *win);

#endif
