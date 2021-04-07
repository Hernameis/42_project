/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:41:20 by sunmin            #+#    #+#             */
/*   Updated: 2021/04/07 11:04:35 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		which_wall(t_win *win)
{
	if (win->hor_ver % 2 == 0)
	{
		if (res_double(win->cub_width, win->laser_x)
				== (int)(win->cub_width - 1))
			return (2);
		else
			return (1);
	}
	else
	{
		if (res_double(win->cub_height, win->laser_y)
				== (int)(win->cub_height - 1))
			return (4);
		else
			return (3);
	}
	return (0);
}

int		wall_e_color(int k, double height, t_win *win)
{
	double		x;
	double		y;
	int			color;

	x = res_double(win->cub_height, win->laser_y) / win->cub_height;
	y = k / height;
	color = win->wall_e_data[(int)(x * (win->wall_e_width - 1))
		+ (int)(y * (win->wall_e_height - 1)) * win->wall_w_width];
	return (color);
}

int		wall_w_color(double k, double height, t_win *win)
{
	double		x;
	double		y;
	int			color;

	x = 1 - res_double(win->cub_height, win->laser_y) / win->cub_height;
	y = k / height;
	color = win->wall_w_data[(int)(x * (win->wall_w_width - 1))
		+ (int)(y * (win->wall_w_height - 1)) * win->wall_w_width];
	return (color);
}

int		wall_s_color(int k, double height, t_win *win)
{
	double		x;
	double		y;
	int			color;

	x = 1 - res_double(win->cub_width, win->laser_x) / win->cub_width;
	y = k / height;
	color = win->wall_s_data[(int)(x * (win->wall_s_width - 1))
		+ (int)(y * (win->wall_s_height - 1)) * win->wall_s_width];
	return (color);
}

int		wall_n_color(int k, double height, t_win *win)
{
	double		x;
	double		y;
	int			color;

	x = res_double(win->cub_width, win->laser_x) / win->cub_width;
	y = k / height;
	color = win->wall_n_data[(int)(x * (win->wall_n_width - 1))
		+ (int)(y * (win->wall_n_height - 1)) * win->wall_n_width];
	return (color);
}
