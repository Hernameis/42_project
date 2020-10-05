/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 13:50:08 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/03 17:12:42 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		i;
	int		nb;
	int		nb_len;
	int		len;
	char	*str;

	if (n < 0)
	{
		len = 1;
		nb = -n;
	}
	else
	{
		len = 0;
		nb = n;
	}
	nb_len = nb;
	while (nb_len != 0)
	{
		nb_len /= 10;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		i = 1;
	}
	else
		i = 0;
	while (i < len)
	{
		str[len] = nb % 10 + '0';
		nb /= 10;
		len--;
	}
	return (str);
}
