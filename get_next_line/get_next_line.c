/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:48:57 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/19 20:26:14 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	put_fdfd(int fd, char *buff, int BUFFER_SIZE)
{
	int		i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		fdfd[fd][i] = buff[i];
		i++;
	}
	return ;
}

void	put_line()    // 개행 문자를 만나면 실행되도록.
{

	return ;
}

int		get_next_line(int fd, char **line)
{
	static char		*fdfd[4096];
	char			*buff;
	ssize_t			n;

	if (!(buff = (char *)malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);
	while ((n = read(fd, buff, BUFFER_SIZE)) != -1)
	{
		put_fdfd(fd, buff, BUFFER_SIZE);
		put_line();
		if (ft_strchr(buff, '\n'))
		{
			put_line();		// 개행 전까지만 집어넣도록 ???
		}
	}
	return (0);
}
