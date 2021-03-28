/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:24:04 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/28 12:03:04 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		parse_r(t_win *win, char **split, int num)
{
	if (num != 3 || split[0][1] != '\0' || win->r_check == 1)
	{
		printf("error\nresolution\n");
		exit(0);
	}
	win->scr_width = (double)ft_atoi(split[1]);
	win->scr_height = (double)ft_atoi(split[2]);
	win->r_check = 1;
}

void		parse_no(t_win *win, char **split, int num)
{
	if (num != 2 || split[0][2] != '\0' || win->no_check == 1)
	{
		printf("error\nnorthwall\n");
		exit(0);
	}
	win->wall_n_addr = ft_strdup(split[1]);
	win->no_check = 1;
}

void		parse_s(t_win *win, char **split, int num)
{
	if (split[0][1] == 'O')
	{
		if (num != 2 || split[0][2] != '\0' || win->so_check == 1)
		{
			printf("error\nsouthwall\n");
			exit(0);
		}
		win->wall_s_addr = ft_strdup(split[1]);
		win->so_check = 1;
	}
	else
	{
		if (num != 2 || split[0][1] != '\0' || win->s_check == 1)
		{
			printf("error\nsprite\n");
			exit(0);
		}
		win->sprite_addr = ft_strdup(split[1]);
		win->s_check = 1;
	}
}

void		parse_we(t_win *win, char **split, int num)
{
	if (num != 2 || split[0][2] != '\0' || win->we_check == 1)
	{
		printf("error\nwestwall\n");
		exit(0);
	}
	win->wall_w_addr = ft_strdup(split[1]);
	win->we_check = 1;
}

void		parse_ea(t_win *win, char **split, int num)
{
	if (num != 2 || split[0][2] != '\0' || win->ea_check == 1)
	{
		printf("error\neastwall\n");
		exit(0);
	}
	win->wall_e_addr = ft_strdup(split[1]);
	win->ea_check = 1;
}
