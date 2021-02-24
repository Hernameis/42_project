/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:07:35 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/25 07:14:45 by sunmin           ###   ########.fr       */
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
//a	return ;
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

	half_height = win->scr_height * 15 / win->sprite_distance[win->sprite_num]; // 해상도가 달라지면 start 값이 음수가 되는 경우도 ㄴ있음
	start = win->scr_height / 2 - half_height;
	if (start < 0)
		start = 0;
	end = win->scr_height / 2 + half_height;
	if (end > win->scr_height)
		end = win->scr_height - 1;		// start, end 안막아주면 팅김
	start_end = end - start;
	i = 0;
	while (i < start_end)
	{
		if (win->sprite_data[((int)(i / start_end * 64) * 64 + ((int)win->laser_x % 50))])
		{
//		color = 0x777777;
			color = win->sprite_data[((int)(i / start_end * 64) * 64 + ((int)win->laser_x % 50))];
			printf("%d %f %d\n", win->i, start + i, color);
			draw_pixel(win, win->i, (start + i), color);
		}
		i++;
	}
	return (0);
}
