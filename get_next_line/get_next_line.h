/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:57:01 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/18 17:48:45 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
#  define GET_NEXT_LINE_H

# ifndef FILE_MAX
# define FILE_MAX 4096
# endif

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 32

int		get_next_line(int fd, char **line);

# endif
