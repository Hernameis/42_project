/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:38:16 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/25 07:51:56 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		set_invalid_map(t_win *win, int i, int j)
{
	int		check;

	check = 0;
	invalid_map1(win, i, j, check);
	invalid_map2(win, i, j, check);
	invalid_map3(win, i, j, check);
	invalid_map4(win, i, j, check);
	invalid_map5(win, i, j, check);
	invalid_map6(win, i, j, check);
	invalid_map7(win, i, j, check);
	invalid_map8(win, i, j, check);
}

void		invalid_map5(t_win *win, int i, int j, int check)
{
	int		k;
	int		l;

	k = i;
	l = j;
	while (k < win->map_height && l < win->map_width)
	{
		if (win->map[k][l] == '1')
		{
			check = 1;
			break ;
		}
		k++;
		l++;
	}
	if (check == 0)
	{
		printf("error\ninvalid map5\n");
		exit(0);
	}
}

void		invalid_map6(t_win *win, int i, int j, int check)
{
	int		k;
	int		l;

	k = i;
	l = j;
	while (k < win->map_height && l >= 0)
	{
		if (win->map[k][l] == '1')
		{
			check = 1;
			break ;
		}
		k++;
		l--;
	}
	if (check == 0)
	{
		printf("error\ninvalid map6\n");
		exit(0);
	}
}

void		invalid_map7(t_win *win, int i, int j, int check)
{
	int		k;
	int		l;

	k = i;
	l = j;
	while (k >= 0 && l < win->map_width)
	{
		if (win->map[k][l] == '1')
		{
			check = 1;
			break ;
		}
		k--;
		l++;
	}
	if (check == 0)
	{
		printf("error\ninvalid map7\n");
		exit(0);
	}
}

void		invalid_map8(t_win *win, int i, int j, int check)
{
	int		k;
	int		l;

	k = i;
	l = j;
	while (k >= 0 && l >= 0)
	{
		if (win->map[k][l] == '1')
		{
			check = 1;
			break ;
		}
		k--;
		l--;
	}
	if (check == 0)
	{
		printf("error\ninvalid map8\n");
		exit(0);
	}
}
