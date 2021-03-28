/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:18:10 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/28 11:59:04 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		key_press(int key, t_win *win)
{
	if (key == KEY_ESC)
		exit(0);
	else
	{
		if (key == KEY_W)
			win->press_w = 1;
		else if (key == KEY_S)
			win->press_s = 1;
		else if (key == KEY_A)
			win->press_a = 1;
		else if (key == KEY_D)
			win->press_d = 1;
		else if (key == KEY_Q)
			win->press_q = 1;
		else if (key == KEY_E)
			win->press_e = 1;
		else if (key == KEY_M)
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
	if (key == KEY_W || key == KEY_S)
	{
		if (key == KEY_W)
			win->press_w = 0;
		else if (key == KEY_S)
			win->press_s = 0;
	}
	else if (key == KEY_A)
		win->press_a = 0;
	else if (key == KEY_D)
		win->press_d = 0;
	else if (key == KEY_Q)
		win->press_q = 0;
	else if (key == KEY_E)
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
	key_pressed_ws(win);
	key_pressed_qe(win);
	key_pressed_ad(win);
	put_laser(win);
	return (0);
}
