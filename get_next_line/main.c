/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:56:16 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/24 14:18:39 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "get_next_line.h"

int		main(void)
{
	int		fd;
	char	*line;
	int		a;

	fd = open("./test", O_RDONLY);
	while ((a = get_next_line(fd, &line)) > -1)
	{
		printf("%s %d\n", "Get_next_line Result : ", a);
		printf("%s %s\n\n", "in the line : ", line);
		if (a == 0)
			break ;
	}
	return (0);
}
