/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:00:09 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/12 11:02:50 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void				ft_putchar(char c, spec *sp)
{
	write(1, &c, 1);
	(sp->count)++;
}

void				init_spec(spec *sp)
{
	sp->zero = 0;
	sp->per_zero = 0;
	sp->left = 0;
	sp->width = 0;
	sp->precision = 0;
	sp->zero_precision = 0;
	sp->minus = 0;
	sp->s_num = 0;
	sp->minus_precision = 0;
	sp->empty_precision = 0;
}

int					ft_printf(const char *format, ...)
{
	va_list			ap;
	spec			sp;

	va_start(ap, format);
	sp.count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			init_spec(&sp);
			if (ft_parcel(&format, ap, &sp) == -1)
				return (-1);
		}
		else
			ft_putchar(*format, &sp);
		format++;
	}
	va_end(ap);
	return (sp.count);
}
