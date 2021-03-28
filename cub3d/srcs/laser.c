/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laser.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 07:36:53 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/28 12:00:20 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				put_laser(t_win *win)
{
	double			w_i;

	w_i = ((win->scr_width - 1) / -2) - 1;
	win->i = 0;
	while (++w_i < (int)win->scr_width / 2)
	{
		win->laser_dir = atan2(w_i, win->dist);
		win->laser_x = win->player_x;
		win->laser_y = win->player_y;
		move_laser(win);
		win->wall_dis = (distance(win->player_x - win->laser_x,
					win->player_y - (win->laser_y)))
			* cos(degree_from_xy(win->player_x, win->laser_x,
						win->player_y, win->laser_y) - win->player_dir);
		win->dis_for_check[win->i] = win->wall_dis;
		draw_wall(win, win->i, win->wall_dis);
		win->i++;
	}
	draw_sprite(win);
}

void				move_laser(t_win *win)
{
	while (win->laser_x >= 0 && win->laser_y >= 0
			&& win->laser_x <= win->scr_width
			&& win->laser_y <= win->scr_height)
	{
		win->laser_x += 0.3 * cos(win->player_dir + win->laser_dir);
		win->laser_y += 0.3 * sin(win->player_dir + win->laser_dir);
		if (check_map(win, win->laser_x, win->laser_y) == '1')
			break ;
	}
	if (which_wall2(win) == 1)
		wall_e_location_fix(win);
	else if (which_wall2(win) == 2)
		wall_w_location_fix(win);
	else if (which_wall2(win) == 3)
		wall_n_location_fix(win);
	else if (which_wall2(win) == 4)
		wall_s_location_fix(win);
}

void				draw_wall(t_win *win, int i, double dis)
{
	double			start;
	double			end;

	win->color = 0x000000;
	win->half_height = 1 / dis * win->cub_height / 5 * win->dist;
	start = win->scr_height / 2 - win->half_height;
	end = win->scr_height / 2 + win->half_height;
	win->j = -1;
	win->k = 0;
	while (++win->j < win->scr_height)
	{
		if (win->j > start && win->j < end)
			wall_pixel(win, start, end, i);
		else
		{
			if (win->j < win->scr_height / 2)
				win->color = win->ceiling_color;
			else
				win->color = win->floor_color;
		}
		draw_pixel(win, i, win->j, win->color);
	}
}

void				wall_pixel(t_win *win, double start, double end, int i)
{
	if (start < 0)
	{
		win->color = if_wall(win->k - start / (end - start)
				* win->half_height * 2, win->half_height * 2, win);
	}
	else
		win->color = if_wall(win->k, win->half_height * 2, win);
	if (check_pixel(win, i, win->j, 0xffff00) == 0)
		draw_pixel(win, i, win->j, win->color);
	win->k++;
}
