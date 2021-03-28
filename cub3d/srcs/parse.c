/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:04:37 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/28 12:01:52 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_cubfile(t_win *win, char **argv)
{
	int		fd;
	int		check;

	check = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("error\nmap file\n");
		return ;
	}
	parse_gnl(win, fd);
	check_resolution(win);
	init_map(win);
	make_map(win);
	check_map_effect(win);
	free(win->parse_map);
	close(fd);
}

void	check_resolution(t_win *win)
{
	mlx_get_screen_size(win->mlx, &win->size_x, &win->size_y);
	if (win->scr_width < 1 || win->scr_height < 1)
	{
		printf("error\nResolution\n");
		exit(0);
	}
	if (win->scr_width < 300)
		win->scr_width = 300;
	if (win->scr_height < 300)
		win->scr_height = 300;
	if (win->scr_width > win->size_x)
		win->scr_width = win->size_x;
	if (win->scr_height > win->size_y)
		win->scr_height = win->size_y;
}

void	get_word(char *line, t_win *win)
{
	char	**split;
	int		num;

	split = ft_split(line, ' ');
	num = get_word_num(split);
	if (split[0][0] == 'R')
		parse_r(win, split, num);
	else if (split[0][0] == 'N' && split[0][1] == 'O')
		parse_no(win, split, num);
	else if (split[0][0] == 'S')
		parse_s(win, split, num);
	else if (split[0][0] == 'W' && split[0][1] == 'E')
		parse_we(win, split, num);
	else if (split[0][0] == 'E' && split[0][1] == 'A')
		parse_ea(win, split, num);
	else
		;
	free_split(split);
}

void	make_map(t_win *win)
{
	char	**split;
	int		i;
	int		j;

	split = ft_split(win->parse_map, 'a');
	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j])
		{
			win->map[i][j] = split[i][j];
			j++;
		}
		i++;
	}
	free_split(split);
}

int		check_map_wall(t_win *win)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = -1;
	while (++i < win->map_height)
	{
		j = -1;
		while (++j < win->map_width)
		{
			if (win->map[i][j] == '0' || win->map[i][j] == '2'
					|| win->map[i][j] == 'N' || win->map[i][j] == 'S'
					|| win->map[i][j] == 'W' || win->map[i][j] == 'E')
			{
				set_invalid_map(win, i, j);
			}
		}
	}
	return (0);
}
