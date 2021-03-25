/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:05:18 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/25 11:27:11 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		if_wall(int k, double height, t_win *win)
{
	if (which_wall(win) == 1)
	{
		return (0x111111);
		return (wall_e_color(k, height, win));		//동
	}
	else if (which_wall(win) == 2)
	{
		return (0xff00ff);
		return (wall_w_color(k, height, win));		//서
	}
	else if (which_wall(win) == 3)
	{
		return (0x00ff5ee);
		return (wall_n_color(k, height, win));		//북
	}
	else if (which_wall(win) == 4)
	{
		return (0x00ff00);
		return (wall_s_color(k, height, win));
	}
	return (0);
}

int		which_wall2(t_win *win)
{
	if (check_map(win, win->laser_x, win->laser_y + 1) == '1'
			&& check_map(win, win->laser_x, win->laser_y - 1) == '1')
	{
		if (res_double(win->cub_width, win->laser_x) < 1)
		{
//			printf("e\n");
			return (1);
		}
		else
		{
//			printf("w\n");
			return (2);
		}
	}
	else
	{
		if (res_double(win->cub_height, win->laser_y) < 1)
		{
			{
//			printf("s\n");
				return (4);
			}
		}
		else
		{
			{
//			printf("n\n");
				return (3);
			}
		}
	}
	return (0);
}
