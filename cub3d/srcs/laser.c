/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laser.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 07:36:53 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/03 00:02:20 by sunmin           ###   ########.fr       */
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
		//			draw_pixel(win, j, i, 0x888888);
					draw_pixel(win, mini_x(win, j), mini_y(win, i), 0x888888);
			}
			else if (check_map(win, (double)j, (double)i) == 2)
			{
				if (win->press_m)
					draw_pixel(win, j, i, 0x0ff5ee);
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
				draw_pixel(win, (int)win->player_x + j, (int)win->player_y + i, 0x00ffee);
//				draw_pixel(win, mini_x(win, (int)win->player_x + j), mini_y(win, (int)win->player_y + i), 0x00ffee);
			j++;
		}
		i++;
	}
}

void	put_laser(t_win *win)
{
	int k = 0;

	win->sprite_num = 0;
	win->sprite_x[win->sprite_num] = 0;
	win->sprite_y[win->sprite_num] = 0;
	win->sprite_exist = 0;
	win->laser_dir = - 1.0 / 2.0 * win->pov * M_PI / 180;
	win->i = 0;
	while (win->i < win->scr_width)
	{
		win->sprite_center_x[win->sprite_num] = 0;
		win->sprite_center_y[win->sprite_num] = 0;
		win->if_sprite = 0;
		win->sprite_end = 0;
		k++;
		win->laser_x = win->player_x;
		win->laser_y = win->player_y;
		while (win->laser_x >= 0 && win->laser_y >= 0 && win->laser_x <= win->scr_width && win->laser_y <= win->scr_height)
		{
			win->laser_x += cos(win->player_dir + win->laser_dir);
			win->laser_y += sin(win->player_dir + win->laser_dir);
//			if (win->press_m)
//				draw_pixel(win, mini_x(win, win->laser_x) ,mini_y(win, win->laser_y), 0xffff00);		// 미니맵 레이저 출력
		//	if (!win->press_m)
		//		draw_pixel(win, win->laser_x, win->laser_y, 0xfff00);		// 레이저 출력
/*			if (check_map(win, (int)win->laser_x, (int)win->laser_y) == 2)	// 스프라이트 인덱스
			{
				check_sprite_center(win);
				first_sprite(win);
				last_sprite(win);
			}*/
			if (check_map(win, win->laser_x, win->laser_y) == 2 && win->if_sprite == 0)		// 스프라이트를 만나면
			{
				win->sprite_exist = 1;
				win->if_sprite = 1;
				if (win->sprite_center_x[win->sprite_num] == 0)
				{
					check_sprite_center(win);
					win->sprite_num++;
				}
				else
				{
					win->if_sprite = 0;
				}
			}
			if (win->if_sprite)	// 스프라이트 인덱스
			{
				check_sprite_center(win);
				first_sprite(win);
				last_sprite(win);
			}
			if (check_map(win, (int)win->laser_x, (int)win->laser_y) == 1)
			{
				win->sprite_end = 1;
				win->if_sprite = 0;
				break;
			}
		}
		if (win->sprite_exist && win->sprite_end == 1)
		{
			while (win->sprite_num != 0)
			{
				win->sprite_num--;
				if_sprite_plane(win);
				idx_between_sprite_center(win);
				win->sprite_dis = distance(win, win->player_x - win->sprite_x[win->sprite_num], win->player_y - win->sprite_y[win->sprite_num]);
			}
		}
		win->wall_dis = (distance(win, win->player_x - (int)win->laser_x + 0.5, win->player_y - (int)win->laser_y)) * cos(degree_from_xy(win->player_x, win->laser_x, win->player_y, win->laser_y) - win->player_dir);
		draw_wall(win, win->i, win->wall_dis);
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

	wall_half_height = win->scr_height / dis * 5 * 2 ;
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

void	put_laser_sprite(t_win *win)
{

	win->sprite_num = 0;
	win->sprite_x[win->sprite_num] = 0;
	win->sprite_y[win->sprite_num] = 0;

	win->sprite_exist = 0;
	win->laser_dir = - 1.0 / 2.0 * win->pov * M_PI / 180;
	win->i = 0;
	while (win->i < win->scr_width)
	{
		win->sprite_center_x[win->sprite_num] = 0;
		win->sprite_center_y[win->sprite_num] = 0;
		win->if_sprite = 0;
		win->sprite_end = 0;
		win->laser_x = win->player_x;
		win->laser_y = win->player_y;
		while (win->laser_x >= 0 && win->laser_y >= 0 && win->laser_x <= win->scr_width && win->laser_y <= win->scr_height)
		{
			win->laser_x += cos(win->player_dir + win->laser_dir);
			win->laser_y += sin(win->player_dir + win->laser_dir);
		if (check_map(win, win->laser_x, win->laser_y) == 2 && win->if_sprite == 0)		// 스프라이트를 만나면
		{
			win->sprite_exist = 1;
			win->if_sprite = 1;
			if (win->sprite_center_x[win->sprite_num] == 0)
			{
				check_sprite_center(win);
				win->sprite_num++;
			}
			else
			{
				win->if_sprite = 0;
			}
		}
			if (check_map(win, (int)win->laser_x, (int)win->laser_y) == 1)
			{
				win->sprite_end = 1;
				win->if_sprite = 0;
				break;
			}
		}
		if (win->sprite_exist && win->sprite_end == 1)
		{
			while (win->sprite_num != 0)
			{
				win->sprite_num--;
				if_sprite_plane(win);
				win->sprite_dis = distance(win, win->player_x - win->sprite_x[win->sprite_num], win->player_y - win->sprite_y[win->sprite_num]);
				if (win->sprite_dis < win->wall_dis)
				{
					draw_sprite(win);
					draw_sprite_plane(win);
				}
			}
		}

		/*
		if(first_sprite(win))
		{
			win->sprite_start_idx = win->i;
		}
		if(last_sprite(win))
		{
			win->sprite_end_idx = win->i;
		}
		*/
		win->i++;
		win->laser_dir += win->pov * M_PI / 180 / win->scr_width;
	}
}
