/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 23:54:28 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/03 00:09:25 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	idx_between_sprite_center(t_win *win)
{
	int		left_right;

	left_right = left_right_from_sprite(win);
	win->sprite_index = left_right * distance(win, win->sprite_x[win->sprite_num] - win->sprite_center_x[win->sprite_num], win->sprite_y[win->sprite_num] - win->sprite_center_y[win->sprite_num]) + win->sprite_len / 2;

//	printf("%f\n", win->sprite_index);
}
