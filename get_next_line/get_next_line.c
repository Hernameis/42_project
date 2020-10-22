/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 16:35:46 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/22 14:34:58 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	char		*remainder[FILE_MAX];
	char		*buff[BUFFER_SIZE + 1];
	char		*temp;
	int			n;

	while (n = read(fd, buff, BUFFER_SIZE) && !(ft_strchr(buff, '\n')))
	{
		if (*line == NULL)
			line = ft_strdup(buffer);
		else
			ft_strjoin(line, buff);
	}
	return (0);
}
