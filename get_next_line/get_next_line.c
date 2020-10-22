/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:35:46 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/22 21:31:18 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		if_nl(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*remain[FILE_MAX];
	char		*buff;
//	char		*temp;
	int			n;
	int			nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((n = read(fd, buff, BUFFER_SIZE)) > -1)
	{
		if (n == 0)
		{
			free(remain[fd]);
			return (0);
		}
		if (remain[fd][0])
		{
			if ((nl = if_nl(remain[fd])))
			{
				*line = ft_substr(remain[fd], nl - 1, ft_strlen(remain[fd]));
				return (1);
			}
			else
			{
				*line = ft_strdup(remain[fd]);
			}
		}
		else
		{
			if ((nl = if_nl(buff)))
			{
				*line = ft_strjoin(*line, ft_substr(buff, 0, nl - 1));
			}
			else
			{
				*line = ft_strjoin(*line, buff);
			}
		}
		return (0);
	}
	return (0);
}
