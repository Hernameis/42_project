/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:34:37 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/03 16:34:39 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memmove(void *dest, const void *src, size_t n)
{
	char *cp_dst;
	char *cp_src;
	int i;

	cp_dst = dest;
	cp_src = src;

	i = 0;
	while(i < n)
	{
		(char) *cp_dst = (char) *cp_src;
		cp_dst++;
		cp_src++;
		i++;
	}
	return (dest);
}

