/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 08:38:50 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/06 19:27:47 by sunmin           ###   ########.fr       */
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

void				d_proccess(int d, spec *sp)			// 공백 - 0 숫자 공백
{
	char			*num;
	char			*str;
	int				n;
	int				i;
	int				j;
	int				len;

	if (d < 0)
	{
		n = -d;
		sp->minus = 1;
	}
	else
		n = d;
	num = ft_itoa(n);
	len = ft_strlen(num);
	if (sp->precision < len)
		sp->precision = len;
	if (sp->width < sp->precision)
		sp->width = sp->precision;
	if(!(str = (char *)malloc(sizeof(char) * (sp->width + 1))))
		return ;
	str[sp->width] = '\0';
	i = 0;
	if (!sp->left && !sp->zero)
	{
		while (i < sp->width - sp->precision)
		{
			str[i] = ' ';
			i++;
		}
		if (sp->minus && i)
			i--;
	}
	if (sp->minus)
	{
		str[i] = '-';
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
	if (sp->left)									// 마지막 공백 
	{
		j = 0;
		if (sp->minus)
			j++;
		while (j < sp->width - sp->precision)
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
	{
		(*form)++;
		precision_check(form, ap, sp);					// precision
	}
	else
		(*form)++;								// precision이 0인 경우 때문에
	if (sp->width < 0 || sp->precision < 0)
		sp->left = 1;
	if (sp->precision)
		sp->zero = 0;
	if (sp->left)
		sp->zero = 0;
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


	printf("[%.-6d]\n", -3);
	printf("[%.6d]\n", -3);
	printf("[%-.6d]\n", -3);
	printf("\n");
	ft_printf("%.6d", -3);



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
	printf("%07.5d\n", 5);
	printf("%07d\n", 5);
//	while (1)
//		;
	return (0);
}
*/
