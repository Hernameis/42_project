/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 20:08:34 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/24 20:52:50 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d_bonus(t_win *win)
{
	player_life(win);
}

void	player_life(t_win *win)
{
//	return ;
	int		i;
	int		j;
	int		color;

	if (check_map(win, win->player_x, win->player_y) == 2)
	{
		if (win->player_life > 0)
			win->player_life -= 0.1;
//		printf("%f\n", win->player_life);
	}
	i = (int)(win->scr_height / 50);
	while (i <	(int)(win->scr_height / 20))
	{
		j = (int)(win->scr_width / 5);
		while (j < (int)(win->scr_width / 2))
		{
			if (j <win->scr_width / 2.0 * win->player_life / 100)
			   color = 0xff0000;
			else
				color = 0x888888;
			draw_pixel(win, j, i, color);
			j++;
		}
		i++;
	}
}

int		player_life_check(t_win *win, int w_idx, int h_idx)
{
	if (h_idx >= (int)(win->scr_height / 50) && h_idx <= (int)(win->scr_height / 20) && w_idx >= (int)(win->scr_width / 5) && w_idx <= (int)(win->scr_width / 2))
		return (1);
	return (0);
}
