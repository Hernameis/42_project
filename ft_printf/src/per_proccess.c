/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   per_proccess.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 10:02:27 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/12 11:05:37 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void				per_proccess(spec *sp)			// 공백 - 0 숫자 공백
{
	char			*num;
	char			*str;
	int				i;
	int				j;
	int				len;
	int				alloc_len;
	int				real_width;
	int				real_precision;


	num = "%";

	real_width = sp->width;
	real_precision = sp->precision;
	len = 1;
	if (sp->precision < len)
		sp->precision = len;
	alloc_len = len;
	if(!(str = (char *)malloc(sizeof(char) * (alloc_len + 1))))
		return ;
	str[alloc_len] = '\0';
	i = 0;
	if (!sp->left && !sp->per_zero)
	{
		while (i < sp->width - 1) // sp->precision)
		{
			str[i] = ' ';
			i++;
		}
		if (sp->minus && i)
			i--;
	}
	if (sp->minus)
	{
		str[i] = '%';
		i++;
	}
	if (sp->per_zero)
	{
		while (i < sp->width - len)
		{
			str[i] = '0';
			i++;
		}
	}
	sp->precision = 1;
	j = 0;
	while (j < 1)
	{
		str[i] = '%';
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
		}
	}
	while (*str)
	{
		ft_putchar(*str, sp);
		str++;
	}
}
