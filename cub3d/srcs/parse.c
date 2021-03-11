/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 12:04:37 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/11 19:27:28 by sunmin           ###   ########.fr       */
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

	return (0);
}

int		check_balnk(char *line, t_win *win)		// 리턴 1이면 맵의 값이 없다는 뜻
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
