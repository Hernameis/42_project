/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 12:01:04 by sunmin            #+#    #+#             */
/*   Updated: 2021/04/06 07:56:48 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	distance(double a, double b)
{
	double	aa;
	double	bb;
	double	aabb;
	double	c;

	aa = a * a;
	bb = b * b;
	aabb = aa + bb;
	c = sqrt(aabb);
	return (c);
}

double	degree_from_xy(double x1, double x2, double y1, double y2)
{
	return (atan2(y2 - y1, x2 - x1));
}

int		if_pass_wall(t_win *win, int key)
{
	if (key == KEY_W || key == KEY_Q)
	{
		if (check_map(win, win->player_x + win->player_move_speed
					* 2 * cos(win->player_dir),
					win->player_y) == '1' || check_map(win, win->player_x,
						win->player_y + win->player_move_speed * 2
						* sin(win->player_dir)) == '1')
			return (0);
	}
	else if (key == KEY_S || key == KEY_E)
	{
		if (check_map(win, win->player_x - win->player_move_speed
					* 2 * cos(win->player_dir),
					win->player_y) == '1' || check_map(win, win->player_x,
						win->player_y - win->player_move_speed * 2
						* sin(win->player_dir)) == '1')
			return (0);
	}
	return (1);
}

void	within_degree(t_win *win)
{
	while (win->player_dir < -1 * M_PI || win->player_dir > M_PI)
	{
		if (win->player_dir < -1 * M_PI)
			win->player_dir += 2 * M_PI;
		if (win->player_dir > M_PI)
			win->player_dir -= 2 * M_PI;
	}
}

double	within_degree_double(double degree)
{
	while (degree < -1 * M_PI || degree > M_PI)
	{
		if (degree < -1 * M_PI)
			degree += 2 * M_PI;
		if (degree > M_PI)
			degree -= 2 * M_PI;
	}
	return (degree);
}
