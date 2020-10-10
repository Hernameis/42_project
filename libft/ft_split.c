/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 11:27:36 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/10 18:05:58 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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
		if (check == 0 && s[i] == c)
			check = 1;
		else if (s[i] != c)
		{
			check = 0;
			count++;
		}
		i++;
	}
	return (count);
}

static int		ft_char_num(char *s, int index, char c)
{
//	printf("%s\n", "char_num enter");  ///////////////////////////////
	int		i;
	int		count;

	count = 0;
	i = 0;
	while(count <= index)
	{
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		count++;
//		printf("%d %c\n", i, 'i'); ////////////
	}
	return (i);

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
		while (s[i] != c)
		{
			split[j][k] = s[i];
			i++;
			k++;
		}
		split[j][k] = '\0';
		while (s[i] == c)
			i++;
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
//	printf("%s\n", "word_num success"); /////////////////////////// success
	if(!(split = (char **)malloc(sizeof(char *) * word_num)))
		return (NULL);
	i = 0;
	while (i < word_num)
	{
	   	if (!(split[i] = (char *)malloc(sizeof(char) * ft_char_num(str, i, c) + 1)))
			return (NULL);
		i++;
	}
//	printf("%s\n", "char_num malloc success");   ///////////////// fail
	ft_push_split(str, split, word_num, c);
//	printf("%s\n", "split success");  ////////////////////////////
	return (split);
}

int		main(void)
{
	char	**split;
	int		i;


	split = ft_split("abcdabcdab", 'a');
	i = 0;
	while (i < 10)
	{
		printf("%s\n", split[i]);
		i++;
	}
	printf("%s\n", "abcdabcdab");
	return (0);
}
