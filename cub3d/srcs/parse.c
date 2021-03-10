/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:04:37 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/10 17:14:08 by sunmin           ###   ########.fr       */
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
			get_map(line, win);
		}
		i++;
	}
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

void	get_map(char *line, t_win *win)
{
	int		check;
	int		i;
	int		j;
	int		len;
	int		**prev_map;
	int		prev_map_width;
	int		prev_map_height;
	int		**new_map;
	int		new_map_width;
	int		new_map_height;

	printf("line %s\n", line);
	len = ft_strlen(line);
	if (len == 0)
	{
		return ;
	}
	if (win->map_check == 1)
	{
		prev_map = win->parse_map2;
		prev_map_width = win->parse_map_width2;
		prev_map_height = win->parse_map_height2;

		new_map = win->parse_map1;
		new_map_width = win->parse_map_width1;
		new_map_height = win->parse_map_height1;
	}
	else //if (win->map_check == 2)
	{
		prev_map = win->parse_map1;
		prev_map_width = win->parse_map_width1;
		prev_map_height = win->parse_map_height1;

		new_map = win->parse_map2;
		new_map_width = win->parse_map_width2;
		new_map_height = win->parse_map_height2;
	}
	i = 0;
	while (i < len)
	{
		if (line[i] == '1')
		{
			if (len > prev_map_width)
				new_map_width = len;
			new_map_height = prev_map_height + 1;
			if (win->map_check == 1)
			{
				win->parse_map_height1 = new_map_height;
			}
			else
				win->parse_map_height2 = new_map_height;
			check = 1;
			break;
		}
	}
	// malloc
	if (!(new_map = (int **)malloc(sizeof(int *) * new_map_height)))
	{
		printf("malloc error\n");
		return ;
	}
	i = 0;
	while (i < new_map_width)
	{
		if(!(new_map[i] = (int *)malloc(sizeof(int) * new_map_width)))
		{
			printf("malloc error2\n");
			return ;
		}
		i++;
	}
	//	1초기화
	i = 0;
	while (i < new_map_height)
	{
		j = 0;
		while (j < new_map_width)
		{
			new_map[i][j] = 1;
			j++;
		}
		i++;
	}
	// 맵 옮기기
	i = 0;
//	if (prev_map != NULL)
	{
		while (i < prev_map_height)
		{
			j = 0;
			while (j < prev_map_width)
			{
				new_map[i][j] = prev_map[i][j];
				j++;
			}
			i++;
		}
	}
	j = 0;
	while (j < new_map_width)
	{
		new_map[i][j] = line[j] - '0';
		j++;
	}

	///////////////////////////////////////////
	i = 0;									///
	while (i < prev_map_height)				///
	{										///
		j = 0;								///
		while (j < prev_map_width)			///
		{									///
			printf("%d", prev_map[i][j]);	///
			j++;							///
		}									///
		printf("\n");						///
		i++;								///
	}										///
	printf("\n");							///
	///////////////////////////////////////////
	
	win->map_height = new_map_height;
	win->map_width = new_map_width;

/*
	i = 0;
	if (prev_map != NULL)
	{
		while (i < prev_map_height && prev_map)
		{
			free(prev_map[i]);
			i++;
		}
		free(prev_map);
	}
*/

	if (win->map_check == 1)
	{
		win->map_check = 2;
	}
	else
		win->map_check = 1;
}