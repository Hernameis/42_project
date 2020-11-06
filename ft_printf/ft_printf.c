/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 08:38:50 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/06 16:10:06 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void				ft_putchar(char c, spec *sp)
{
	write(1, &c, 1);
	(sp->count)++;
//	printf("\ncount : %d\n", sp->count);
}

void				init_spec(spec *sp)
{
	sp->zero = 0;
	sp->left = 0;
	sp->width = 0;
	sp->precision = 0;
	sp->minus = 0;
	sp->count = 0;
}

void				d_proccess(int d, spec *sp)
{

}

// cspdiuxX%
void				width_check(char **form, va_list ap, spec *sp)
{
	int				i;
	int				j;
	int				num;
	char			*tmp;

//	printf("width_check : %s\n", *form);
	i = 0;
	if (**form == '*')
	{
		sp->width = va_arg(ap, int);
		(*form)++;
	}
	else
	{
		while (**form >= '0' && **form <= '9')
		{
			(*form)++;
			i++;
		}
	}
	j = 0;
	while (j < i)
	{
		(*form)--;
		j++;
	}
//	printf("%s %d\n", *form, i);
	tmp = ft_substr(*form, 0, i);
	num = ft_atoi(tmp);
	if (num < 0)
	{
		sp->left = 1;
		num = -num;
	}
	sp->width = num;
	j = 0;
	while (j < i)
	{
		(*form)++;
		j++;
	}
	free(tmp);
}

void				precision_check(char **form, va_list ap, spec *sp)
{
	int				i;
	int				j;
	int				num;
	char			*tmp;

	i = 0;
	if (**form == '*')
	{
		sp->precision = va_arg(ap, int);
		(*form)++;
	}
	else
	{
		while (**form >= '0' && **form <= '9')
		{
			(*form)++;
			i++;
		}
	}
	j = 0;
	while (j < i)
	{
		(*form)--;
		j++;
	}
	tmp = ft_substr(*form, 0, i);
	num = ft_atoi(tmp);
	if (num < 0)
	{
		sp->left = 1;
		num = -num;
	}
	sp->precision = num;
	j = 0;
	while (j < i)
	{
		(*form)++;
		j++;
	}
	free(tmp);
}

char				**ft_parcel(char **form, va_list ap, spec *sp)	
{
	(*form)++;
	if (**form == '-')								// left
	{
		sp->left = 1;
		(*form)++;
	}
	if (**form == '0')								// zero
	{
		sp->zero = 1;
		(*form)++;
	}
	width_check(form, ap, sp);						// width
	if (**form == '.')
		(*form)++;
	precision_check(form, ap, sp);					// precision
	if (sp->width < 0 || sp->precision < 0)
		sp->left = 1;
	ft_parcel2(form, ap, sp);
	return (form);
}

char				**ft_parcel2(char **form, va_list ap, spec *sp)
{
	if (**form == 'd' || **form == 'i')	
		d_proccess(va_arg(ap, int), sp);
//	else if (**form == 's')
//		s_proccess(, va_arg(ap, char *));			// ??????????
//	else if (**form == 'p')
//		p_proccess();
//	else if (**form == 'c')
//		c_proccess();
//	else if (**form == 'u')
//		u_proccess();
//	else if (**form == 'x')
//		x_proccess();
//	else if (**form == 'X')
//		xx_proccess();
	else										// %%가 들어오는 경우
	{
//		per_proccess();
//		printf("444 %c\n", **form);
	}
//	printf("555 %c\n", **form);
	return (form);
}

int					ft_printf(const char *format, ...)
{
	va_list			ap;
	spec			sp;
	char			*str;

	str = (char *)format;
	va_start(ap, format);
	init_spec(&sp);
	while (*str)
	{
		if (*str == '%')
			str = *(ft_parcel(&str, ap, &sp));
		else
			ft_putchar(*str, &sp);
		str++;
	}
//	printf("zero : %d, left : %d, width : %d, precision : %d, minus : %d, count :  %d\n", sp.zero, sp.left, sp.width, sp.precision, sp.minus, sp.count);
	va_end(ap);
	return (sp.count);
}

/*
int		main(void)
{
	printf("%11.5d\n", -53);
	ft_printf("%11.5d\n", -53);
	printf("==========\n");
	printf("%7d\n", -14);
	ft_printf("%7d\n", -14);
	printf("==========\n");
	printf("%3d\n", 0);
	ft_printf("%3d\n", 0);
	printf("==========\n");
	printf("%-7d\n", 33);
	ft_printf("%-7d\n", 33);
	printf("==========\n");
	printf("%-7d\n", -14);
	ft_printf("%-7d\n", -14);
	printf("==========\n");
	printf("%-3d\n", 0);
	ft_printf("%-3d\n", 0);
	printf("==========\n");
	printf("%-5d\n", -2562);
	ft_printf("%-5d\n", -2562);
	printf("==========\n");
//	while (1)
//		;
	return (0);
}
*/
