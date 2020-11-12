/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 10:44:15 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/12 10:50:13 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int			itoa_len(long long n)
{
	int				len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len = 1;
	}
	if (n == 0)
		len = 1;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static int			ft_num(int c)
{
	return ((c < 0) ? -c : c);
}

char				*ft_itoa_base(long long n, char x)
{
	char			*hex;
	char			*str;
	int				len;
	int				i;
	int				sign;

	if (x == 'x' || x == 'p')
		hex = "0123456789abcdef";
	else if (x == 'X')
		hex = "0123456789ABCDEF";
	sign = 1;
	len = itoa_len(n);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	sign = (n < 0) ? -1 : 1;
	str[len] = '\0';
	while (i <= --len)
	{
		str[len] = hex[ft_num(n % 16)];
		n = n / 16;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
