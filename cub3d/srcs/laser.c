/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laser.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 07:36:53 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/22 12:58:49 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				put_player(t_win *win)
{
	int				i;
	int				j;

	i = -7;
	while (i < 7)
	{
		j = -7;
		while (j < 7)
		{
			if (win->press_m)
				draw_pixel(win, (int)win->player_x + j,
						(int)win->player_y + i, 0x00ffee);
			j++;
		}
		i++;
	}
}

void				put_laser(t_win *win)
{
	double			w_i;

	w_i = ((win->scr_width - 1) / -2) - 1;
	win->dist = 1 / tan(win->pov * M_PI / 180 / 2) * win->scr_width / 2;
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
}

void				move_laser(t_win *win)
{
	while (win->laser_x >= 0 && win->laser_y >= 0
			&& win->laser_x <= win->scr_width
			&& win->laser_y <= win->scr_height)
	{
		win->laser_x += cos(win->player_dir + win->laser_dir);
		win->laser_y += sin(win->player_dir + win->laser_dir);
		if (check_map(win, win->laser_x, win->laser_y) == '1')
			break ;
	}
}

void				draw_wall(t_win *win, int i, double dis)
{
	double			start;
	double			end;

	win->half_height = win->dist / dis * win->cub_height / 5;
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
				win->color = 0x87ceeb;
			else
				win->color = 0xffd700;
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
