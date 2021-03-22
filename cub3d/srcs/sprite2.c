/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 10:54:05 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/22 14:55:11 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			draw_sprite(t_win *win)
{
	int			num;

	printf("1\n");
	put_sprite(win);
	printf("2\n");
	num = win->sprite_num;
	printf("3\n");
	while (num >= 0)
	{
	printf("4\n");
		if (check_sprite(win, num))
		{
	printf("5\n");
			sprite_pixel(win, num);
		}
		num--;
	}
	printf("6\n");
}

int				check_sprite(t_win *win, int num)
{
	printf("a\n");
	within_degree(win);
	printf("b\n");
	printf("pd %f sd %f n %d cx %f cy %f\n", win->player_dir, win->sprite[num].degree, num, win->sprite[num].center_x, win->sprite[num].center_y);
	if (within_degree_double(win->player_dir - win->sprite[num].degree)
			>= (-1 * (win->pov / 2 + 15.0)
			* M_PI / 180) && within_degree_double(win->player_dir
				- win->sprite[num].degree) <= ((win->pov / 2 + 15.0)
					* M_PI / 180))
	{
	printf("c\n");
		return (1);
	}
	printf("d\n");
	return (0);
}

void			put_sprite(t_win *win)
{
	int			num;

	num = 0;
	while (num < win->sprite_num)
	{
		win->sprite[num].distance = distance(win->player_x
				- win->sprite[num].center_x, win->player_y
				- win->sprite[num].center_y);
		win->sprite[num].degree = degree_from_xy(win->player_x,
				win->sprite[num].center_x, win->player_y,
				win->sprite[num].center_y);
		num++;
	}
	compare_sprite(win, win->sprite_num);
}
