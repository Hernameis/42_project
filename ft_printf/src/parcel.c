/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 10:59:07 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/12 12:10:52 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			first_flag(const char **form, spec *sp)
{
	while (**form == '-' || **form == '0')
	{
		if (**form == '-')
			sp->left = 1;
		if (**form == '0')
		{
			sp->zero = 1;
			sp->per_zero = 1;
		}
		(*form)++;
	}
}

int					ft_parcel(const char **form, va_list ap, spec *sp)
{
	(*form)++;
	first_flag(form, sp);
	if ((**form >= '0' && **form <= '9') || **form == '*')
		width_check(form, ap, sp);
	if (**form == '.')
	{
		(*form)++;
		precision_check(form, ap, sp);
	}
	else
		sp->empty_precision = 1;
	if (sp->precision)
		sp->zero = 0;
	else if (sp->zero_precision)
		sp->zero = 0;
	if (sp->left)
	{
		sp->zero = 0;
		sp->per_zero = 0;
	}
	return (ft_parcel2(form, ap, sp));
}

int					ft_parcel2(const char **form, va_list ap, spec *sp)
{
	if (**form == 'd' || **form == 'i')
	{
		d_proccess(va_arg(ap, int), sp);
	}
	else if (**form == 's')
		s_proccess(va_arg(ap, char *), sp);
	else if (**form == 'p')
		p_proccess(va_arg(ap, long long int), sp);
	else if (**form == 'c')
	{
		c_proccess(va_arg(ap, int), sp);
	}
	else if (**form == 'u')
		u_proccess(va_arg(ap, unsigned int), sp);
	else if (**form == 'x')
		x_proccess(va_arg(ap, unsigned int), sp, 'x');
	else if (**form == 'X')
		x_proccess(va_arg(ap, unsigned int), sp, 'X');
	else if (**form == '%')
		per_proccess(sp);
	else
	{
		return (-1);
	}
	return (0);
}
