/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 07:30:11 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/21 07:56:30 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	struct_init(t_win *win)
{
	win->scr_height = 200;
	win->scr_width = 300;
	win->press_w = 0;
	win->press_s = 0;
	win->press_a = 0;
	win->press_d = 0;
	win->key_ad = 0;
	win->key_ws = 0;
	win->player_x = win->scr_width / 2;
	win->player_y = win->scr_height / 2;
	win->player_dir = 0;
	win->laser_x = 0;
	win->laser_y = 0;
	win->laser_dir = 0;
}
