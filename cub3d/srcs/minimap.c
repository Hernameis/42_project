/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 07:36:53 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/22 17:10:53 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_grid(t_win *win)		// 그리드 그냥 채움
{
	int i;
	int j;

	i = 0;
	while (i < win->scr_height)
	{
		j = 0;
		while (j < win->scr_width)
		{
			if (check_map(win, (double)j, (double)i) == 1)
			{
				if (win->press_m)
					draw_pixel(win, mini_x(win, j), mini_y(win, i), 0x888888);
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
	i = -7;
	while (i < 7)
	{
		j = -7;
		while (j < 7)
		{
			if (win->press_m)
				draw_pixel(win, mini_x(win, (int)win->player_x + j), mini_y(win, (int)win->player_y + i), 0x00ffee);
			j++;
		}
		i++;
	}
}

void	put_laser(t_win *win)
{
	double	temp;
	double	dis;

	win->sprite_num = 0;
	win->laser_dir = - 1.0 / 2.0 * win->pov * M_PI / 180;
	win->i = 0;
	while (win->i < win->scr_width)
	{
		win->laser_x = win->player_x;
		win->laser_y = win->player_y;
		while (win->laser_x >= 0 && win->laser_y >= 0 && win->laser_x <= win->scr_width && win->laser_y <= win->scr_height)		// 이 조건 없이 while(1)이면 세그폴트 // 벽조건 있으면 상관없을지도
		{
			win->laser_x += cos(win->player_dir + win->laser_dir);
			win->laser_y += sin(win->player_dir + win->laser_dir);
//			if (win->press_m && i >= win->scr_width / 2 - 1 && i <= win->scr_width / 2 + 1)
//				draw_pixel(win, mini_x(win, (int)(win->laser_x)), mini_y(win, (int)(win->laser_y)), 0xffff00);
			if (win->if_sprite == 0 && check_map(win, (int)win->laser_x, (int)win->laser_y) == 2)
				start_sprite(win);
			if (win->if_sprite == 1 && check_map(win, (int)win->laser_x, (int)win->laser_y) != 2)
				end_sprite(win);
			if (check_map(win, (int)win->laser_x, (int)win->laser_y) == 1)
				break;
		}
		dis = (distance(win, win->player_x - (int)win->laser_x + 0.5, win->player_y - (int)win->laser_y)) * cos(degree_from_xy(win->player_x, win->laser_x, win->player_y, win->laser_y) - win->player_dir);
//		printf("%f\n", dis);
		draw_wall(win, win->i, dis);
		draw_sprite(win);
		win->i++;
		win->laser_dir += win->pov * M_PI / 180 / win->scr_width;
	}
}

void	draw_wall(t_win *win, int i, double dis)
{
	int		start;
	int		end;
	int		j;
	int		color;
	double	wall_half_height;
	double	degree;
	int		k;

	wall_half_height = win->scr_height * 10 * 5 / dis;
	start = win->scr_height / 2 - wall_half_height;
	end = win->scr_height / 2 + wall_half_height;
	j = 0;
	k = 0;
	while (j < win->scr_height)
	{
		if (j > start && j < end)
		{
			color = if_wall(k, wall_half_height * 2, win);
			draw_pixel(win, i, j , color);
			k++;
		}
		else
		{
			if (j < win->scr_height / 2)
				color = 0x87ceeb;
			else
				color = 0xffd700;
		}
			draw_pixel(win, i, j, color);
		j++;
	}
}

int		mini_x(t_win *win, int x)
{
	return (x / win->minimap_size + (int)(win->scr_width * (win->minimap_size - 1) / win->minimap_size));
}

int		mini_y(t_win *win, int y)
{
	return (y / win->minimap_size);
}
