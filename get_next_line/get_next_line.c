/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:04:55 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/24 14:39:23 by sunmin           ###   ########.fr       */
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
//		printf("%s%s\n", "line1 :", *line);
//		printf("%s%s\n", "remain1 :", *remain);
		return (1);
	}
	if (*remain)
	{
		*line = ft_strdup(*remain);
//		printf("%s%s\n", "line2 :", *line);
//		printf("%s%s\n", "remain2 :", *remain);
		free(*remain);
		*remain = NULL;
	}
	else
	{
		*remain = ft_strdup("");
//		printf("%s%s\n", "line3 :", *line);
//		printf("%s%s\n", "remain3 :", *remain);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char		*remain[FILE_MAX];
	char		*buff;
	char		*temp;
	int			n;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FILE_MAX || !line)
		return (-1);
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (remain[fd] == NULL)
		remain[fd] = ft_strdup("");
	while (!(temp = is_new(remain[fd], '\n')) && (n = read(fd, buff, BUFFER_SIZE)) > 0)
	{
//		printf("%s%s\n", "oo_buff :", buff);
//		printf("%s %d\n", "nnn", n);
		buff[n] = '\0';
//		printf("%s%s\n", "o_buff :", buff);
		temp = ft_strjoin(remain[fd], buff);
//		printf("%s%s\n", "o_temp :", temp);
		free(remain[fd]);
		remain[fd] = temp;
	}
//	printf("%s%s\n", "o_rem :", remain[fd]);
	free(buff);
	if (n < 0)
		return (-1);
	return (push_gnl(&remain[fd], temp, line));
}
