/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 12:25:05 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/03 16:30:10 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		count;
	char	**split;

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
}
