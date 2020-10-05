/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:35:39 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/03 16:35:41 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	int		i;

	str = (void *)malloc(size * count);
	i = 0;
	while (i < count)
	{
		(int)str[i] = 0;
		i++;
	}
	return (str);
}
