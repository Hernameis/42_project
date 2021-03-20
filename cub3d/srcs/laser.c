/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laser.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 07:36:53 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/20 10:46:05 by sunmin           ###   ########.fr       */
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
	int				j;
	int				color;
	double			wall_half_height;
	double			k;

	wall_half_height = win->dist / dis * win->cub_height / 2;
	start = win->scr_height / 2 - wall_half_height;
	end = win->scr_height / 2 + wall_half_height;
	j = 0;
	k = 0;
	while (j < win->scr_height)
	{
		if (j > start && j < end)
		{
			if (start < 0)
			{
				color = if_wall(k - start / (end - start)
						* wall_half_height * 2, wall_half_height * 2, win);
			}
			else
			{
				color = if_wall(k, wall_half_height * 2, win);
			}
			if (check_pixel(win, i, j, 0xffff00) == 0)
				draw_pixel(win, i, j, color);
			k++;
		}
		else
		{
			if (j < win->scr_height / 2)
				color = 0x87ceeb;
			else
				color = 0xffd700;
		}
		draw_pixel(win, i, j, color);
		j++;
	}
}
