/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 07:30:11 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/05 17:29:50 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	struct_init(t_win *win)
{
	win->map_width = 10;
	win->map_height = 10;
	win->screen_width = 500;
	win->screen_height = 500;
	win->cub_height = win->screen_height / win->map_height;
	win->cub_width = win->screen_width / win->map_width;
	win->scr_height = win->screen_height;
	win->scr_width = win->screen_width;
	win->press_w = 0;
	win->press_s = 0;
	win->press_a = 0;
	win->press_d = 0;
	win->press_q = 0;
	win->press_e = 0;
	win->press_m = 0;
	win->key_ad = 0;
	win->key_ws = 0;
	win->player_x = win->scr_width / 2;
	win->player_y = win->scr_height / 2;
	win->player_dir = 0;
	win->player_move_speed = (int)((win->scr_height + win->scr_width) / 500 + 1.5);
	win->laser_x = 0;
	win->laser_y = 0;
	win->laser_dir = 0;
	win->pov = 60;
	win->minimap_size = 3;
	win->i = 0;

	// 보너스
	win->player_life = 100;


	// 스프라이트 맵
}
