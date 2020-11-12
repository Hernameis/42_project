/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:44:21 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/07 20:19:53 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long	i;
	char			*str;

	if (dest == NULL && src == NULL)
		return (NULL);
	str = dest;
	i = 0;
	while (i < n)
	{
		*str++ = *(unsigned char *)src++;
		i++;
	}
	return (dest);
}
