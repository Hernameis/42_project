/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 08:38:50 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/04 16:18:48 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

typedef struct		specifier
{
	int				zero;
	int				left;
	int				width;
	int				precision;
	int				count;
}					spec;

void				ft_putchar(char c, spec *sp)
{
	write(1, &c, 1);
	(sp->count)++;
}

void				init_spec(spec *sp)
{
	sp->zero = 0;
	sp->left = 0;
	sp->width = 0;
	sp->precision = 0;
	sp->count = 0;
}

void				d_proccess(int d, spec *sp)
{
//	printf("d_proccess : %d\n", d);
	char			*str;
	char			*str2;
	int				i;
	int				j;

	str = ft_itoa(d);
	printf("itoa : %s\n", str);
	sp->precision < ft_strlen(str) ? ft_strlen(str) : sp->precision;
	if (sp->precision > sp->width)
		sp->width = sp->precision;
	if(!(str2 = (char *)malloc(sizeof(char) * (sp->width + 1))))
			return ;
	if (sp->zero)
		ft_bzero(str2, 0);
	else
	{
		ft_memset(str2, ' ', sp->width);
		str2[sp->width] = '\0';
	}
	if (sp->left)
	{
		i = 0;
		while (i < sp->width && i < sp->precision)
		{
			str2[i] = str[i];
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < sp->width - sp->precision)
		{
			str2[i] = ' ';
			i++;
		}
		printf("strlen : %zu\n", ft_strlen(str));
		while (i < sp->precision - ft_strlen(str))
		{
			i++;
		}
		j = 0;
		while (i < sp->precision)
		{
			str2[i] = str[j];
			i++;
			j++;
		}
	}
	i = 0;
	while (str2[i])
	{
		ft_putchar(str2[i], sp);
		i++;
	}
	free(str);
	free(str2);
}
// cspdiuxX%

char				**ft_parcel(char **form, va_list ap, spec *sp)			//나중에 2부분으로 분할.
{									// 인덱스 증가시킴 서식지정자랑 플래그들 체크	// set_flags먼저 하고 d,s,c 구분해서 보냄
//	printf("%d\n", 111);
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
	while ((**form >= '0' && **form <= '9') || **form == '*')			// width	wildcard도 생각해야함.
	{
		if (**form == '*')
		{
			sp->width = va_arg(ap, int);
			(*form)++;
			break ;
		}
		sp->width = (sp->width * 10) + **form - '0';
		(*form)++;
//		printf("222 %c\n", **form);
	}
	if (**form == '.')
		(*form)++;
	while ((**form >= '0' && **form <= '9') || **form == '*')			// precision	wildcard도 생각해야함.
	{
		if (**form == '*')
		{
			sp->precision = va_arg(ap, int);
			(*form)++;
			break ;
		}
		sp->precision = (sp->precision * 10) + **form - '0';
		(*form)++;
	}
	if (**form == 'd' || **form == 'i')								// 2번 파셀
	{
//		printf("333 %c\n", **form);
		d_proccess(va_arg(ap, int), sp);
	}
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
	else
	{
//		per_proccess();
		printf("444 %c\n", **form);
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
	va_end(ap);
	printf("return : %d\n", sp.count);
	printf("zero : %d, left : %d, width : %d, precision : %d\n", sp.zero, sp.left, sp.width, sp.precision);
	return (sp.count);
}



int		main(void)
{
	printf("=================\n");
	printf("%-3.5dabcd\nreturn : %d\n", 51, printf("%-3.5dabcd\n", 51));
	printf("%*.*dabcde\nreturn : %d\n", -3, 5, 51, printf("%-3.5dabcde\n", 51));
	printf("%010.5d\n", 21);
	printf("=================\n");
	ft_printf("%3.*dabcd\n", 5, 51);
//	while(1)
//		;
	return (0);
}
