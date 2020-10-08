/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:34:37 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/08 15:20:50 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ddst;
	unsigned char	*ssrc;

	if (dest == NULL && src == NULL)
		return (NULL);
	ddst = (unsigned char *)dest;
	ssrc = (unsigned char *)src;
	if (ssrc > ddst)
	{
		while (n--)
			*(unsigned char *)ddst++ = *(unsigned char *)ssrc++;
	}
	else
	{
		ddst += n;
		ssrc += n;
		while (n--)
			*(unsigned char *)--ddst = *(unsigned char *)--ssrc;
	}
	return (dest);
}
