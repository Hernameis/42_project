/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:53:28 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/16 19:51:58 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char *FD[1024];
	ssize_t		n;

	n = read(fd, 				// ssize_t	read(int fd, void *buf, size_t count);
	return (0);
}
