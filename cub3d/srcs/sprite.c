/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:07:35 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/03 17:26:20 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
void	check_sprite_center(t_win *win)
{
	win->sprite_center_x[win->sprite_check_height][win->sprite_check_width] = (int)(win->laser_x / win->cub_width) * win->cub_width + (win->cub_width / 2);
	win->sprite_center_y[win->sprite_check_height][win->sprite_check_width] = (int)(win->laser_y / win->cub_height) * win->cub_height + (win->cub_height / 2);
	win->sprite_check_height = (int)(win->laser_y / win->cub_height);
	win->sprite_check_width = (int)(win->laser_x / win->cub_width);
//	printf("%d %d\n", win->sprite_check_height, win->sprite_check_width);
	draw_pixel(win, win->sprite_center_x[win->sprite_check_height][win->sprite_check_width], (int)win->sprite_center_y[win->sprite_check_height][win->sprite_check_width], 0xffff00);
}

int		if_sprite_plane(t_win *win)
{

	double	tan_laser;
	double	tan_sprite;
	double	laser_b;
	double	sprite_b;
	double	sprite_degree;

	sprite_degree = win->player_dir - M_PI / 2;
	tan_laser = tan(win->player_dir + win->laser_dir);
	tan_sprite = tan(sprite_degree);
	laser_b = equation_intercept_y(tan_laser, win->player_x, win->player_y);
	sprite_b = equation_intercept_y(tan_sprite, win->sprite_center_x[win->sprite_check_height][win->sprite_check_width], win->sprite_center_y[win->sprite_height][win->sprite_width]);
	win->sprite_x[win->sprite_num] = meet_between_segments_x(tan_laser, laser_b, tan(sprite_degree), sprite_b);
	win->sprite_y[win->sprite_num] = meet_between_segments_y(tan_laser, laser_b, tan(sprite_degree), sprite_b);
//	printf("%.2f %.2f %.2f %.2f %.2f (%.2f, %.2f) %d\n", win->laser_dir, tan_laser, tan_sprite, laser_b, sprite_b, win->sprite_x[win->sprite_num], win->sprite_y[win->sprite_num], win->sprite_num);

//	if (check_map(win, win->sprite_x[win->sprite_num], win->sprite_y[win->sprite_num]) == 2)
//	{
//		return (1);
//	}
//	else
//	{
//		win->sprite_x[win->sprite_num] = 0;
//		win->sprite_y[win->sprite_num] = 0;
//	}
	return (0);
}

void	draw_sprite_plane(t_win *win)
{
	draw_pixel(win, (int)win->sprite_x[win->sprite_num], (int)win->sprite_y[win->sprite_num], 0x888888);
//	draw_pixel(win, (int)win->i, 300, 0x000000);
}

void	draw_sprite(t_win *win)
{
//	return ;
	int		start;
	int		end;
	int		start_end;
	double	half_height;
	double	degree;
	int		j;
	int		color;

	half_height = win->scr_height / win->sprite_dis * 5 * 2 ;

	start = (int)win->scr_height / 2 - half_height;
	end = (int)win->scr_height / 2 + half_height;
	start_end = end - start;

	if (end > win->scr_height)
		end = win->scr_height;
	j = start;
	if (j < 0)
		j = 0;
	while (j < end)
	{
		if (sprite_color(win, j, start, start_end))
		{
			color = sprite_color(win, j, start, start_end);
			draw_pixel(win, win->i, j, color);
		}
		j++;
	}
}

int		sprite_color(t_win *win, int j, int start, int height)
{
	int		color;
	int		start_w;
	int		end_w;
	int		start_end;

	start_w = call_sprite_idx_first(win);
	end_w = call_sprite_idx_last(win);
	start_end = end_w - start_w;
//	printf("%d %d\n", (int)((j - start / (double)height) * win->sprite_height) , (int)((int)((win->i - start_w))  / (double)start_end * win->sprite_width));		// 가로 세로 인덱스 64인지 각각 확인
//	printf("%d %d ,,,, %d %d\n", j - start, height, win->i - start_w, start_end);

//	color = win->sprite_data[(int)(((j - start) / (double)height) * win->sprite_height) * win->sprite_width + (int)((win->sprite_index / win->sprite_len) * win->sprite_width)];
	// 가로 인덱스에 스프라이트 크기 곱해주기
// 인덱스 침범 때문에 세그폴트 발생

	color = 0x555555;
//	printf("%d\n", (int)((win->sprite_index / win->sprite_len) * win->sprite_width));
	return (color);
}
*/
