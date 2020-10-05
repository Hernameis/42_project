/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:26:28 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/05 19:38:37 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned long i;

	i = 0;
	while (i < n)
	{
		if (*(int *)src == c)
		{
			*(int *)dest = *(int *)src;
			dest++;
			src++;
			i++;
		}
		else
			break ;
	}
	if (*(int *)src != '\0')
		return (dest);
	return (NULL);
}
