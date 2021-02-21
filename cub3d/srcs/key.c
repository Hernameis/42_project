/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 13:18:10 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/21 09:36:44 by sunmin           ###   ########.fr       */
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
		win->player_x += cos(win->player_dir);
		win->player_y += sin(win->player_dir);
	}
	else if (win->press_s)
	{
		win->player_x -= cos(win->player_dir);
		win->player_y -= sin(win->player_dir);
	}
	if (win->press_d)
	{
		win->player_dir += 0.05;
	}
	if (win->press_a)
	{
		win->player_dir -= 0.05;
	}
	cjswkd(win);
	put_grid(win);
	put_player(win);
	put_laser(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img_ptr, 0, 0);
	return (0);
}
