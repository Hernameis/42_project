/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:33:15 by sunmin            #+#    #+#             */
/*   Updated: 2021/04/01 14:15:07 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_map_effect(t_win *win)
{
	check_player(win);
	check_map_wall(win);
	return (0);
}

void	check_comma(t_win *win, char *line)
{
	int		len;
	int		i;

	win->com_check = 0;
	len = ft_strlen(line);
	i = -1;
	while (++i < len)
	{
		if (line[i] == ',')
			win->com_check++;
	}
	if (win->com_check > 2)
	{
		printf("error\nceiling floor\n");
		exit(0);
	}
}

void	check_all_flags(t_win *win)
{
	if (!win->r_check || !win->no_check || !win->so_check || !win->we_check
			|| !win->ea_check || !win->s_check || !win->f_check
			|| !win->c_check || !win->map_check)
	{
		win->all_flags = 0;
		printf("error\nnot all arguments\n");
		exit(0);
	}
	win->all_flags = 1;
}
