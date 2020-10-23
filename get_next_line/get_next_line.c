/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:04:55 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/23 16:50:22 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	char		*remain[FILE_MAX];
	char		buff[BUFFER_SIZE + 1];
	ssize_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	buff[BUFFER_SIZE] = '\0';
	while (n = read(fd, buff, BUFFER_SIZE))
	{

	}
	return (0);
}
