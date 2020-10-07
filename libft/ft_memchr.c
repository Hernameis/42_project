/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:30:37 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/07 16:13:51 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t n)
{
	unsigned char	*pptr;
	size_t			i;

	pptr = (unsigned char *)ptr;
	i = 0;
	while (n--)
	{
		if (*(unsigned char *)pptr != (unsigned char)value)
			pptr++;
		else
			return (pptr);
	}
	return (NULL);
}
