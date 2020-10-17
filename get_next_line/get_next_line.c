/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:53:28 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/17 21:23:02 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char		*fdfd[4096];
	char		*buff;
	ssize_t		n;

	if(!(buff = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);

	if((read(fd, *buff, BUFFER_SIZE)) == -1)
		return (0);
	return (0);
}
