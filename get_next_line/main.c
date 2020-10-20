/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:56:16 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/20 20:38:12 by sunmin           ###   ########.fr       */
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

	fd = open("./test", O_RDONLY);
	while (printf("%s %d\n", "Get_next_line Result : ", get_next_line(fd, &line)))
	{
		printf("%s %s\n", "in the fd : ", line);
	}
}
