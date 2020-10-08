/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:21:52 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/08 14:41:45 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void const *src1, void const *src2, size_t n)
{
	unsigned char *s1;
	unsigned char *s2;

	s1 = (unsigned char *)src1;
	s2 = (unsigned char *)src2;
	if (n == 0)
		return (0);
	n -= 1;
	while (n--)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
		}
	}
	return ((int)(*s1 - *s2));
}
