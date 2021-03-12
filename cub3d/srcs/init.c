/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 07:30:11 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/12 18:14:51 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	struct_init(t_win *win)
{
	//		파싱으로 처리할 부분
	win->map_width = -2147483648;
	win->map_height = 0;
	win->check_map = 0;
	win->parse_map = ft_strdup("");

	//


	win->press_w = 0;
	win->press_s = 0;
	win->press_a = 0;
	win->press_d = 0;
	win->press_q = 0;
	win->press_e = 0;
	win->press_m = 0;
	win->key_ad = 0;
	win->key_ws = 0;


	win->laser_x = 0;
	win->laser_y = 0;
	win->laser_dir = 0;
	win->pov = 66;
	win->minimap_size = 3;
	win->i = 0;

	// 보너스
	win->player_life = 100;


	// 스프라이트 맵
}

void	struct_init2(t_win *win)
{

	win->cub_height = win->scr_height / (double)win->map_height;
	win->cub_width = win->scr_width / (double)win->map_width;
	win->player_x = win->player_x * win->cub_width + win->cub_width / 2.0;
	win->player_y = win->player_y * win->cub_height + win->cub_height / 2.0;
	win->player_dir = win->player_dir * M_PI / 180;
	win->scr_height = win->scr_height;
	win->scr_width = win->scr_width;
	win->player_move_speed = (int)((win->scr_height + win->scr_width) / 500 + 1.5);


}
