/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:41:20 by sunmin            #+#    #+#             */
/*   Updated: 2021/02/21 20:02:19 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		wall_color(int k, int height, t_win *win)
{

//	printf("%d\n", (int)(64.0 / 200 * (int)win->laser_x) % 200 + (int)(64.0 / height * k * win->wall_w_width));
//	printf("### %d ###\n", k);
//	printf("@@ %d %f\n", win->i, win->laser_x);
	return (win->wall_w_data[(int)(64.0 / 200 * (int)win->laser_y) % 200 + (int)(64.0 / height * k * win->wall_w_width)]);
}
