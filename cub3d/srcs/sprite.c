/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:07:35 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/22 20:21:40 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_sprite(t_win *win)
{
	win->sprite_x1 = win->laser_x;
	win->sprite_y1 = win->laser_y;
}

void	end_sprite(t_win *win)
{
	win->sprite_x2 = win->laser_x;
	win->sprite_y2 = win->laser_y;
}

int		set_sprite(t_win *win)
{
	win->sprite_x[win->sprite_num] = (win->sprite_x1 + win->sprite_x2) / 2.0;
	win->sprite_y[win->sprite_num] = (win->sprite_y1 + win->sprite_y2) / 2.0;
	win->sprite_num++;
	return (0);
}

int		draw_sprite(t_win *win)
{
	while (win->sprite_num-- > 0)
	{
		win->sprite_distance = distance(win, win->sprite_x[win->sprite_num] - win->player_x, win->sprite_y[win->sprite_num] - win->player_y);
		put_sprite(win);
	}
	return (0);
}

int		put_sprite(t_win *win)
{
	int		height;
	int		end;
	int		start;
	int		index;

	height = win->scr_height * 10 * 5 / win->sprite_distance;
	start = win->scr_height / 2 - height / 2;
	end = win->scr_height / 2 + height / 2;

	index = start;
	while (index < end)
	{
		// 만약 값이 있으면
//		draw_pixel(win, win->i, height, win->sprite_data[(int)((index / height * win->sprite_height * index) * win->sprite_height + ((int)win->laser_x % (int)win->cub_size) * win->sprite_width / win->scr_width)]);
		draw_pixel(win, win->i, index, 0x0ff5ee);
//		printf("%d %d %d %d\n", height, start, end, win->i);
		index++;
	}
	return (0);
}
