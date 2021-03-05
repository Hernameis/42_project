/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 08:14:43 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/05 17:26:48 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_map(t_win *win, double x, double y)
{
	int	map[10][10] = 
	{
		{3, 1, 1, 1, 1, 1, 1, 1, 1, 3},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 2, 0, 0, 1},
		{1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 2, 2, 2, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
		{1, 0, 1, 1, 0, 0, 0, 0, 0, 1},
		{3, 1, 1, 1, 1, 1, 1, 1, 1, 3}
	};

//	return (map[(int)((y / (double)win->cub_size))][(int)((x / (double)win->cub_size))]);
//	printf("%d %d\n", (int)(y / win->scr_height * win->map_height), (int)(x / win->scr_width * win->map_width));
	return (map[(int)(y / win->scr_height * win->map_height)][(int)(x / win->scr_width * win->map_width)]);
//	return (map[(int)(y / win->scr_height)][(int)(x / win->scr_width)]);
}

