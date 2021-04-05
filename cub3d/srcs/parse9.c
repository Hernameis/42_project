/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:38:16 by sunmin            #+#    #+#             */
/*   Updated: 2021/04/05 10:07:22 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_end_error(t_win *win)
{
	if (!win->r_check || !win->no_check || !win->so_check || !win->we_check
			|| !win->ea_check || !win->s_check || !win->f_check
			|| !win->c_check)
	{
		printf("error\n");
		exit(0);
	}
}

int		set_parse(t_win *win, char *line)
{
	int		len;
	int		i;

	len = ft_strlen(line);
	i = 0;
	while (line[i] == ' ' || (line[i] >= 8 && line[i] <= 13))
		i++;
	if (line[i] == 'R' || (line[i] == 'N' && line[i + 1] == 'O') || (line[i] == 'W' && line[i + 1] == 'E')
			|| (line[i] == 'E' && line[i + 1] == 'A') || (line[i] == 'S' && (line[i + 1] == ' ' || line[i + 1] == 'O')))
		get_word(line, win);
	else if (line[i] == 'F' || line[i] == 'C')
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
