/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:13:42 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/08 20:45:16 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		l_big;
	size_t		l_lit;
	size_t		size;

	if (little == NULL)
		return ((char *)big);
	l_big = ft_strlen(big);
	l_lit = ft_strlen(little);
	if (len > l_big)
		size = l_big;
	else
		size = len;
	while (size-- >= l_lit)
	{
		if (ft_memcmp(big, little, l_lit) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
