/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:34:27 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/09 14:06:38 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		start;
	size_t		end;

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
	while (ft_strchr(set, s1[end - 1]))
	{
		if (end - 1 < 1)
			break ;
		--end;
	}
	printf("%zu %zu\n", start, end);
	if (!(str = (char *)malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	if (start > end)
		return (strdup(""));
	ft_strlcpy(str, s1 + start, end - start + 1);
	return (str);
}

int		main(void)
{
	char *s1 = " \t \t \n  \n\n\n\t";
	printf("%s\n", ft_strtrim(s1, " \n\t"));
	return (0);
}
