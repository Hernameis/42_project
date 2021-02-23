/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:18:10 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/23 12:03:28 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int key, t_win *win)
{
	if (key == key_esc)
		exit (0);
	else
	{
		if (key == key_w)
			win->press_w = 1;
		else if (key == key_s)
			win->press_s = 1;
		else if (key == key_a)
			win->press_a = 1;
		else if (key == key_d)
			win->press_d = 1;
		else if (key == key_q)
			win->press_q = 1;
		else if (key == key_e)
			win->press_e = 1;
		else if (key == key_m)
		{
			if (win->press_m == 1)
				win->press_m = 0;
			else
				win->press_m = 1;
		}
	}
	return (0);
}

int		key_release(int key, t_win *win)
{
	if (key == key_w || key == key_s)
	{
		if (key == key_w)
			win->press_w = 0;
		else if (key == key_s)
			win->press_s = 0;
	}
	else if (key == key_a)
		win->press_a = 0;
	else if (key == key_d)
		win->press_d = 0;
	else if (key == key_q)
		win->press_q = 0;
	else if (key == key_e)
		win->press_e = 0;
	return (0);
}

int		if_key_ad(t_win *win)
{
	if (win->press_d && !win->press_a)
	{
		win->key_ad = 1;
		return (1);
	}
	else if (win->press_a && !win->press_d)
	{
		win->key_ad = -1;
		return (-1);
	}
	win->key_ad = 0;
	return (0);
}

int		if_key_ws(t_win *win)
{
	if (win->press_w && !win->press_s)
	{
		win->key_ws = 1;
		return (1);
	}
	else if (win->press_s && !win->press_w)
	{
		win->key_ws = -1;
		return (-1);
	}
	win->key_ws = 0;
	return (0);
}

int		if_key_pressed(t_win *win)
{
	if (win->press_w)
	{
		if (if_pass_wall(win, key_w) != 1)
		{
			win->player_x += cos(win->player_dir) * win->player_move_speed;
			win->player_y += sin(win->player_dir) * win->player_move_speed;
		}
	}
	else if (win->press_s)
	{
		if (if_pass_wall(win, key_s) != 1)
		{
			win->player_x -= cos(win->player_dir);
			win->player_y -= sin(win->player_dir);
		}
	}
	if (win->press_q)
	{
		win->temp = win->player_dir;
		win->player_dir -= M_PI / 2;
		if (if_pass_wall(win, key_q) != 1)
		{
			win->player_x += cos(win->player_dir);
			win->player_y += sin(win->player_dir);
		}
		win->player_dir = win->temp;
	}
	else if (win->press_e)
	{
		win->temp = win->player_dir;
		win->player_dir += M_PI / 2;
		if (if_pass_wall(win, key_e) != 1)
		{
			win->player_x += cos(win->player_dir);
			win->player_y += sin(win->player_dir);
		}
		win->player_dir = win->temp;
	}
	if (win->press_d)
	{
		win->player_dir += 0.05;
	}
	if (win->press_a)
	{
		win->player_dir -= 0.05;
	}
	put_laser(win);
	put_grid(win);
	put_player(win);

	return (0);
}
