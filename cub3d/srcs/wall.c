/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:41:20 by sunmin            #+#    #+#             */
/*   Updated: 2021/04/05 13:58:13 by sunmin           ###   ########.fr       */
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
	else if (check_map(win, win->laser_x + 1, win->laser_y) == '1'
			&& check_map(win, win->laser_x - 1, win->laser_y) == '1')
	{
		if (res_double(win->cub_height, win->laser_y)
				== (int)(win->cub_height - 1))
			return (3);
		else
			return (4);
	}
	else
		return (wall_corner(win));
	return (0);
}

int		wall_e_color(int k, double height, t_win *win)
{
	return (0xff5ee);	//////////
	double		x;
	double		y;
	int			color;

	x = 1 - res_double(win->cub_height, win->laser_y) / win->cub_height;
	y = k / height;
	color = win->wall_e_data[(int)(x * win->wall_e_width)
		+ (int)(y * win->wall_e_height) * win->wall_w_width];
	return (color);
}

int		wall_w_color(double k, double height, t_win *win)
{
	return (0xff0000);		//////////
	double		x;
	double		y;
	int			color;

	x = res_double(win->cub_height, win->laser_y) / win->cub_height;
	y = k / height;
	color = win->wall_w_data[(int)(x * win->wall_w_width)
		+ (int)(y * win->wall_w_height) * win->wall_w_width];
	return (color);
}

int		wall_s_color(int k, double height, t_win *win)
{
	return (0x00ff00);		////////////
	double		x;
	double		y;
	int			color;

	x = res_double(win->cub_width, win->laser_x) / win->cub_width;
	y = k / height;
	color = win->wall_s_data[(int)(x * win->wall_s_width)
		+ (int)(y * win->wall_s_height) * win->wall_s_width];
	return (color);
}

int		wall_n_color(int k, double height, t_win *win)
{
	return (0x0000ff);//		//////////
	double		x;
	double		y;
	int			color;

	x = 1 - res_double(win->cub_width, win->laser_x) / win->cub_width;
	y = k / height;
	color = win->wall_n_data[(int)(x * win->wall_n_width)
		+ (int)(y * win->wall_n_height) * win->wall_n_width];
	return (color);
}
