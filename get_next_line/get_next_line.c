/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:35:46 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/23 15:36:07 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		if_nl(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	printf("%c\n", 'a');
	char		*remain[FILE_MAX];
	char		*buff;
//	char		*temp;
	int			n;
	int			nl;

	printf("%c\n", 'b');
	if (fd < 0 || BUFFER_SIZE <= 0)									// 예외처리
		return (-1);
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))		// 버퍼에 버퍼사이즈 만큼 동적할당
		return (-1);
	printf("%s %s\n", "remain : ", remain[fd]);
	while ((n = read(fd, buff, BUFFER_SIZE)) > -1 && printf("%s\n", "read"))			// 오류가 아니면 계속 read함(반복)
	{
		printf("%s\n", "read innnn");
		if (n == 0 && !(if_nl(remain[fd])))													// 읽을 게 없으면
		{
			free(remain[fd]);
			return (0);												// 프리하고 리턴
		}
		printf("%c\n", 'c');
		if (!(remain[fd] = (char *)malloc(sizeof(BUFFER_SIZE + 1))))	// 스태틱에 동적할당
			return (0);
		if (printf("%c\n", 'd') && remain[fd][0] && printf("%s\n", "dd"))				// 스태틱에 값이 있으면
		{
			printf("%c\n", 'e');
			if ((nl = if_nl(remain[fd])))
			{
				printf("%s\n", "ee");
				*line = ft_substr(remain[fd], nl - 1, ft_strlen(remain[fd]));
				return (1);
			}
			else
				*line = ft_strdup(remain[fd]);
		}
		else																			// 스태틱에 값이 없으면
		{
			printf("%c\n", 'f');
			if ((nl = if_nl(buff)))
			{
				printf("%c\n", 'g');
				*line = ft_strjoin(*line, ft_substr(buff, 0, nl - 1));
				remain[fd] = ft_strjoin(remain[fd], ft_substr(buff, nl, ft_strlen(buff)));
				return (1);
			}
			else
			{
				printf("%c\n", 'h');
				*line = ft_strjoin(*line, buff);
			}
			printf("%c\n", 'x');
		}
		printf("%c\n", 'y');
	}
	printf("%c\n", 'z');
	return (0);
}
