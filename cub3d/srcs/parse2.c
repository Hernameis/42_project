/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 12:35:40 by sunmin            #+#    #+#             */
/*   Updated: 2021/03/21 08:42:29 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_word_num(char **split, t_win *win)
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
	split2 = ft_split(split[1], ',');
	num = get_word_num(split2, win);
	if (line[0] == 'F')
	{
		if (num != 3 || split[0][1] != '\0' || win->f_check == 1)
		{
			printf("floor error\n");
			exit(0);
		}
		win->floor_color = ft_atoi(split2[0]) * 256 * 256
			+ ft_atoi(split2[1]) * 256 + ft_atoi(split2[2]);
		win->f_check = 1;
	}
	else if (line[0] == 'C')
	{
		if (num != 3 || split[0][1] != '\0' || win->c_check == 1)
		{
			printf("ceiling error\n");
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

int		get_map(char *line, t_win *win)
{
	int		i;
	int		len;
	char	*index;
	char	*temp;

	index = ft_strdup("a");
	len = ft_strlen(line);
	if (len > win->map_width)
		win->map_width = len;
	if (check_blank(line, win))
	{
		if (win->check_map == 1)
		{
			free(index);
			printf("cub map error\n");
			exit(0);
		}
		else
		{
			free(index);
			return (1);
		}
	}
	else
	{
		win->map_height++;
		win->check_map = 1;
		temp = ft_strdup(win->parse_map);
		free(win->parse_map);
		win->parse_map = ft_strjoin((const char *)temp, (const char *)line);
		free(temp);
		temp = ft_strdup(win->parse_map);
		free(win->parse_map);
		win->parse_map = ft_strjoin((const char *)temp, (const char *)index);
		free(temp);
		free(index);
		return (1);
	}
	free(index);
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
