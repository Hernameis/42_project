/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:41:20 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/27 10:49:30 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		which_wall(t_win *win)
{
	if (check_map(win, win->laser_x, win->laser_y + 1) == '1'
			&& check_map(win, win->laser_x, win->laser_y - 1) == '1')
	{
		if (res_double(win->cub_width, win->laser_x)
				== (int)(win->cub_width - 1))
			return (1);
		else
			return (2);
	}
	else
	{
		if (res_double(win->cub_height, win->laser_y)
				== (int)(win->cub_height - 1))
		{
			return (3);
		}
		else
		{
			return (4);
		}
	}
	return (0);
}

int		wall_e_color(int k, double height, t_win *win)
{
	return (win->wall_e_data[win->wall_e_height
			- (int)((double)(win->wall_e_width) / (int)win->cub_width
				* ((int)win->laser_y % (int)win->cub_width))
			+ ((int)((double)win->wall_e_height / height * k)
				* win->wall_e_width)]);
}

int		wall_w_color(double k, double height, t_win *win)
{
	double		x;
	double		y;
	int			color;

	x = ((int)win->laser_y % (int)win->cub_height) / win->cub_height;
	y = k / height;
	color = win->wall_w_data[(int)(x * win->wall_w_width)
		+ (int)(y * win->wall_w_height) * win->wall_w_width];
	return (color);
}

int		wall_s_color(int k, double height, t_win *win)
{
	double		x;
	double		y;
	int			color;

	x = 1 - ((int)win->laser_x % (int)win->cub_width) / win->cub_width;
	y = k / height;
	color = win->wall_s_data[(int)(x * win->wall_s_width)
		+ (int)(y * win->wall_s_height) * win->wall_s_width];
	return (color);
}

int		wall_n_color(int k, double height, t_win *win)
{
	double		x;
	double		y;
	int			color;

	x = ((int)win->laser_x % (int)win->cub_width) / win->cub_width;
	y = k / height;
	color = win->wall_n_data[(int)(x * win->wall_n_width)
		+ (int)(y * win->wall_n_height) * win->wall_n_width];
	return (color);
}
