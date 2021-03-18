/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:41:20 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/18 09:12:01 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		if_wall(int k, double height, t_win *win)
{

	if (which_wall(win) == 1)
	{
		return (wall_w_color(k, height, win));
	}
	else if (which_wall(win) == 2)
	{
		return (wall_e_color(k, height, win));
	}
	else if (which_wall(win) == 3)
	{
		return (wall_n_color(k, height, win));
	}
	else if (which_wall(win) == 4)
	{
		return (wall_s_color(k, height, win));
	}
	return (0);
}

int		which_wall(t_win *win)
{
	if (check_map(win, win->laser_x, win->laser_y + 1) == '1' && check_map(win, win->laser_x, win->laser_y - 1) == '1')		// 동서인지
	{
		if (res_double(win->laser_x, win->cub_width) >= 0 && res_double(win->laser_x, win->cub_width) < 1)
//		if ((int)win->laser_x % (int)win->cub_width == 0)								// 동쪽 벽
			return (1);
		else //if ((int)win->laser_x % (int)win->cub_width == win->cub_width - 1)			// 서쪽 벽
			return (2);
	}
	else		// 남북인지
	{
		if (res_double(win->laser_y, win->cub_height) >= 0 && res_double(win->laser_x, win->cub_width) < 1)
//		if ((int)win->laser_y % (int)win->cub_height == 0)							// 북쪽 벽
			return (4);
		else	//if ((int)win->laser_y % (int)win->cub_height == win->cub_height -1)		// 남쪽 벽
			return (3);


	}
	return (0);
}

int		wall_e_color(int k, double height, t_win *win)		// 동쪽 벽			????
{
	return (win->wall_e_data[win->wall_e_height - (int)((double)(win->wall_e_width) / (int)win->cub_width * ((int)win->laser_y % (int)win->cub_width)) + ((int)((double)win->wall_e_height / height * k) * win->wall_e_width)]);
}

int		wall_w_color(double k, double height, t_win *win)		// 서쪽 벽
{
	double		x;
	double		y;
	int			color;

	x = ((int)win->laser_y % (int)win->cub_height) / win->cub_height;
	y = k / height;
	color = win->wall_w_data[(int)(x * win->wall_w_width) + (int)(y * win->wall_w_height) * win->wall_w_width];
	return (color);

}

int		wall_s_color(int k, double height, t_win *win)		// 남쪽 벽			?????
{
	double		x;
	double		y;
	int			color;

	x = ((int)win->laser_x % (int)win->cub_width) / win->cub_width;
	y = k / height;
	color = win->wall_s_data[(int)(x * win->wall_s_width) + (int)(y * win->wall_s_height) * win->wall_s_width];
	return (color);
	
//	return (win->wall_s_data[(int)((double)win->wall_s_width / (int)win->cub_width * ((int)win->laser_x % (int)win->cub_width)) + ((int)((double)win->wall_s_height / height * k) * win->wall_s_width)]);
}

int		wall_n_color(int k, double height, t_win *win)		// 북쪽 벽
{
	double		x;
	double		y;
	int			color;

	x = ((int)win->laser_x % (int)win->cub_width) / win->cub_width;
	y = k / height;
	color = win->wall_n_data[(int)(x * win->wall_n_width) + (int)(y * win->wall_n_height) * win->wall_n_width];
	return (color);
}
