/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:13:42 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/08 21:57:42 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		l_big;         // 없으면 NO CRASH 뜸
	size_t		l_lit;

	l_big = ft_strlen(big);      // 없으면 NO CRASH 뜸
	l_lit = ft_strlen(little);
	while (len-- >= l_lit)
	{
		if (ft_memcmp(big, little, l_lit) == 0)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
