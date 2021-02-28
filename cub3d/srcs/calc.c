/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 12:01:04 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/28 23:15:46 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	distance(t_win *win, double a, double b)
{
	double	aa;
	double	bb;
	double	aabb;
	double	c;

	aa = a * a;
	bb = b * b;
	aabb = aa + bb;
//	printf("%f @@  %f @@ %f\n", aa, bb, aabb);
	c = sqrt(a * a + b * b);
	return (c);
}

double	degree_from_xy(double x1, double x2, double y1, double y2)
{
	return (atan2(y2 - y1, x2 - x1));
}

int		if_pass_wall(t_win *win, int key)
{
	if (key == key_w || key == key_q)
	{
		return (check_map(win, win->player_x + 15 * cos(win->player_dir), win->player_y + 15 * sin(win->player_dir)));
	}
	else if (key == key_s || key == key_e)	// e키일때는 뚫리는 상황 있음
	{
		return (check_map(win, win->player_x - 15 * cos(win->player_dir), win->player_y - 15 * sin(win->player_dir)));
	}
	return (0);
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
