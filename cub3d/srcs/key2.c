/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 10:08:49 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/22 14:22:44 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		key_pressed_ws(t_win *win)
{
	if (win->press_w)
	{
		if (if_pass_wall(win, KEY_W) != '1' && if_pass_wall(win, KEY_W) != '2')
		{
			win->player_x += cos(win->player_dir) * win->player_move_speed;
			win->player_y += sin(win->player_dir) * win->player_move_speed;
		}
	}
	else if (win->press_s)
	{
		if (if_pass_wall(win, KEY_S) != '1' && if_pass_wall(win, KEY_S) != '2')
		{
			win->player_x -= cos(win->player_dir) * win->player_move_speed;
			win->player_y -= sin(win->player_dir) * win->player_move_speed;
		}
	}
}

void		key_pressed_qe(t_win *win)
{
	if (win->press_q)
	{
		win->temp = win->player_dir;
		win->player_dir -= M_PI / 2;
		if (if_pass_wall(win, KEY_Q) != '1')
		{
			win->player_x += cos(win->player_dir) * win->player_move_speed;
			win->player_y += sin(win->player_dir) * win->player_move_speed;
		}
		win->player_dir = win->temp;
	}
	else if (win->press_e)
	{
		win->temp = win->player_dir;
		win->player_dir -= M_PI / 2;
		if (if_pass_wall(win, KEY_E) != '1')
		{
			win->player_x -= cos(win->player_dir) * win->player_move_speed;
			win->player_y -= sin(win->player_dir) * win->player_move_speed;
		}
		win->player_dir = win->temp;
	}
}

void		key_pressed_ad(t_win *win)
{
	if (win->press_d)
	{
		win->player_dir += 0.08;
	}
	if (win->press_a)
	{
		win->player_dir -= 0.08;
	}
}

void		ceiling(t_win *win)
{
	int		i;
	int		j;
	int		color;

	i = 0;
	while (i < (int)win->scr_height)
	{
		if (i < win->scr_height / 2)
			color = 0x87ceeb;
		else
			color = 0x111111;
		j = 0;
		while (j < win->scr_width)
		{
			draw_pixel(win, j, i, color);
			j++;
		}
		i++;
	}
}
