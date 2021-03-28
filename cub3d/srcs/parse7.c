/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 13:58:57 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/28 12:03:28 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		parse_gnl(t_win *win, int fd)
{
	int		a;
	char	*line;

	while ((a = get_next_line(fd, &line)) > 0)
	{
		if (line[0] == 'R' || line[0] == 'N' || line[0] == 'W'
				|| line[0] == 'E' || line[0] == 'S')
		{
			get_word(line, win);
		}
		else if (line[0] == 'F' || line[0] == 'C')
		{
			get_floor_ceiling_color(line, win);
		}
		else
		{
			if (get_map(line, win) == 0)
			{
				break ;
			}
		}
		free(line);
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
