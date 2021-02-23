/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:41:20 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/23 11:16:16 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		if_wall(int k, int height, t_win *win)
{
	if (which_wall(win) == 1)
		return (wall_w_color(k, height, win));
	else if (which_wall(win) == 2)
		return (wall_e_color(k, height, win));
	else if (which_wall(win) == 3)
		return (wall_s_color(k, height, win));
	else if (which_wall(win) == 4)
		return (wall_n_color(k, height, win));
	return (0);
}

int		which_wall(t_win *win)
{
	if ((int)win->laser_x % win->cub_width == 0)
		return (1);
	else if ((int)win->laser_x % win->cub_width == win->cub_width - 1)
		return (2);
	else if ((int)win->laser_y % win->cub_height == win->cub_height -1)
		return (3);
	else if ((int)win->laser_y % win->cub_height == 0)
		return (4);
	return (0);
}

int		wall_w_color(double k, int height, t_win *win)		// 서쪽 벽
{
	return (win->wall_w_data[((int)(64.0 / height * k) * win->wall_w_height) + (int)(64.0 / win->cub_width * ((int)win->laser_y % win->cub_width))]);
}
/*
int		wall_w_color(double k, int height, t_win *win)		// 서쪽 벽
{
	return (win->wall_w_data[(int)(64.0 / 200 * ((int)win->laser_y % 200)) + ((int)(64.0 / height * k) * win->wall_w_width)]);
}
*/
int		wall_s_color(int k, int height, t_win *win)		// 남쪽 벽
{
	return (win->wall_s_data[(int)(64.0 / 200 * ((int)win->laser_x % 200)) + ((int)(64.0 / height * k) * win->wall_s_height)]);
}

int		wall_e_color(int k, int height, t_win *win)		// 동쪽 벽
{
	return (win->wall_e_data[win->wall_e_height - (int)(64.0 / 200 * ((int)win->laser_y % 200)) + ((int)(64.0 / height * k) * win->wall_e_height)]);
}

int		wall_n_color(int k, int height, t_win *win)		// 북쪽 벽
{
	return (win->wall_n_data[win->wall_n_height - (int)(64.0 / 200 * ((int)win->laser_x % 200)) + ((int)(64.0 / height * k) * win->wall_n_height)]);
}
