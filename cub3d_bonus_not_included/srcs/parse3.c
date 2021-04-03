/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:08:14 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/28 12:02:22 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			free_split(char **split)
{
	int			i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	if (split)
		free(split);
}

int				check_player(t_win *win)
{
	int			i;
	int			j;
	int			dir;

	win->check = 0;
	i = -1;
	while (++i < win->map_height)
	{
		j = -1;
		while (++j < win->map_width)
		{
			if (win->map[i][j] == 'N' || win->map[i][j] == 'S'
					|| win->map[i][j] == 'W' || win->map[i][j] == 'E')
			{
				win->check_height = i;
				win->check_width = j;
				dir = win->map[i][j];
				win->check++;
			}
		}
	}
	check_player2(win, dir);
	return (0);
}

void			check_player2(t_win *win, int dir)
{
	if (win->check != 1)
	{
		printf("error\nplayer location\n");
		exit(0);
	}
	else
	{
		win->player_x = win->check_width;
		win->player_y = win->check_height;
		win->player_dir = dir;
		if (dir == 'N')
			win->player_dir = 270;
		else if (dir == 'S')
			win->player_dir = 90;
		else if (dir == 'W')
			win->player_dir = 180;
		else
			win->player_dir = 0;
	}
}

void			init_map(t_win *win)
{
	int			i;
	int			j;

	win->map = (char **)malloc(sizeof(char *) * (win->map_height + 1));
	i = 0;
	while (i < win->map_height)
	{
		win->map[i] = (char *)malloc(sizeof(char) * (win->map_width + 1));
		win->map[i][win->map_width] = '\0';
		i++;
	}
	win->map[win->map_height] = NULL;
	i = -1;
	while (++i < win->map_height)
	{
		j = -1;
		while (++j < win->map_width)
		{
			win->map[i][j] = ' ';
		}
	}
}

int				check_blank(char *line)
{
	int			len;
	int			i;

	len = ft_strlen(line);
	i = 0;
	while (i < len)
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == '2'
				|| line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
				|| line[i] == 'E')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
