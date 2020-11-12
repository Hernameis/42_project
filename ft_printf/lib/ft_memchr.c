/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:30:37 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/07 20:50:32 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t n)
{
	unsigned char	*pptr;

	pptr = (unsigned char *)ptr;
	while (n--)
	{
		if (*pptr != (unsigned char)value)
			pptr++;
		else
			return (pptr);
	}
	return (NULL);
}
