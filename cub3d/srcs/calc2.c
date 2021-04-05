/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:00:42 by sunmin            #+#    #+#             */
/*   Updated: 2021/04/06 07:56:16 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		res_double(double a, double b)
{
	while (b >= a)
	{
		b -= a;
	}
	return ((int)b);
}

int			if_pass_sprite(t_win *win, int key)
{
	if (key == KEY_W || key == KEY_Q)
	{
		if (check_map(win, win->player_x + win->player_move_speed * 2
					* cos(win->player_dir),
					win->player_y) == '2' || check_map(win, win->player_x,
						win->player_y + win->player_move_speed * 2
						* sin(win->player_dir)) == '2')
			return (0);
	}
	else if (key == KEY_S || key == KEY_E)
	{
		if (check_map(win, win->player_x - win->player_move_speed * 2
					* cos(win->player_dir),
					win->player_y) == '2' || check_map(win, win->player_x,
						win->player_y - win->player_move_speed * 2
						* sin(win->player_dir)) == '2')
			return (0);
	}
	return (1);
}
