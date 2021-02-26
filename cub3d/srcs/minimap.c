/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 07:36:53 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/26 17:13:06 by sunmin           ###   ########.fr       */
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
			else if (check_map(win, (double)j, (double)i) == 2)
			{
				if (win->press_m)
					draw_pixel(win, mini_x(win, j), mini_y(win, i), 0x0ff5ee);
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

	int k = 0;
	win->sprite_num = 0;
	win->laser_dir = - 1.0 / 2.0 * win->pov * M_PI / 180;
	win->i = 0;
	while (win->i < win->scr_width)
	{
		win->one_sprite = 0;
		k++;
		win->laser_x = win->player_x;
		win->laser_y = win->player_y;
		while (win->laser_x >= 0 && win->laser_y >= 0 && win->laser_x <= win->scr_width && win->laser_y <= win->scr_height)
		{
			win->laser_x += cos(win->player_dir + win->laser_dir);
			win->laser_y += sin(win->player_dir + win->laser_dir);
			if (win->press_m)
//				draw_pixel(win, mini_x(win, win->laser_x) ,mini_y(win, win->laser_y), 0xffff00);		// 레이저 출력
			if (win->if_sprite == 0 && check_map(win, (int)win->laser_x, (int)win->laser_y) == 2 && (((int)win->laser_x % 40 == 20 && win->laser_y >= 20) || (((int)win->laser_y % 40 == 20) && win->laser_x >= 20)))
			{
				if (win->if_sprite == 0)
				{
					win->sprite_start_x[win->sprite_num] = win->laser_x;
					win->sprite_start_y[win->sprite_num] = win->laser_y;
					win->sprite_start_i[win->sprite_num] = win->i;
					printf("%f @@ %f\n", win->laser_x, win->laser_y);
				set_sprite(win);
				}
				win->one_sprite = 1;	// 스프라이트가 하나 이상
			}
			if (!(win->if_sprite == 0 && check_map(win, (int)win->laser_x, (int)win->laser_y) == 2 && (((int)win->laser_x % 40 == 20 && win->laser_y >= 20) || (((int)win->laser_y % 40 == 20) && win->laser_x >= 20))))
			{
				if (win->if_sprite)
				{
					win->if_sprite = 0;
//					win->sprite_end_x[win->sprite_num] = win->laser_x;
//					win->sprite_end_y[win->sprite_num] = win->laser_y;
					win->sprite_end_i[win->sprite_num] += 1;
				}
			}
			if (check_map(win, (int)win->laser_x, (int)win->laser_y) == 1)
				break;
		}
		dis = (distance(win, win->player_x - (int)win->laser_x + 0.5, win->player_y - (int)win->laser_y)) * cos(degree_from_xy(win->player_x, win->laser_x, win->player_y, win->laser_y) - win->player_dir);


		draw_wall(win, win->i, dis);
		if (win->one_sprite)
		{
			draw_sprite(win, win->s);
		}
		win->sprite_num = 0;
		win->i++;
		win->laser_dir += win->pov * M_PI / 180 / win->scr_width;
	}

}

void	draw_wall(t_win *win, int i, double dis)
{
//	return ;
	double	start;
	double	end;
	int		j;
	int		color;
	double	wall_half_height;
	double	degree;
	double	k;

	wall_half_height = win->scr_height * 10 * 5 / dis;
	start = win->scr_height / 2 - wall_half_height;
	win->start = start;
//	if (start <= 0)
//		start = 0;
	end = win->scr_height / 2 + wall_half_height;
	win->end = end;
	win->start_end = end - start;
//	printf("%f @@  %f @@  %f\n", start, end, start / (end - start));
//	if (end >= win->scr_height - 1)
//		end = win->scr_height - 1;
	j = 0;
	k = 0;
	while (j < win->scr_height)
	{
		if (j > start && j < end)
		{
			if (start < 0)
			{
				color = if_wall(k - start / (end - start) * wall_half_height * 2, wall_half_height * 2, win);
			}
			else
				color = if_wall(k, wall_half_height * 2, win);
			if (player_life_check(win, i, j) != 1)
			{
				if (check_pixel(win, i, j, 0xffff00) == 0)	// 레이저랑 안겹치게
					draw_pixel(win, i, j, color);
			}
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
