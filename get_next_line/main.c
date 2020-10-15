/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:56:16 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/15 17:21:31 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int		main(void)
{
	int		fd;
	char	*line;
	char	*BUFFER_SIZE[50];

	fd = open("./test", O_RDONLY);
	printf("%d\n", fd);
	printf("%zd\n", read(0, BUFFER_SIZE, 60));
	return (0);
	line = "1";
}
