/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:07:55 by sunmin            #+#    #+#             */
/*   Updated: 2021/04/01 14:36:49 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	swap_map(t_win *win, char *line)
{
	win->map_height++;
	win->check_map = 1;
	win->temp_map = ft_strdup(win->parse_map);
	free(win->parse_map);
	win->parse_map = ft_strjoin((const char *)win->temp_map,
			(const char *)line);
	free(win->temp_map);
	win->temp_map = ft_strdup(win->parse_map);
	free(win->parse_map);
	win->parse_map = ft_strjoin((const char *)win->temp_map,
			(const char *)win->index);
	free(win->temp_map);
	free(win->index);
}

void	check_contain_number(char *str)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	i = -1;
	while (++i < len)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			printf("error\nnot number\n");
			exit(0);
		}
	}
}

int		if_unknown_key(char key)
{
	if (key == 'R' || key == 'N' || key == 'S' || key == 'W' || key == 'E'
			|| key == 'F' || key == ' ' || key == '	' || key == '1')
		return (0);
	return (1);
}
