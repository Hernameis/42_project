/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 12:01:04 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/21 16:11:17 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	distance(t_win *win, double a, double b)
{
	double	aa;
	double	bb;
	double	aabb;
	double	c;

	aa = a * a;
	bb = b * b;
	aabb = aa + bb;
//	printf("%f @@  %f @@ %f\n", aa, bb, aabb);
	c = sqrt(a * a + b * b);
	return (c);
}

double	degree_from_xy(double x1, double x2, double y1, double y2)
{
	return (atan2(y2 - y1, x2 - x1));
}
