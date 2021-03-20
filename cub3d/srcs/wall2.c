/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:05:18 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/20 11:06:46 by sunmin           ###   ########.fr       */
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
