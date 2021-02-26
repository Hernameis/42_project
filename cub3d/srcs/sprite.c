/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 15:07:35 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/26 18:31:07 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		set_sprite(t_win *win)	// 스프라이트를 만나는 중간 레이저의 절편 중간 값을 구해서 거기를 기준으로 카메라 평면에 수직으로 레이저 하나의 각도만큼 가면서 체크 하면서 그 점을 저장
{
	win->sprite_x[win->sprite_num] = win->laser_x;
	win->sprite_y[win->sprite_num] = win->laser_y;
	{
		draw_pixel(win, mini_x(win, win->sprite_x[win->sprite_num]), mini_y(win, win->sprite_y[win->sprite_num]), 0xff0000);	// 좌표	찍어보기
		draw_pixel(win, win->sprite_x[win->sprite_num], win->sprite_y[win->sprite_num], 0xff0000);
	}
	win->sprite_num++;
	return (0);
}

int		draw_sprite(t_win *win, int i)
{
//	return 0;
	while (win->sprite_num-- > 0)
	{
		win->sprite_distance[win->sprite_num] = distance(win, win->sprite_x[win->sprite_num] - win->player_x, win->sprite_y[win->sprite_num] - win->player_y);	// * cos(degree_from_xy(win->player_x, win->sprite_x[win->sprite_num], win->player_y, win->sprite_y[win->sprite_num]) - win->player_dir);
//		printf("%f\n", win->sprite_distance[win->sprite_num]);
//		printf("%f %f, %f %f\n", win->sprite_x[win->sprite_num], win->sprite_y[win->sprite_num], win->player_x, win->player_y);
//		printf("%f\n", win->sprite_distance[win->sprite_num]);
		put_sprite(win);
	}
	return (0);
}

int		put_sprite(t_win *win)
{
//	return 0;
	double		half_height;
	double		end;
	double		start;
	double		start_end;
	double		i;
	int			color;

	win->sprite_len[win->sprite_num] = distance(win, fabs(win->sprite_start_x[win->sprite_num] - win->sprite_end_x[win->sprite_num]), fabs(win->sprite_start_y[win->sprite_num] - win->sprite_end_y[win->sprite_num]));
	half_height = win->scr_height * 15 / win->sprite_distance[win->sprite_num]; // 해상도가 달라지면 start 값이 음수가 되는 경우도 ㄴ있음

	start = win->scr_height / 2 - half_height;
	end = win->scr_height / 2 + half_height;
	if (end > win->scr_height)
		end = win->scr_height - 1;		// start, end 안막아주면 팅김
	start_end = end - start;
	i = start;
	while (i < start_end && i >= 0 && i < win->scr_height)
	{
//		if (win->sprite_data[((int)(i / start_end * 64) * 64 + (int)((double)(win->sprite_start_i[win->sprite_num] / (win->sprite_end_i[win->sprite_num] - win->sprite_start_i[win->sprite_num] + 0.1) * 64.0)))])
//		{
		color = 0x777777;		//
//			color = win->sprite_data[((int)(i / start_end * 64) * 64 + (int)((double)(win->sprite_start_i[win->sprite_num] / (win->sprite_end_i[win->sprite_num] - win->sprite_start_i[win->sprite_num] + 0.1) * 64.0)))];
			if (check_pixel(win, win->i, (start + i), 0xffff00) == 0 && check_pixel(win, win->i, (start + i), 0x0000ff) == 0 && check_pixel(win, win->i, (i), 0xff0000) == 0)
			{
				draw_pixel(win, win->i, (start + i), color);
		//		printf("%f\n", i);
			}

//		}
		i++;
	}
	return (0);
}
