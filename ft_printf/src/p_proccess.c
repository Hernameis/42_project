/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_proccess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 10:01:45 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/12 12:01:12 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void				p_proccess(long long int p, spec *sp)
{
	char			*num;
	char			*str;
	long long int	n;
	int				i;
	int				j;
	int				len;
	unsigned int	alloc_len;
	int				real_width;
	int				real_precision;

	n = p;
	num = ft_itoa_base(n, 'p');
	sp->minus = 1;						//  -부호 부분을 0x출력으로 사용하기 위함임.
	real_width = sp->width;
	real_precision = sp->precision;
	len = ft_strlen(num);
	if (real_precision < len && real_precision != 0)
		sp->zero = 0;
	if (p == 0 && sp->zero_precision)
		len = 0;
	if (sp->precision < len)
		sp->precision = len;
	if (sp->width < sp->precision)
		sp->width = sp->precision;

	if (sp->minus && (real_width < len || real_width < real_precision))
		alloc_len = sp->width + 2;											// 0x때문에 + 2
	else
		alloc_len = sp->width;

	if(!(str = (char *)malloc(sizeof(char) * (alloc_len  + 1))))
		return ;
	str[alloc_len] = '\0';
	i = 0;
	if (!sp->left && !sp->zero)
	{
		while (i < sp->width - sp->precision)
		{
			str[i] = ' ';
			i++;
		}
		if (sp->minus && i)
		{
			i--;
			if (i)
				i--;
		}
	}
	if (sp->minus)
	{
		str[i] = '0';
		i++;
		str[i] = 'x';
		i++;
	}
	if (sp->zero)
	{
		while (i < sp->width - len)
		{
			str[i] = '0';
			i++;
		}
	}
	j = 0;
	if (sp->precision)
	{
		while (j < sp->precision - len)
		{
			str[i] = '0';
			j++;
			i++;
		}
	}
	j = 0;
	while (len--)
	{
		str[i] = num[j];
		i++;
		j++;
	}
	if (sp->left)
	{
		j = 0;
		if (sp->minus)
		{
			j++;
			j++;
		}
		while (j <sp->width - sp->precision)
		{
			str[i] = ' ';
			i++;
			j++;
		}
	}
	while (*str)
	{
		ft_putchar(*str, sp);
		str++;
	}
	free(num);
}
