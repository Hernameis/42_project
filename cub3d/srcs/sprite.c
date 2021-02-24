/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:07:35 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/24 13:59:07 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_sprite(t_win *win)
{
//	return ;
	win->sprite_x1 = win->laser_x;
	win->sprite_y1 = win->laser_y;
}

void	end_sprite(t_win *win)
{
//	return ;
	win->sprite_x2 = win->laser_x;
	win->sprite_y2 = win->laser_y;
}

int		set_sprite(t_win *win)
{
//	return 0;
	win->sprite_x[win->sprite_num] = (win->sprite_x1 + win->sprite_x2) / 2.0;
	win->sprite_y[win->sprite_num] = (win->sprite_y1 + win->sprite_y2) / 2.0;
	win->sprite_num++;
	return (0);
}

int		draw_sprite(t_win *win, int i)
{
//	return 0;
	while (win->sprite_num-- > 0)
	{
		win->sprite_distance[win->sprite_num] = distance(win, win->sprite_x[win->sprite_num] - win->player_x, win->sprite_y[win->sprite_num] - win->player_y);

		put_sprite(win);
	}
	return (0);
}

int		put_sprite(t_win *win)
{
//	return 0;
	double		half_height;
	double		end;
	double		start;
	double		start_end;
	double		i;
	int			color;


	half_height = win->scr_height * 50 / win->sprite_distance[win->sprite_num];
	start = win->scr_height / 2 - half_height;
	end = win->scr_height / 2 + half_height;
	start_end = end - start;
	i = 0;
	while (i < start_end)
	{
		if (win->sprite_data[(int)((int)(i / start_end * 64) * 64 + ((int)win->laser_x % 64))])
		{
			color = win->sprite_data[(int)((int)(i / start_end * 64) * 64 + ((int)win->laser_x % 64))];
			draw_pixel(win, win->i, start + i, color);
		}
		i++;
	}
	return (0);
}
