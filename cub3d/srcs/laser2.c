/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laser2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 08:40:01 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/26 12:14:02 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		wall_n_location_fix(t_win *win)
{
	win->laser_y = ((int)(win->laser_y / win->cub_height) + 1)
		* win->cub_height - 1;
}

void		wall_s_location_fix(t_win *win)
{
	win->laser_y = ((int)(win->laser_y / win->cub_height)) * win->cub_height;
}

void		wall_w_location_fix(t_win *win)
{
	win->laser_x = ((int)(win->laser_x / win->cub_width) + 1)
		* win->cub_width - 1;
}

void		wall_e_location_fix(t_win *win)
{
	win->laser_x = ((int)(win->laser_x / win->cub_width)) * win->cub_width;
}
