/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:04:55 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/23 21:24:12 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			get_next_line(int fd, char **line)
{
	char		*remain[FILE_MAX];
	char		buff[BUFFER_SIZE + 1];
	size_t		nl;
	ssize_t		n;

	printf("%s\n", "aaa");
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!(remain[fd] = ft_strdup("")))
		return (-1);
	printf("%s\n", "bbb");
	while (n = read(fd, buff, BUFFER_SIZE) && !is_new(buff))
	{
		buff[BUFFER_SIZE] = '\0';
		remain[fd] = ft_strjoin(remain[fd], buff);
	}
	return (0);
}
