/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 13:48:57 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/20 19:04:40 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void		put_fdfd(int fd, char *buff, int BUFFER_SIZE)		// 개행을 확인해서 
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

static void		put_line(char *buff, char **line)    // 개행문자가 없으면 ㄱ다 집어넣고, 개행이 있으면 개행까지만 집어넣음.
{
	char		*str;

	if (ft_strchr(buff, '\n')) // buff안에 개행이 있으면, 개행까지만 line에 넣어주고 나머지는 fdfd에 넣어줌?????
	{
		개행까지만 line에 집어넣음;
	}
	else						// buff안에 개행이 없으면 다 넣으면 됨
	{
		ft_strjoin(*line, buff);
	}
	return ;
}

static int		ft_return()		// 리턴하기 전에 free하는 부분 처리하는 함수.
{
	return (0);
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
		if (n == 0)
			break ;
		if (n > 0)
		{
			put_line(buff, **line);		// 개행 전까지만 집어넣도록 ???
			put_fdfd(fd, buff, BUFFER_SIZE);
		}
	}
	ft_return();
	return (0);
}
