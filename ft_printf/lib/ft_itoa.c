/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 13:50:08 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/11 11:46:13 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		itoa_len(long long n)
{
	int		len;

	len = 0;
	if (n < 0)
		n = -n;
	if (n == 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int		ft_num(int c)
{
	return ((c < 0) ? -c : c);
}

char			*ft_itoa(long long n)
{
	char	*str;
	int		len;
	int		i;
	int		sign;

	sign = 1;
	len = itoa_len(n);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	sign = (n < 0) ? -1 : 1;
	str[len] = '\0';
	while (i <= --len)
	{
		str[len] = ft_num(n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
