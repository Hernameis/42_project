/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:34:37 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/05 19:42:14 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char			*cp_dst;
	char			*cp_src;
	unsigned long	i;

	cp_dst = (char *)dest;
	cp_src = (char *)src;

	i = 0;
	while(i < n)
	{
		*(char *)cp_dst = *(char *)cp_src;
		cp_dst++;
		cp_src++;
		i++;
	}
	return (dest);
}
