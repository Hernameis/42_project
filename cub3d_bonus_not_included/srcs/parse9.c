/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:38:16 by sunmin            #+#    #+#             */
/*   Updated: 2021/04/03 09:01:13 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_end_error(t_win *win)
{
	if (!win->r_check || !win->no_check || !win->so_check || !win->we_check
			|| !win->ea_check || !win->s_check || !win->f_check
			|| !win->c_check)
	{
		printf("error\nmap must be at the end\n");
		exit(0);
	}
}

int		set_parse(t_win *win, char *line)
{
	if (line[0] == 'R' || line[0] == 'N' || line[0] == 'W'
			|| line[0] == 'E' || line[0] == 'S')
		get_word(line, win);
	else if (line[0] == 'F' || line[0] == 'C')
		get_floor_ceiling_color(line, win);
	else
	{
		if (get_map(line, win) == 0)
			return (0);
	}
	return (1);
}

void	floor_ceiling_check(t_win *win, char **split, char **split2, int num)
{
	if (num != 3 || split[0][1] != '\0' || win->c_check == 1)
	{
		printf("error\nceiling\n");
		exit(0);
	}
	check_contain_number(split2[0]);
	check_contain_number(split2[1]);
	check_contain_number(split2[2]);
	win->ceiling_color = ft_atoi(split2[0]) * 256 * 267
		+ ft_atoi(split2[1]) * 256 + ft_atoi(split2[2]);
	win->c_check = 1;
}
