/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_proccess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 09:48:31 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/12 11:05:42 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void				s_proccess(char *s, spec *sp)			// 공백 - 0 숫자 공백
{
	char			*str;
	int				i;
	int				j;
	int				len;
	int				alloc_len;
	int				real_width;
	int				real_precision;


	if (!s)
		s = ft_strdup("(null)");


	real_width = sp->width;
	len = ft_strlen(s);
	real_precision = len;
	if (sp->zero_precision && sp->s_num == 0)
		real_precision = 0;
	else if (!sp->minus_precision && sp->s_num < len)
		real_precision = sp->s_num;
	else if (!sp->minus_precision && sp->s_num >= len)
		real_precision = len;
	else if (sp->minus_precision && sp->s_num)
		real_precision = len;
	if (sp->empty_precision)
		real_precision = len;
	alloc_len = sp->width;
	if (!sp->width)
		alloc_len = real_precision;
	if(!(str = (char *)malloc(sizeof(char) * (alloc_len + 1))))
		return ;
	str[alloc_len] = '\0';
	i = 0;
	if (!sp->left && !sp->per_zero)
	{
		while (i < sp->width - real_precision)		//  - sp->precision)
		{
			str[i] = ' ';
			i++;
		}
		if (sp->minus && i)
			i--;
	}
	if (sp->per_zero)
	{
		while (i < sp->width - len)
		{
			str[i] = '0';
			i++;
		}
	}
	j = 0;
	while (j < real_precision)
	{
		str[i] = s[j];
		i++;
		j++;
	}

	if (sp->left)									// 마지막 공백 
	{
		j = 0;
		if (sp->minus)
			j++;
		while (i < sp->width)						 //j < sp->width - sp->precision)
		{
			str[i] = ' ';
			i++;
		//	j++;
		}
	}
	while (*str)
	{
		ft_putchar(*str, sp);
		str++;
	}
}

