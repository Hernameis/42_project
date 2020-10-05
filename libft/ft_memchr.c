/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:30:37 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/05 20:05:05 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*memchr(const void *ptr, int value, size_t n)
{
	char			*cp_ptr;
	unsigned long	i;

	cp_ptr = (char *)ptr;
	i = 0;
	while(i < n)
	{
		if (*(int *)cp_ptr != value)
			cp_ptr++;
		
		else
			return (cp_ptr);
		i++;
	}
	if (*(int *)cp_ptr == 0)
		return (NULL);
	return (NULL);
}
