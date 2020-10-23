/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:04:55 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/23 19:24:47 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	char		*remain[FILE_MAX];
	char		buff[BUFFER_SIZE + 1];
	size_t		nl;
	ssize_t		n;

	if (!(remain[fd] = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((n = read(fd, buff, BUFFER_SIZE)) > -1)
	{
		buff[BUFFER_SIZE] = '\0';
		if (remain[fd][0])
		{
			*line = ft_strjoin(*line, remain[fd]);
			nl = is_new(remain[fd]);
			remain[fd] = ft_substr(remain[fd], nl, ft_strlen(remain[fd]) - nl);
			return (0);
		}
		free(remain[fd]);
	}
	return (0);
}
