/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:26:28 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/03 16:26:30 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memccpy(void *dest, const void *src, int c, size_t n)
{
	int i;

	i = 0;
	while (src[i])
	{
		if (src[i] == c)
		{
			dest[i] = src[i];
			i++;
		}
		else
			break ;
	}
	if (src[i] != '\0')
		return (dest);
	return (NULL);
}
