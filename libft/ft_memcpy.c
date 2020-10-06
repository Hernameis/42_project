/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:44:21 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/06 11:21:20 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long i;

	i = 0;
	while (i < n)
	{
		*(int *)dest = *(int *)src;
		dest++;
		src++;
		i++;
	}
	*(int *)dest = 0;
	return (dest);
}
