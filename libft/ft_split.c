/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 11:27:36 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/09 23:24:52 by sunmin           ###   ########.fr       */
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
	split = NULL;
	return (split);
	j = 0;
}
