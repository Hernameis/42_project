/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 08:14:43 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/26 11:32:26 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	check_map(t_win *win, double x, double y)
{
	return (win->map[(int)(y / win->cub_height)][(int)(x / win->cub_width)]);
}
