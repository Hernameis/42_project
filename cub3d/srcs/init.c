/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 07:30:11 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/22 17:08:35 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	struct_init(t_win *win)
{
	win->sprite_x = (double *)malloc(sizeof(double) * 1000);
	win->sprite_y = (double *)malloc(sizeof(double) * 1000);
	win->sprite_distance = (double *)malloc(sizeof(double) * 1000);

	win->scr_height = 600;
	win->scr_width = 400;
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
	win->cub_size = 200;
	win->if_sprite = 0;
}
