/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:16:04 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/10 20:36:17 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	unsigned char	*ssrc;
	size_t			i;
	size_t			len;

	if (dest == NULL || src == NULL)
		return (0);
	ssrc = (unsigned char *)src;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	i = 1;
	while (i < dstsize && *ssrc)
	{
		*dest++ = *ssrc++;
		i++;
	}
	*dest = '\0';
	return (len);
}
