/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 07:36:53 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/21 09:49:58 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_grid(t_win *win)
{
	int i;
	int j;

	i = 0;
	while (i < win->scr_height)
	{
		j = 0;
		while (j < win->scr_width)
		{
			if (j % (int)(win->scr_width / win->map_width) == 1)
			{
				draw_pixel(win, j, i, 0x888888);
			}
			j++;
		}
		i++;
	}
}

void	put_player(t_win *win)
{
	int		i;
	int		j;
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			draw_pixel(win, (int)win->player_x + j, (int)win->player_y + i, 0x00ffee);
			j++;
		}
		i++;
	}
}

void	put_laser(t_win *win)
{
	win->laser_x = win->player_x;
	win->laser_y = win->player_y;
	win->laser_dir = win->player_dir;
	while (win->laser_x >= 0 && win->laser_y >= 0 && win->laser_x <= win->scr_width && win->laser_y <= win->scr_height)		// 이 조건 없이 while(1)이면 세그폴트
	{
		win->laser_x += cos(win->laser_dir);
		win->laser_y += sin(win->laser_dir);
		draw_pixel(win, (int)win->laser_x, (int)win->laser_y, 0xffff00);
		if (check_map(win, (int)win->laser_x, (int)win->laser_y) == 1)
			break;
	}
}

/// 나중에 지울 함수
//
//
void	cjswkd(t_win *win)
{
	int	i;
	int	j;
	i = 0;
	while (i < win->scr_height)
	{
		j = 0;
		while (j < win->scr_width)
		{
			draw_pixel(win, j, i, 0x000000);
			j++;
		}
		i++;
	}
}
