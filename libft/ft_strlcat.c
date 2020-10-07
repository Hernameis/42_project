/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:35:28 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/07 21:19:48 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*ssrc;
	char	d_len;
	char	s_len;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	ssrc = (char *)src;
	while (*dst)
		dst++;
	while (*src && size)
	{
		*dst++ = *ssrc++;
		size--;
	}
	return (d_len + s_len);
}
