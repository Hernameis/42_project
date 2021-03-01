/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:07:35 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/01 15:08:55 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_sprite_center(t_win *win)
{
	win->sprite_center_x[win->sprite_num] = (int)(win->laser_x / win->cub_width) * win->cub_width + (win->cub_width / 2);
	win->sprite_center_y[win->sprite_num] = (int)(win->laser_y / win->cub_height) * win->cub_height + (win->cub_height / 2);
	draw_pixel(win, win->sprite_center_x[win->sprite_num], (int)win->sprite_center_y[win->sprite_num], 0xffff00);
}

int		if_sprite_plane(t_win *win)
{

	double	tan_laser;
	double	tan_sprite;;
	double	laser_b;
	double	sprite_b;
	double	sprite_degree;

	sprite_degree = win->player_dir - M_PI / 2;
	tan_laser = tan(win->player_dir + win->laser_dir);
	tan_sprite = tan(sprite_degree);
	laser_b = equation_intercept_y(tan_laser, win->player_x, win->player_y);
	sprite_b = equation_intercept_y(tan_sprite, win->sprite_center_x[win->sprite_num], win->sprite_center_y[win->sprite_num]);
	win->sprite_x[win->sprite_num] = meet_between_segments_x(tan_laser, laser_b, tan(sprite_degree), sprite_b);
	win->sprite_y[win->sprite_num] = meet_between_segments_y(tan_laser, laser_b, tan(sprite_degree), sprite_b);
	printf("%.2f %.2f %.2f %.2f %.2f (%.2f, %.2f)\n", win->laser_dir, tan_laser, tan_sprite, laser_b, sprite_b, win->sprite_x[win->sprite_num], win->sprite_y[win->sprite_num]);
	if (check_map(win, win->sprite_x[win->sprite_num], win->sprite_y[win->sprite_num]) == 2)
	{
		return (1);
	}
	else
	{
		win->sprite_x[win->sprite_num] = 0;
		win->sprite_y[win->sprite_num] = 0;
	}
	return (0);
}

void	draw_sprite(t_win *win)
{
	draw_pixel(win, (int)win->sprite_x[win->sprite_num], (int)win->sprite_y[win->sprite_num], 0x888888);

	draw_pixel(win, (int)win->i, 300, 0x000000);
}
