/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:07:55 by sunmin            #+#    #+#             */
/*   Updated: 2021/04/02 12:03:14 by sunmin           ###   ########.fr       */
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
			|| key == 'F' || key == 'C' || key == ' ' || key == '	'
			|| key == '1' || key == '\n' || key == '\0')
		return (0);
	return (1);
}

void	check_cf_color(char **split)
{
	if (ft_atoi((const char *)split[0]) > 255
			|| ft_atoi((const char *)split[1]) > 255
			|| ft_atoi((const char *)split[2]) > 255)
	{
		printf("error\ncf_color\n");
		exit(0);
	}
	if (split[0][3] != '\0' || split[1][3] != '\0' || split[2][3] != '\0')
	{
		printf("error\ncf_color\n");
		exit(0);
	}
}
