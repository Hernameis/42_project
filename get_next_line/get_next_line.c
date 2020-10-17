/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:53:28 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/17 20:20:47 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char		*fdfd[4096];
	char		*buff;
	ssize_t		n;

	if(!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);

	n = read(fd, *buff, BUFFER_SIZE);			// ssize_t	read(int fd, void *buf, size_t count);
	return (0);
}
