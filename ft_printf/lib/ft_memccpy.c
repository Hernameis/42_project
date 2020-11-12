/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:26:28 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/07 15:06:37 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*ddst;
	unsigned char		*ssrc;

	if (dest == NULL && src == NULL)
		return (NULL);
	ddst = (unsigned char *)dest;
	ssrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)ssrc != (unsigned char)c)
			*ddst++ = *ssrc++;
		else
		{
			*ddst = *ssrc;
			return (ddst + 1);
		}
		i++;
	}
	return (NULL);
}
