/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 08:14:43 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/21 09:54:08 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_map(t_win *win, double x, double y)
{

	int		i;
	double	map_width;
	double	map_height;


	win->map_width = 10;
	win->map_height = 10;


	int	map[10][10] = 
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 1, 1, 1, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
		{1, 0, 1, 0, 1, 0, 0, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
//	printf("123\n %.2f %.2f %.2f %.2f\n", win->scr_width, win->scr_height, map_width, map_height);
//	printf("%d, %d\n", (int)(y / (win->scr_height / map_height)), (int)(x / (win->scr_width / map_width)));
//	printf("\n");
//	printf("%d\n", map[(int)(y / (win->scr_height / map_height))][(int)(x / (win->scr_width / map_width))]);
	return (map[(int)(y / (win->scr_height /win->map_height))][(int)(x / (win->scr_width / win->map_width))]);

}
