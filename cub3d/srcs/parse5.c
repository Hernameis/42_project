/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 12:07:55 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/22 12:38:48 by sunmin           ###   ########.fr       */
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
