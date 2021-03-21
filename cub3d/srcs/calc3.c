/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 09:00:42 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/21 10:02:00 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double		res_double(double a, double b)
{
	while (b >= a)
	{
		b -= a;
	}
	return (b);
}
