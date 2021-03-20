/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:04:37 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/20 21:38:47 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_cubfile(t_win *win, char **argv)
{
	int		fd;
	int		a;
	int		len;
	char	*line;
	char	c;
	int		i;
	int		check;

	check = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("map file error\n");
		return ;
	}
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
	check_resolution(win);
	init_map(win);
	make_map(win);
	check_map_effect(win);
	free(win->parse_map);
	close(fd);
}

void	check_resolution(t_win *win)
{
	if (win->scr_width < 200 || win->scr_height < 200
			|| win->scr_height > 1500 || win->scr_width > 1500)
	{
		printf("Resolution invalid (200 ~ 1500)\n");
		exit(0);
	}
}

void	get_word(char *line, t_win *win)
{
	char	**split;
	int		num;

	split = ft_split(line, ' ');
	num = get_word_num(split, win);
	if (split[0][0] == 'R')
	{
		if (num != 3 || split[0][1] != '\0')
		{
			printf("resolution error\n");
			exit(0);
		}
		win->scr_width = (double)ft_atoi(split[1]);
		win->scr_height = (double)ft_atoi(split[2]);
	}
	else if (split[0][0] == 'N' && split[0][1] == 'O')
	{
		if (num != 2 || split[0][2] != '\0')
		{
			printf("northwall error\n");
			exit(0);
		}
		win->wall_n_addr = ft_strdup(split[1]);
	}
	else if (split[0][0] == 'S')
	{
		if (split[0][1] == 'O')
		{
			if (num != 2 || split[0][2] != '\0')
			{
				printf("southwall error\n");
				exit(0);
			}
			win->wall_s_addr = ft_strdup(split[1]);
		}
		else
		{
			if (num != 2 || split[0][1] != '\0')
			{
				printf("sprite error\n");
				exit(0);
			}
			win->sprite_addr = ft_strdup(split[1]);
		}
	}
	else if (split[0][0] == 'W' && split[0][1] == 'E')
	{
		if (num != 2 || split[0][2] != '\0')
		{
			printf("westwall error\n");
			exit(0);
		}
		win->wall_w_addr = ft_strdup(split[1]);
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		if (num != 2)
		{
			printf("eastwall error\n");
			exit(0);
		}
		win->wall_e_addr = ft_strdup(split[1]);
	}
	else
	{
		;
	}
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
	int		l;
	int		check;

	check = 0;
	i = 0;
	while (i < win->map_height)
	{
		j = 0;
		while (j < win->map_width)
		{
			if (win->map[i][j] == '0' || win->map[i][j] == '2'
					|| win->map[i][j] == 'N' || win->map[i][j] == 'S'
					|| win->map[i][j] == 'W' || win->map[i][j] == 'E')
			{
				k = i;
				check = 0;
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
					printf("invalid map1 %d %d %d\n", i, j, k);
					exit(0);
				}
				k = i;
				check = 0;
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
					printf("invalid map2 %d %d\n", i, j);
					exit(0);
				}
				k = j;
				check = 0;
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
					printf("invalid map3\n");
					exit(0);
				}
				k = j;
				check = 0;
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
					printf("invalid map4\n");
					exit(0);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}
