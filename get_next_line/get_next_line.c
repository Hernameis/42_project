/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:04:55 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/24 13:21:55 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int		push_gnl(char **remain, char *temp, char **line)
{
	char		*next;

	if (temp)
	{
		*temp = '\0';
		*line = ft_strdup(*remain);
		next = ft_strdup(temp + 1);
		free(*remain);
		*remain = next;
		return (1);
	}
	if (*remain)
	{
		*line = ft_strdup(*remain);
		free(*remain);
		*remain = NULL;
	}
	else
		*remain = ft_strdup("");
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char		*remain[FILE_MAX];
	char		*buff;
	char		*temp;
	ssize_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FILE_MAX || !line)
		return (-1);
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (remain[fd] == NULL)
		remain[fd] = ft_strdup("");
	while (!(temp = is_new(remain[fd])) && (n = read(fd, buff, BUFFER_SIZE) > 0))
	{
		buff[BUFFER_SIZE] = '\0';
		temp = ft_strjoin(remain[fd], buff);
		free(remain[fd]);
		remain[fd] = temp;
	}
	free(buff);
	if (n < 0)
		return (-1);
	return (push_gnl(&remain[fd], temp, line));
}
