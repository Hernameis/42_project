/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:32:28 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/06 11:25:10 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub;
	int i;
	int j;

	if(!(sub = (char *)malloc(sizeof(char) * (len - start))))
		return (NULL);
	i = 0;
	j = start;
	while (start < len)
	{
		sub[i] = s[j];
		i++;
		j++;
	}
	return (sub);
}
