/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:33:15 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/28 12:02:27 by sunmin           ###   ########.fr       */
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

	len = ft_strlen(line);
	i = -1;
	while (++i < len)
	{
		if (line[i] == ',')
			win->c_check++;
	}
	if (win->c_check > 2)
	{
		win->c_check = 0;
		printf("error\nceiling floor\n");
		exit(0);
	}
	win->c_check = 0;
}
