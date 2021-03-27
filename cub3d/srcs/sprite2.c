/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 10:54:05 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/27 11:48:52 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			draw_sprite(t_win *win)
{
	int			num;

	put_sprite(win);
	num = win->sprite_num;
	num = num - 1;
	while (num >= 0)
	{
		if (check_sprite(win, num))
		{
			sprite_pixel(win, num);
		}
		num--;
	}
}

int				check_sprite(t_win *win, int num)
{
	within_degree(win);
	if (within_degree_double(win->player_dir - win->sprite[num].degree)
			>= (-1 * (win->pov / 2 + 15.0)
			* M_PI / 180) && within_degree_double(win->player_dir
				- win->sprite[num].degree) <= ((win->pov / 2 + 15.0)
					* M_PI / 180))
	{
		{
			return (1);
		}
	}
	return (0);
}

void			put_sprite(t_win *win)
{
	int			num;

	num = 0;
	while (num < win->sprite_num)
	{
		win->sprite[num].distance = distance(win->player_x
				- win->sprite[num].center_x, win->player_y
				- win->sprite[num].center_y);
		win->sprite[num].degree = degree_from_xy(win->player_x,
				win->sprite[num].center_x, win->player_y,
				win->sprite[num].center_y);
		num++;
	}
	compare_sprite(win, win->sprite_num);
}
