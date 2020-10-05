/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:13:42 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/05 22:04:40 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;
	int j;
	int k;

	if (*s == '\0')
		return (str);
	i = 0;
	j = 0;
	k = 0;
	while (s[j])
	{
		if (str[i] != s[j])
			j++;
		else
		{
			while (str[i + k] == s[j + k])
				k++;
		}
	}
	if (str[i + k] == '\0' && s[j + k] == '\0')
		return (&str[i]);
	return ('\0');
}
