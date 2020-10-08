/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 11:27:36 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/08 17:23:18 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		count;
	char	**split;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] == c)
		i++;
	count = 1;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	if (!(split = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);

	return (split);
	j = 0;
}
