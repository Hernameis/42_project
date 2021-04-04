/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:35:40 by sunmin            #+#    #+#             */
/*   Updated: 2021/04/05 08:18:46 by sunmin           ###   ########.fr       */
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

	split = ft_split(line, ' ');
	if (!split[1] || split[2])
	{
		printf("cf_error\n");
		exit(0);
	}
	check_comma(win, split[1]);
	if (!(split2 = ft_split(split[1], ',')))
	{
		printf("error\nceiling_floor error\n");
		exit(0);
	}
	check_cf_color(split2);
	num = get_word_num(split2);
	if (line[0] == 'F')
		get_floor_color(win, split, split2, num);
	else if (line[0] == 'C')
		floor_ceiling_check(win, split, split2, num);
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
	check_contain_number(split2[0]);
	check_contain_number(split2[1]);
	check_contain_number(split2[2]);
	win->floor_color = ft_atoi(split2[0]) * 256 * 256
		+ ft_atoi(split2[1]) * 256 + ft_atoi(split2[2]);
	win->f_check = 1;
}

int		get_map(char *line, t_win *win)
{
	win->map_check = 0;
	win->index = ft_strdup("a");
	if ((int)ft_strlen(line) > win->map_width)
		win->map_width = ft_strlen(line);
	if (check_blank(line))
	{
		if (win->check_map == 1)
		{
			free(win->index);
			return (0);
		}
		else
		{
			free(win->index);
			return (1);
		}
	}
	else
	{
		map_end_error(win);
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
