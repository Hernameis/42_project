/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:22:19 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/05 21:19:43 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	check;
	int				i;

	check = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == check)
		{
			return ((char *)s + i);
		}
		i++;
	}
	return (NULL);
}
