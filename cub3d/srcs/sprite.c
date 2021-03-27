/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:08:43 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/27 10:23:29 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		sprite_pixel(t_win *win, int num)
{
	int		i;
	int		j;

	sprite_start(win, num);
	i = win->start;
	while (i < win->end)
	{
		j = win->start_w;
		while (j < win->end_w)
		{
			if ((sprite_color(win, i - win->start,
							j - win->start_w, win->end_w - win->start_w)) != 0)
			{
				if (i >= 0 && j >= 0 && i < win->scr_height
						&& j < win->scr_width)
				{
					if (win->dis_for_check[j] > win->sprite[num].distance)
						draw_pixel(win, j, i, sprite_color(win, i - win->start,
							j - win->start_w, win->end_w - win->start_w));
				}
			}
			j++;
		}
		i++;
	}
}

void		sprite_start(t_win *win, int num)
{
	win->center = (within_degree_double(win->sprite[num].degree
				- win->player_dir) + (win->pov * M_PI / 180) / 2)
		/ (win->pov * M_PI / 180) * win->scr_width;
	win->half = win->scr_height / win->sprite[num].distance
		* win->sprite_size / 2;
	win->start = (int)(win->scr_height / 2 - win->half);
	win->end = (int)(win->scr_height / 2 + win->half);
	win->start_w = (int)(win->center - win->half);
	win->end_w = (int)(win->center + win->half);
}

int			sprite_color(t_win *win, int i, int j, int width)
{
	double	x;
	double	y;
	int		color;
	int		height;

	height = win->end - win->start;
	x = i / (double)height;
	y = j / (double)width;
	color = win->sprite_data[(int)(x * win->sprite_width) + (int)(y
			* win->sprite_height) * win->sprite_width];
	return (color);
}

void		compare_sprite(t_win *win, int num)
{
	int		j;
	double	temp_distance;
	double	temp_degree;

	while (num > 0)
	{
		j = 0;
		while (j < num - 1)
		{
			if (win->sprite[j].distance > win->sprite[j + 1].distance)
			{
				temp_distance = win->sprite[j + 1].distance;
				temp_degree = win->sprite[j + 1].degree;
				win->sprite[j + 1].distance = win->sprite[j].distance;
				win->sprite[j + 1].degree = win->sprite[j].degree;
				win->sprite[j].distance = temp_distance;
				win->sprite[j].degree = temp_degree;
			}
			j++;
		}
		num--;
	}
}
