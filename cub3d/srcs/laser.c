/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   laser.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 07:36:53 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/18 09:50:13 by sunmin           ###   ########.fr       */
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
			if (check_map(win, (double)j, (double)i) == '1')
			{
				if (win->press_m)
					draw_pixel(win, j, i, 0x888888);
		//			draw_pixel(win, mini_x(win, j), mini_y(win, i), 0x888888);
			}
			else if (check_map(win, (double)j, (double)i) == '2')
			{
				if (win->press_m)
					draw_pixel(win, j, i, 0x0ff5ee);
				//	draw_pixel(win, mini_x(win, j), mini_y(win, i), 0x0ff5ee);
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
	double	a_i = ((win->scr_width - 1) / -2);
	win->dist = 1 / tan(win->pov *M_PI / 180 / 2) * win->scr_width / 2;
	win->i = 0;
	while (a_i < (int)win->scr_width / 2)
	{
		win->laser_dir = atan2(a_i, win->dist);
		k++;
		win->laser_x = win->player_x;
		win->laser_y = win->player_y;
		while (win->laser_x >= 0 && win->laser_y >= 0 && win->laser_x <= win->scr_width && win->laser_y <= win->scr_height)
		{
			win->laser_x += cos(win->player_dir + win->laser_dir);
			win->laser_y += sin(win->player_dir + win->laser_dir);
			if (check_map(win, win->laser_x, win->laser_y) == '1')
				break;
		}
		win->wall_dis = (distance(win->player_x - win->laser_x, win->player_y - (win->laser_y))) * cos(degree_from_xy(win->player_x, win->laser_x, win->player_y, win->laser_y) - win->player_dir);
		win->dis_for_check[win->i] = win->wall_dis;
		draw_wall(win, win->i, win->wall_dis);
		win->i++;
		a_i++;
	}
}

void	draw_wall(t_win *win, int i, double dis)
{
	double	start;
	double	end;
	int		j;
	int		color;
	double	wall_half_height;
	double	k;
	double	scr_height;
	wall_half_height = win->scr_height / dis * 25;
	start = win->scr_height / 2 - wall_half_height;
	end = win->scr_height / 2 + wall_half_height;
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
			{
				color = if_wall(k, wall_half_height * 2, win);
			}
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

void	draw_sprite(t_win *win)
{
	int		num;

	put_sprite(win);
	num = win->sprite_num;
	while (num >= 0)
	{
		if (check_sprite(win, num))
		{
			sprite_pixel(win, num);
		}
		num--;
	}
}

int		check_sprite(t_win *win, int num)		//	보이는 스프라이트인지
{
	within_degree(win);
	if (win->sprite[num].degree >= win->player_dir - (win->pov + 20) / 2 * M_PI / 180 && win->sprite[num].degree <= win->player_dir + (win->pov + 20) / 2 * M_PI / 180)// 각도 안에 들어오면	// 그리고 벽보다 가까우면
	{
		return (1);
	}
	return (0);
}

void	put_sprite(t_win *win)
{
	int		num;

	num = 0;
	while (num < win->sprite_num)
	{
		win->sprite[num].distance = distance(win->player_x - win->sprite[num].center_x, win->player_y - win->sprite[num].center_y);
		win->sprite[num].degree = degree_from_xy(win->player_x, win->sprite[num].center_x, win->player_y, win->sprite[num].center_y);
		num++;
	}
	compare_sprite(win, win->sprite_num);
}

void	sprite_pixel(t_win *win, int num)
{
	int		i;
	int		j;
	double	half;
	int		start;
	int		end;
	double	center;
	int		start_w;
	int		end_w;

	center = (win->sprite[num].degree - win->player_dir + (win->pov * M_PI / 180) / 2) / (win->pov * M_PI / 180) * win->scr_width;
	half = win->scr_height / win->sprite[num].distance * 55;
	start = (int)(win->scr_height / 2 - half);
	end = (int)(win->scr_height / 2 + half);
	start_w = (int)(center - half);
	end_w = (int)(center + half);
	i = start;
	while (i < end)
	{
		j = start_w;
		while (j < end_w)
		{
			if ((sprite_color(win, i - start, end - start, j - start_w, end_w - start_w)) != 0)
			{
				if (i >= 0 && j >= 0 && i < win->scr_height && j < win->scr_width)
				{
					if (win->dis_for_check[j] > win->sprite[num].distance)
					{
						draw_pixel(win, j, i, sprite_color(win, i - start, end - start, j - start_w, end_w - start_w));
					}
				}
			}
			j++;
		}
		i++;
	}
}

int		sprite_color(t_win *win, int i, int height, int j, int width)
{
//	return (0x000001);
	double	x;
	double	y;
	int		color;

	x = i / (double)height;
	y = j / (double)width;
	color = win->sprite_data[(int)(x * win->sprite_width) + (int)(y * win->sprite_height) * win->sprite_width];
	return (color);
}

void	compare_sprite(t_win *win, int num)
{
	int		i;
	int		j;
	double	temp_distance;
	double	temp_degree;

	i = num;
	while (i > 0)
	{
		j = 0;
		while (j < num - 1)
		{
			if (win->sprite[j].distance > win->sprite[j + 1].distance)
			{
				temp_distance = win->sprite[j + 1].distance;
				temp_degree = win->sprite[j + 1].degree;
				win->sprite[j + 1].distance = win->sprite[j].distance;
				win->sprite[j + 1].degree = win->sprite[j].degree;
				win->sprite[j].distance = temp_distance;
				win->sprite[j].degree = temp_degree;
			}
			j++;
		}
		i--;
	}
}
