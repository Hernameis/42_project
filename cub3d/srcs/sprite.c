/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 10:08:43 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/19 10:30:06 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_sprite(t_win *win)
{
	int		num;

	put_sprite(win);
	num = win->sprite_num;
	while (num >= 0)
	{
		if (check_sprite(win, num))
		{
			sprite_pixel(win, num);
		}
		num--;
	}
}

int		check_sprite(t_win *win, int num)
{
	within_degree(win);
	if (win->sprite[num].degree >= win->player_dir - (win->pov + 30) / 2 * M_PI / 180 && win->sprite[num].degree <= win->player_dir + (win->pov + 30) / 2 * M_PI / 180)
	{
		return (1);
	}
	return (0);
}

void	put_sprite(t_win *win)
{
	int		num;

	num = 0;
	while (num < win->sprite_num)
	{
		win->sprite[num].distance = distance(win->player_x - win->sprite[num].center_x, win->player_y - win->sprite[num].center_y);
		win->sprite[num].degree = degree_from_xy(win->player_x, win->sprite[num].center_x, win->player_y, win->sprite[num].center_y);
		num++;
	}
	compare_sprite(win, win->sprite_num);
}

void	sprite_pixel(t_win *win, int num)
{
	int		i;
	int		j;
	double	half;
	int		start;
	int		end;
	double center;
	int		start_w;
	int		end_w;

	center = (win->sprite[num].degree - win->player_dir + (win->pov * M_PI / 180) / 2) / (win->pov * M_PI / 180) * win->scr_width;
	half = win->scr_height / win->sprite[num].distance * 55;
	start = (int)(win->scr_height / 2 - half);
	end = (int)(win->scr_height / 2 + half);
	start_w = (int)(center - half);
	end_w = (int)(center + half);
	i = start;
	while (i < end)
	{
		j = start_w;
		while (j < end_w)
		{
			if ((sprite_color(win, i - start, end - start, j -start_w, end_w - start_w)) != 0)
			{
				if (i >= 0 && j >= 0 && i < win->scr_height && j < win->scr_width)
				{
					if (win->dis_for_check[j] > win->sprite[num].distance)
					{
						draw_pixel(win, j, i, sprite_color(win, i - start, end - start, j - start_w, end_w - start_w));
					}
				}
			}
			j++;
		}
		i++;
	}
}

int		sprite_color(t_win *win, int i, int height, int j, int width)
{
	double	x;
	double	y;
	int		color;

	x = i / (double)height;
	y = j / (double)width;
	color = win->sprite_data[(int)(x * win->sprite_width) + (int)(y * win->sprite_height) * win->sprite_width];
	return (color);
}

void	compare_sprite(t_win *win, int num)
{
	int		i;
	int		j;
	double	temp_distance;
	double	temp_degree;

	i = num;
	while (i > 0)
	{
		j = 0;
		while (j < num - 1)
		{
			if (win->sprite[j].distance > win->sprite[j + 1].distance)
			{
				temp_distance  = win->sprite[j + 1].distance;
				temp_degree = win->sprite[j + 1].degree;
				win->sprite[j + 1].distance = win->sprite[j].distance;
				win->sprite[j + 1].degree = win->sprite[j].degree;
				win->sprite[j].distance = temp_distance;
				win->sprite[j].degree = temp_degree;
			}
			j++;
		}
		i--;
	}
}
