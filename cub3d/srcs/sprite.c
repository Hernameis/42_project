/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:07:35 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/23 15:28:56 by sunmin           ###   ########.fr       */
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

int		draw_sprite(t_win *win, int i)
{
	while (win->sprite_num > 0)
	{
		win->sprite_distance[win->sprite_num] = distance(win, win->sprite_x[win->sprite_num] - win->player_x, win->sprite_y[win->sprite_num] - win->player_y);
		put_sprite(win, i);
		win->sprite_num--;
	}
	return (0);
}

int		put_sprite(t_win *win, int i)
{
	int		half_height;
	int		end;
	int		start;

	half_height = win->scr_height * 10 * 5 / win->sprite_distance[win->sprite_num];
	start = win->scr_height / 2 - half_height;
	end = win->scr_height / 2 + half_height;

	while (start++ < end)
	{
		draw_pixel(win, i, start, 0x0ff5ee);
//		printf("%d %d %d %d\n", half_height, start, end, win->i);
	}
	return (0);
}
