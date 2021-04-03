/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:58:57 by sunmin            #+#    #+#             */
/*   Updated: 2021/04/03 09:05:49 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		parse_gnl(t_win *win, int fd)
{
	int		a;
	char	*line;

	while ((a = get_next_line(fd, &line)) > 0)
	{
		if (if_unknown_key(line[0]) == 1)
		{
			printf("error\nunknown key\n");
			exit(0);
		}
		if (win->all_flags == 0)
		{
			set_parse(win, line);
			free(line);
		}
		else
		{
			printf("error\ntoo many arguments\n");
			exit(0);
		}
	}
	free(line);
}

void		invalid_map1(t_win *win, int i, int j, int check)
{
	int		k;

	k = i;
	while (k < win->map_height)
	{
		if (win->map[k][j] == '1')
		{
			check = 1;
			break ;
		}
		k++;
	}
	if (check == 0)
	{
		printf("error\ninvalid map1\n");
		exit(0);
	}
}

void		invalid_map2(t_win *win, int i, int j, int check)
{
	int		k;

	k = i;
	while (k >= 0)
	{
		if (win->map[k][j] == '1')
		{
			check = 1;
			break ;
		}
		k--;
	}
	if (check == 0)
	{
		printf("error\ninvalid map2\n");
		exit(0);
	}
}

void		invalid_map3(t_win *win, int i, int j, int check)
{
	int		k;

	k = j;
	while (k < win->map_width)
	{
		if (win->map[i][k] == '1')
		{
			check = 1;
			break ;
		}
		k++;
	}
	if (check == 0)
	{
		printf("error\ninvalid map3\n");
		exit(0);
	}
}

void		invalid_map4(t_win *win, int i, int j, int check)
{
	int		k;

	k = j;
	while (k >= 0)
	{
		if (win->map[i][k] == '1')
		{
			check = 1;
			break ;
		}
		k--;
	}
	if (check == 0)
	{
		printf("error\ninvalid map4\n");
		exit(0);
	}
}
