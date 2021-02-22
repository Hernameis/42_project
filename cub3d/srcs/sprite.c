/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:07:35 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/22 17:52:11 by sunmin           ###   ########.fr       */
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

	while (win->sprite_num--)
	{
		sprite_distance = distance(win->player_x, win->sprite_x[num], win->player_y, win->sprite_y[num]);
		put_sprite(t_win *win);
	}
	return (0);
}

int		put_sprite(t_win *win)
{
	draw_pixel;
	return (0);
}
