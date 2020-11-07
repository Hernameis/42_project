/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 08:38:50 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/07 14:35:53 by sunmin           ###   ########.fr       */
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
	sp->zero_precision = 0;
	sp->minus = 0;
	sp->count = 0;
}

void				d_proccess(int d, spec *sp)			// 공백 - 0 숫자 공백
{
//	printf("d_proccess!!!!\n");
	char			*num;
	char			*str;
	int				n;
	int				i;
	int				j;
	int				len;
	int				alloc_len;
	int				real_width;
	int				real_precision;

	if (d < 0)
	{
		n = -d;
		sp->minus = 1;
	}
	else
		n = d;
	num = ft_itoa(n);


	real_width = sp->width;
	real_precision = sp->precision;
//	printf("\nreal_precision %d\n", real_precision);
	len = ft_strlen(num);
	if (real_precision < len && real_precision != 0)
		sp->zero = 0;
	if (d == 0 && sp->zero_precision)
		len = 0;

	if (sp->precision < len)
		sp->precision = len;
	if (sp->width < sp->precision)
		sp->width = sp->precision;

	if (sp->minus && (real_width < len || real_width < real_precision))
		alloc_len = sp->width + 1;
	else
		alloc_len = sp->width;

//	printf("nn num =  %s, alloc_len = %d nn\n", num, alloc_len);
	if(!(str = (char *)malloc(sizeof(char) * (alloc_len + 1))))
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
//	printf("width_check !!!\n");
	int				i;
	int				j;
	int				num;
	char			*tmp;

//	printf("width_check : %s\n", *form);
	i = 0;
	if (**form == '*')
	{
		num = va_arg(ap, int);
		(*form)++;
	}
	else
	{
		while (**form >= '0' && **form <= '9')
		{
			(*form)++;
			i++;
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
	}
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
//	free(tmp);
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

		num= va_arg(ap, int);
//		printf("\n**** %d ****\n", num);
		(*form)++;
	}
	else
	{
		while (**form >= '0' && **form <= '9')
		{
			(*form)++;
			i++;
		}
		j = 0;
		while (j < i)
		{
			(*form)--;
			j++;
		}
		tmp = ft_substr(*form, 0, i);
		num = ft_atoi(tmp);					// num이 0이면 zero_precision 1로 하면 됨.
	}
	if (num < 0)
	{
//		if (sp->left)
//			sp->left = 0;
//		sp->left = 1;
		num = 0;
	}
	else if (num == 0)
		sp->zero_precision = 1;
	sp->precision = num;
	j = 0;
	while (j < i)
	{
		(*form)++;
		j++;
	}
//	if (tmp)
//		free(tmp);
//	printf("precision %d\n", sp->precision);
}

char				**ft_parcel(char **form, va_list ap, spec *sp)	
{
//	printf("parcel 1 !!! & **form = %c \n", **form);
	(*form)++;
	while (**form == '-' || **form == '0')
	{
		if (**form == '-')								// left
			sp->left = 1;
		if (**form == '0')								// zero
			sp->zero = 1;
		(*form)++;
	}
	if ((**form >= '0' && **form <= '9') || **form == '*')
		width_check(form, ap, sp);					// width
	if (**form == '.')
	{
		(*form)++;
		precision_check(form, ap, sp);					// precision
	}
//	alse
//		(*form)++;								// precision이 0인 경우 때문에 ... 하지만 이것 때문에 %d가 바로 오는 경우 d를 건너뜀.
//	if (sp->width < 0 || sp->precision < 0)
//		sp->left = 1;
//	else if (sp->width < 0 && sp->precision < 0)
//		sp->left = 0;
	if (sp->precision)
		sp->zero = 0;
	else if (sp->zero_precision)
		sp->zero = 0;
	if (sp->left)
		sp->zero = 0;
	ft_parcel2(form, ap, sp);
	return (form);
}

char				**ft_parcel2(char **form, va_list ap, spec *sp)
{
//	printf("parcel2!!!\n**form!! = %c\n", **form);
	if (**form == 'd' || **form == 'i')	
	{
		d_proccess(va_arg(ap, int), sp);
//		printf("d,i!!!!\n");
	}
//	else if (**form == 's')
//		s_proccess(, va_arg(ap, char *));			// ??????????
//	else if (**form == 'p')
//		p_proccess();
//	else if (**form == 'c')
//		c_proccess();
	else if (**form == 'u')
		u_proccess(va_arg(ap, unsigned int), sp);
//	else if (**form == 'x')
//		x_proccess();
//	else if (**form == 'X')
//		xx_proccess();
	else										// %%가 들어오는 경우
	{
//		printf("parcel2_else!!\n");
//		per_proccess();
//		printf("444 %c\n", **form);
	}
//	printf("555 %c\n", **form);
//	printf("parcel2 end!!\n");
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
//	printf("width & precision & left_flag & zero & minus & zero_precision\n%d %d %d %d %d %d\n", sp.width, sp.precision, sp.left, sp.zero, sp.minus, sp.zero_precision);
	return (sp.count);
}

//    /*
int		main(void)
{


	printf("-->|%0*.u|<--\n", 4, 512);
	ft_printf("-->|%0*.u|<--\n", 4, 512);

	return (0);
}
//   */
