/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 11:27:36 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/10 19:57:07 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_num(char *s, char c)
{
	int		check;
	int		i;
	int		count;

	count = 0;
	check = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			check = 0;
			i++;
		}
		while (s[i] && s[i] != c)
		{
			check = 1;
			i++;
		}
		if (check == 1)
			count++;
	}
	return (count);
}

static int		ft_char_num(char *s, int index, char c)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = 0;
	while (count <= index)
	{
		j = 0;
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			j++;
		}
		count++;
	}
	return (j);
}

static char		**ft_push_split(char *s, char **split, int num, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (j < num)
	{
		k = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c)
		{
			split[j][k] = s[i];
			i++;
			k++;
		}
		split[j][k] = '\0';
		j++;
	}
	return (split);
}

char			**ft_split(char const *s, char c)
{
	int		word_num;
	int		i;
	char	**split;
	char	*str;

	str = (char *)s;
	if (s == NULL)
		return (NULL);
	word_num = ft_word_num(str, c);
	if (!(split = (char **)malloc(sizeof(char *) * word_num)))
		return (NULL);
	i = 0;
	while (i < word_num)
	{
		if (!(split[i] = (char *)malloc(sizeof(char) *
						ft_char_num(str, i, c) + 1)))
			return (NULL);
		i++;
	}
	ft_push_split(str, split, word_num, c);
	return (split);
}
