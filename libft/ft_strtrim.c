/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:34:27 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/08 22:39:24 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		start;
	size_t		end;
	size_t		i;

	if (s1 == NULL)
		return (NULL);
	else if (set == NULL)
		return (ft_strdup(s1));
	else if (s1 == NULL)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(s1));
	start = 0;
	while (ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[end]))
		--end;
	if (!(str = (char *)malloc(sizeof(char) * (end - start + 1 + 1))))
		return (NULL);
	i = 0;
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
