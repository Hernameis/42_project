/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:38:16 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/22 14:41:54 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_invalid_map(t_win *win, int k, int i, int j)
{
	int		check;

	k = i;
	check = 0;
	invalid_map1(win, k, j, check);
	k = i;
	check = 0;
	invalid_map2(win, k, j, check);
	k = j;
	check = 0;
	invalid_map3(win, k, i, check);
	k = j;
	check = 0;
	invalid_map4(win, k, i, check);
}
