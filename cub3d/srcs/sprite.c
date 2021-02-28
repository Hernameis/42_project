/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:07:35 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/01 00:03:38 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_sprite_center(t_win *win)
{
//	return ;
	win->sprite_center_x[win->sprite_num] = (int)(win->laser_x / win->cub_width) * win->cub_width + (win->cub_width / 2);
	win->sprite_center_y[win->sprite_num] = (int)(win->laser_y / win->cub_height) * win->cub_height + (win->cub_height / 2);
//	printf("%d\n", win->sprite_num);
	draw_pixel(win, win->sprite_center_x[win->sprite_num], (int)win->sprite_center_y[win->sprite_num], 0xffff00);
}

void	draw_sprite(t_win *win)
{
	double	sprite_x;
	double	sprite_y;
	double	degree;
	double	dis;

	sprite_x = win->sprite_center_x[win->sprite_num];
	sprite_y = win->sprite_center_y[win->sprite_num];
	degree = degree_from_xy(win->player_x, sprite_x, win->player_y, sprite_y);
//	printf("%f %f %f\n", win->player_dir, win->pov / 2 *  M_PI / 180, degree);
	while (degree >= win->player_dir - (win->pov / 2) * M_PI / 180 && degree <= win->player_dir + (win->pov / 2) * M_PI / 180)
	{
		dis = distance(win, sprite_x - win->player_x, sprite_y - win->player_y) * cos(win->player_dir - degree); 
		degree = degree_from_xy(win->player_x, sprite_x, win->player_y, sprite_y);
		draw_sprite_pixel(win, degree, dis);
		sprite_x += cos(win->player_dir + M_PI / 2);
		sprite_y += sin(win->player_dir + M_PI / 2);
	}
}

void	draw_sprite_pixel(t_win *win, double degree, double dis)
{
	int		i;
	int		col;
	int		start;
	int		end;
	int		start_end;
	double	sprite_half_height;

	i = (int)((degree - (win->player_dir - (win->pov / 2) * M_PI / 180)) / (win->pov * M_PI / 180) * win->scr_width);
	sprite_half_height = win->scr_height * 5 * 2 / dis;
	start = (int)win->scr_height / 2 - sprite_half_height;
	if (start < 0)
		start = 0;
	end = (int)win->scr_height / 2 + sprite_half_height;
	if (end > (int)win->scr_height)
		end = (int)win->scr_height;
	start_end = end - start;
	col = start;
	while (col < end)
	{

		draw_pixel(win, i, col, 0x000000);
		col++;
	}
//	printf("%d\n", i);
}
