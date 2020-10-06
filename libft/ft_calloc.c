/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:35:39 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/06 11:15:42 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void				*str;
	unsigned long		i;

	str = (void *)malloc(size * count + 1);
	i = 0;
	while (i < count)
	{
		*(int *)str = 0;
		str++;
		i++;
	}
	return (str);
}
