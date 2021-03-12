/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:04:37 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/12 18:12:33 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_cubfile(t_win *win, char **argv)
{
	int		fd;
	int		a;
	int		i;
	char	*line;
	char	**split;
	char	c;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("map file error\n");
		return ;
	}
	i = 0;
	printf("aa\n");
	while ((a = get_next_line(fd, &line)) > 0)		// 스프라이트 까지
	{
		if (line[0] == 'R' || line[0] == 'N' || line[0] == 'W' || line[0] == 'E' || line[0] == 'S')
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
				break;
		}
		i++;
	}
	init_map(win);
	make_map(win);
	check_map_effect(win);
	printf("a\n");
	close(fd);
}

int		check_cubfile(const char *str)
{
	size_t		len;

	len = ft_strlen(str);
	if (str[len - 4] == '.' && str[len - 3] == 'c' && str[len - 2] == 'u' && str[len - 1] == 'b')
		return (1);
	return (0);
}

void	get_word(char *line, t_win *win)
{
	char	**split;

	split = ft_split(line, ' ');
	if (line[0] == 'R')
	{
		win->scr_width = (double)ft_atoi(split[1]);
		win->scr_height = (double)ft_atoi(split[2]);
	}
	else if (line[0] == 'N' && line[1] == 'O')
	{
		win->wall_n_addr = split[1];
	}
	else if (line[0] == 'S')
	{
		if (line[1] == 'O')
		{
			win->wall_s_addr= split[1];
		}
		else
			win->sprite_addr = split[1];
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		win->wall_w_addr = split[1];
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		win->wall_e_addr = split[1];
	}
	else
	{
		;
//		printf("blank\n");
	}
}

void	get_floor_ceiling_color(char *line, t_win *win)
{
	char	**split;		// 스플릿 두 번 쓰기 (',', ' ')
	char	**split2;

	split = ft_split(line, ' ');
	if (line[0] == 'F')						//////////////////////////////////
	{
		split2 = ft_split(split[1], ',');
		win->floor_color = ft_atoi(split2[0]) * 256 * 256 + ft_atoi(split2[1]) * 256 + ft_atoi(split2[2]);
	}
	else if (line[0] == 'C')
	{
		split2 = ft_split(split[1], ',');
		win->ceiling_color = ft_atoi(split2[0]) * 256 * 256 + ft_atoi(split2[1]) * 256 + ft_atoi(split2[2]);
	}
	else
		;
}

int		get_map(char *line, t_win *win)
{
	int		i;
	int		len;
	char	*index;

	index = ft_strdup("a");
	len = ft_strlen(line);
	if (len > win->map_width)
		win->map_width = len;
	if (check_blank(line, win))
	{
		if (win->check_map == 1)
		{
			printf("cub map error\n");
			return (0);
		}
		else
			return (1);
	}
	else
	{
		win->map_height++;
		win->check_map = 1;
		win->parse_map = ft_strjoin((const char *)win->parse_map, (const char *)line);
		win->parse_map = ft_strjoin((const char *)win->parse_map, (const char *)index);
		printf("parse map\n%s\n", win->parse_map);
		return (1);
	}
	return (0);
}

int		check_blank(char *line, t_win *win)		// 리턴 1이면 맵의 값이 없다는 뜻
{
	int		len;
	int		i;

	len = ft_strlen(line);
	i = 0;
	while (i < len)
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == '2' || line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	init_map(t_win *win)
{
	int		i;
	int		j;

	win->map = (char **)malloc(sizeof(char *) * (win->map_height + 1));
	i = 0;
	while (i < win->map_height)
	{
		win->map[i] = (char *)malloc(sizeof(char) * (win->map_width + 1));
		win->map[i][win->map_width] = '\0';
		i++;
	}
	win->map[win->map_height] = NULL;
	i = 0;
	while (i < win->map_height)
	{
		j = 0;
		while (j < win->map_width)
		{
			win->map[i][j] = ' ';
			j++;
		}
		i++;
	}
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
}

int		check_map_effect(t_win *win)
{
	check_player(win);
	// 벽체크와 플레이어 위치 방향 체크까지 같이
	return (0);
}

int		check_player(t_win *win)
{
	int		i;
	int		j;
	int		check;
	int		height;
	int		width;
	int		dir;

	check = 0;
	i = 0;
	while (i < win->map_height)
	{
		j = 0;
		while (j < win->map_width)
		{
			if (win->map[i][j] == 'N' || win->map[i][j] == 'S' || win->map[i][j] == 'W' || win->map[i][j] == 'E')
			{
				height = i;
				width = j;
				dir = win->map[i][j];
				check++;
			}
			j++;
		}
		i++;
	}
	if (check != 1)
	{
		printf("player location error\n");
		exit(0);
	}
	else
	{
		win->player_x = width;
		win->player_y = height;
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
	printf("%f %f %f\n", win->player_x, win->player_y, win->player_dir);
	return (0);
}
