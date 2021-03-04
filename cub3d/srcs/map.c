/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 08:14:43 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/04 15:27:45 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_map(t_win *win, double x, double y)
{

	int		i;
	double	map_width;
	double	map_height;


	


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

