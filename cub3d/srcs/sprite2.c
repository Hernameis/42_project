/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 21:40:42 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/02 23:54:24 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		first_sprite(t_win *win)
{
	if (win->i <= win->sprite_start_check[win->sprite_check_height][win->sprite_check_width])
	{
		win->sprite_start_check[win->sprite_check_height][win->sprite_check_width] = win->i;
		return (1);
	}
	return (0);
}

int		last_sprite(t_win *win)
{
	if (win->i >= win->sprite_start_check[win->sprite_check_height][win->sprite_check_width])
	{
		win->sprite_end_check[win->sprite_check_height][win->sprite_check_width] = win->i;
		return (1);
	}
	return (0);
}

int		call_sprite_idx_first(t_win *win)
{
	return (win->sprite_start_check[win->sprite_check_height][win->sprite_check_width]);
}

int		call_sprite_idx_last(t_win *win)
{
	return (win->sprite_end_check[win->sprite_check_height][win->sprite_check_width]);
}

int		left_right_from_sprite(t_win *win)
{
	win->sprite_p_dir = degree_from_xy(win->player_x, win->sprite_x[win->sprite_num], win->player_y, win->sprite_y[win->sprite_num]);
	if (win->laser_dir + win->player_dir < win->sprite_p_dir)
	{
		return (-1);
	}
	return (1);
}
