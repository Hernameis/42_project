/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:35:40 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/28 12:02:11 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_word_num(char **split)
{
	int		i;

	i = 0;
	while (split[i])
	{
		i++;
	}
	return (i);
}

void	get_floor_ceiling_color(char *line, t_win *win)
{
	char	**split;
	char	**split2;
	int		num;

	check_comma(win, line);
	split = ft_split(line, ' ');
	split2 = ft_split(split[1], ',');
	num = get_word_num(split2);
	if (line[0] == 'F')
		get_floor_color(win, split, split2, num);
	else if (line[0] == 'C')
	{
		if (num != 3 || split[0][1] != '\0' || win->c_check == 1)
		{
			printf("error\nceiling\n");
			exit(0);
		}
		win->ceiling_color = ft_atoi(split2[0]) * 256 * 256
			+ ft_atoi(split2[1]) * 256 + ft_atoi(split2[2]);
		win->c_check = 1;
	}
	else
		;
	free_split(split);
	free_split(split2);
}

void	get_floor_color(t_win *win, char **split, char **split2, int num)
{
	if (num != 3 || split[0][1] != '\0' || win->f_check == 1)
	{
		printf("error\nfloor\n");
		exit(0);
	}
	win->floor_color = ft_atoi(split2[0]) * 256 * 256
		+ ft_atoi(split2[1]) * 256 + ft_atoi(split2[2]);
	win->f_check = 1;
}

int		get_map(char *line, t_win *win)
{
	win->index = ft_strdup("a");
	if ((int)ft_strlen(line) > win->map_width)
		win->map_width = ft_strlen(line);
	if (check_blank(line))
	{
		if (win->check_map == 1)
		{
			free(win->index);
			printf("cub map error\n");
			exit(0);
		}
		else
		{
			free(win->index);
			return (1);
		}
	}
	else
	{
		swap_map(win, line);
		return (1);
	}
	free(win->index);
	return (1);
}

int		check_cubfile(const char *str)
{
	size_t		len;

	len = ft_strlen(str);
	if (str[len - 4] == '.' && str[len - 3] == 'c'
			&& str[len - 2] == 'u' && str[len - 1] == 'b')
		return (1);
	return (0);
}
