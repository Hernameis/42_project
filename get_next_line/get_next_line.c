/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:48:57 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/19 17:19:10 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	put_fdfd(char *s, )
{

	return ;
}

void	put_line()
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
		put_fdfd(buff, );
		if (ft_strchr(buff, '\n'))
		{
			put_line();
		}
	}
	return (0);
}
