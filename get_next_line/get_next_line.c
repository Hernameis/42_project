/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:53:28 by sunmin            #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2020/10/17 23:04:36 by sunmin           ###   ########.fr       */
=======
/*   Updated: 2020/10/18 13:21:27 by sunmin           ###   ########.fr       */
>>>>>>> Stashed changes
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
	while((read(fd, *buff, BUFFER_SIZE)) != -1)
	{
		if (strchr(buff, '\n'))
		{
			
		}
	}

	return (0);
}
