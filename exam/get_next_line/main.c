/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:56:16 by sunmin            #+#    #+#             */
/*   Updated: 2021/04/16 13:20:35 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int		get_next_line(char **line);

int		main(void)
{
	int		fd;
	char	*line;
	int		a;

	fd = open("./test", O_RDONLY);
	while ((a = get_next_line(&line)) > -1)
	{
		printf("%s %d\n", "Get_next_line Result : ", a);
		printf("%s %s\n\n", "in the line : ", line);
		if (a == 0)
			break ;
	}
	return (0);
}
