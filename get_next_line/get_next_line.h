/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:57:01 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/23 14:54:04 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
#  define GET_NEXT_LINE_H

# ifndef FILE_MAX
# define FILE_MAX 4096
# endif

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1000

int		get_next_line(int fd, char **line);
char	*nl_pointer(char *s);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);

# endif
