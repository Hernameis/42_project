/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:21:52 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/05 20:12:18 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void const *src1, void const *src2, size_t n)
{
	unsigned long i;
	
	i = 0;
	while (i < n)
	{
		if (*(int *)src1 > *(int *)src2)
			return (1);
		else if (*(int *)src1 < *(int *)src2)
			return (-1);
		src1++;
		src2++;
		i++;
	}
	return (0);
}
