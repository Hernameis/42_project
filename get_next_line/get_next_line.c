/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:48:57 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/19 10:11:29 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char		*fdfd[4096];
	char		*buff;
	ssize_t		n;

	if (!(buff = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);
	while ((read(fd, buff, BUFFER_SIZE)) != -1)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (ft_strchr(buff, '\n'))
		{

		}
	}

	return (0);
}
