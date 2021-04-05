/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:05:18 by sunmin            #+#    #+#             */
/*   Updated: 2021/04/05 14:12:05 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		if_wall(int k, double height, t_win *win)
{
	if (which_wall(win) == 1)
	{
		return (wall_e_color(k, height, win));
	}
	else if (which_wall(win) == 2)
	{
		return (wall_w_color(k, height, win));
	}
	else if (which_wall(win) == 3)
	{
		return (wall_s_color(k, height, win));
	}
	else if (which_wall(win) == 4)
	{
		return (wall_n_color(k, height, win));
	}
	return (0);
}

int		which_wall2(t_win *win)					// 조건문 수정
{
//	if (check_map(win, win->laser_x, win->laser_y + 1) == '1'		//	이 부분을
//			&& check_map(win, win->laser_x, win->laser_y - 1) == '1')		//	수정해야 함
//	{
		if (res_double(win->cub_width, win->laser_x) < 1)
			return (1);
		else if (res_double(win->cub_width, win->laser_x) >= 1)
			return (2);
//	}
//	else
//	{
		else if (res_double(win->cub_height, win->laser_y) < 1)
			return (4);
		else
			return (3);
//	}
	return (0);
}

/*
int		which_wall2(t_win *win)					// 조건문 수정
{
	if (check_map(win, win->laser_x, (int)(win->laser_y + 1)) == '1'		//	이 부분을
			&& check_map(win, win->laser_x, win->laser_y - 1) == '1')		//	수정해야 함
	{
		if (res_double(win->cub_width, win->laser_x) < 1)
			return (1);
		else
			return (2);
	}
	else
	{
		if (res_double(win->cub_height, win->laser_y) < 1)
		{
			return (4);
		}
		else
		{
			return (3);
		}
	}
	return (0);
}
*/

int		wall_corner(t_win *win)
{
	if (check_map(win, win->laser_x - 0.01, win->laser_y) == '1')
		return (1);
	else if (check_map(win, win->laser_x + 0.01, win->laser_y) == '1')
		return (2);
	return (0);
}
