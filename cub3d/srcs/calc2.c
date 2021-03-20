/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 09:53:18 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/20 10:00:44 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		equation_intercept_y(double a, double p, double q)
{
	return (q - a * p);
}

double		meet_between_segments_x(double a, double b, double c, double d)
{
	return ((d - b) / (a - c));
}

double		meet_between_segments_y(double a, double b, double c, double d)
{
	return ((b * c - a * d) / (c - a));
}

int			mini_x(t_win *win, int x)
{
	return (x / win->minimap_size + (int)(win->scr_width
				* (win->minimap_size - 1) / win->minimap_size));
}

int			mini_y(t_win *win, int y)
{
	return (y / win->minimap_size);
}
