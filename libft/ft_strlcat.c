/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:35:28 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/05 21:02:18 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			size_dst;
	size_t			size_src;
	unsigned long	i;
	unsigned long	j;

	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (size > size_dst + 1)
	{
		i = size_dst;
		j = 0;
		while (size > size_dst + j)
		{
			dst[size_dst + j] = src[j];
			j++;
		}
		dst[size_dst + j] = '\0';
	}
	if (size > size_dst + 1)
		return (size_dst + j);
	return (size_dst);
}
