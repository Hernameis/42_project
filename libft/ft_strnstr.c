/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:13:42 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/06 16:36:02 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	str = (char *)big;
	if (*little == '\0')
		return (str);
	i = 0;
	j = 0;
	k = 0;
	while (str[j])
	{
		if (str[i] != little[j])
			j++;
		else
		{
			while (str[i + k] == little[j + k])
				k++;
		}
	}
	if (str[i + k] == '\0' && little[j + k] == '\0')
		return (&str[i]);
	return (NULL);
	len = 0;
}
