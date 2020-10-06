/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:30:58 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/06 19:48:13 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t n)
{
	unsigned long i;
	unsigned char cha;
	unsigned char *str;

	i = 0;
	cha = value;
	str = ptr;
	while (i < n)
	{
		str[i] = cha;
		i++;
	}
	return (str);
}
