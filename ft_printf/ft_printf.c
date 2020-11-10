/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 08:38:50 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/10 11:48:39 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

static int			itoa_len(long long n)
{
	int				len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len = 1;
	}
	if (n == 0)
		len = 1;
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static int			ft_num(int c)
{
	return ((c < 0) ? -c : c);
}

char				*ft_itoa_base(long long n, char x)
{
	char			*hex;
	char			*str;
	int				len;
	int				i;
	int				sign;

	if (x == 'x' || x == 'p')
		hex = "0123456789abcdef";
	else if(x == 'X')
		hex = "0123456789ABCDEF";
	sign = 1;
	len = itoa_len(n);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	sign = (n < 0) ? -1 : 1;
	str[len] = '\0';
	while (i <= --len)
	{
		str[len] = hex[ft_num(n % 16)];
		n = n / 16;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}														// 여기까지 이토아 베이스 

void				ft_putchar(char c, spec *sp)
{
	write(1, &c, 1);
	(sp->count)++;
//	printf("\ncount : %d\n", sp->count);
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
	sp->count = 0;
	sp->s_num = 0;
	sp->minus_precision = 0;
	sp->empty_precision = 0;
}


void				s_proccess(char *s, spec *sp)			// 공백 - 0 숫자 공백
{
//	printf("d_proccess!!!!\n");
	char			*str;
	int				i;
	int				j;
	int				len;
	int				alloc_len;
	int				real_width;
	int				real_precision;


	if (!s)
		s = ft_strdup("(null)");
		 //	sp->minus = 1;


	real_width = sp->width;
//	if (sp->s_num)
//		real_precision = sp->s_num;
//	else
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



//	printf("\nreal_precision %d\n", real_precision);
//	if (real_precision < len && real_precision != 0)
//		sp->zero = 0;
//	if (sp->precision < len)
//		sp->precision = len;
//	if (sp->width < sp->precision)
//		sp->width = sp->precision;

//	if (sp->minus && (real_width < len || real_width < real_precision))
//		alloc_len = sp->width + 1;
//	else
		alloc_len = sp->width;

//	printf("nn num =  %s, alloc_len = %d nn\n", num, alloc_len);
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
//	if (sp->minus)
//	{
//		str[i] = c
//		i++;
//	}
	if (sp->per_zero)
	{
		while (i < sp->width - len)
		{
			str[i] = '0';
			i++;
		}
	}
//	j = 0;
//	if (sp->precision)
//	{
//		while (j < sp->precision - len)
//		{
//			str[i] = '0';
//			j++;
//			i++;
//		}
//	}
//	sp->precision = 1;

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
//	printf("\n\nalloc_len : %d real_width : %d real_precision : %d sp->zero : %d sp->left : %d sp->minus : %d sp->width : %d sp->precision : %d sp->zero_precision %d sp->per_zero %d sp->s_num %d\n", alloc_len, real_width, real_precision, sp->zero, sp->left, sp->minus, sp->width, sp->precision, sp->zero_precision, sp->per_zero, sp->s_num);

	while (*str)
	{
		ft_putchar(*str, sp);
		str++;
	}
//	free(num);
}



void				c_proccess(char c, spec *sp)			// 공백 - 0 숫자 공백
{
//	printf("d_proccess!!!!\n");
	char			*str;
	int				i;
	int				j;
	int				len;
	int				alloc_len;
	int				real_width;
	int				real_precision;


//	sp->minus = 1;


	real_width = sp->width;
	real_precision = sp->precision;
//	printf("\nreal_precision %d\n", real_precision);
	len = 1;
//	if (real_precision < len && real_precision != 0)
//		sp->zero = 0;
	if (sp->precision < len)
		sp->precision = len;
	if (sp->width < sp->precision)
		sp->width = sp->precision;

//	if (sp->minus && (real_width < len || real_width < real_precision))
//		alloc_len = sp->width + 1;
//	else
		alloc_len = sp->width;

//	printf("nn num =  %s, alloc_len = %d nn\n", num, alloc_len);
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
		str[i] = c;
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
//	j = 0;
//	if (sp->precision)
//	{
//		while (j < sp->precision - len)
//		{
//			str[i] = '0';
//			j++;
//			i++;
//		}
//	}
	sp->precision = 1;
	j = 0;
	while (j < 1)
	{
		str[i] = c;
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
//	printf("\n\nalloc_len : %d real_width : %d real_precision : %d sp->zero : %d sp->left : %d sp->minus : %d sp->width : %d sp->precision : %d sp->zero_precision %d sp->per_zero %d\n", alloc_len, real_width, real_precision, sp->zero, sp->left, sp->minus, sp->width, sp->precision, sp->zero_precision, sp->per_zero);
	i = 0;
	while (i < sp->width)
	{
		ft_putchar(str[i], sp);
		i++;
	}
//	free(num);
}




void				per_proccess(spec *sp)			// 공백 - 0 숫자 공백
{
//	printf("d_proccess!!!!\n");
	char			*num;
	char			*str;
	int				i;
	int				j;
	int				len;
	int				alloc_len;
	int				real_width;
	int				real_precision;


//	sp->minus = 1;

	num = "%";

	real_width = sp->width;
	real_precision = sp->precision;
//	printf("\nreal_precision %d\n", real_precision);
	len = 1;
//	if (real_precision < len && real_precision != 0)
//		sp->zero = 0;
	if (sp->precision < len)
		sp->precision = len;
//	if (sp->width < sp->precision)
//		sp->width = sp->precision;

//	if (sp->minus && (real_width < len || real_width < real_precision))
//		alloc_len = sp->width + 1;
//	else
		alloc_len = sp->width;

//	printf("nn num =  %s, alloc_len = %d nn\n", num, alloc_len);
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
//	j = 0;
//	if (sp->precision)
//	{
//		while (j < sp->precision - len)
//		{
//			str[i] = '0';
//			j++;
//			i++;
//		}
//	}
	sp->precision = 1;
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
		while (i < sp->width)						 //j < sp->width - sp->precision)
		{
			str[i] = ' ';
			i++;
		//	j++;
		}
	}
//	printf("\n\nalloc_len : %d real_width : %d real_precision : %d sp->zero : %d sp->left : %d sp->minus : %d sp->width : %d sp->precision : %d sp->zero_precision %d sp->per_zero %d sp->per_left %d\n", alloc_len, real_width, real_precision, sp->zero, sp->left, sp->minus, sp->width, sp->precision, sp->zero_precision, sp->per_zero, sp->per_left);
	while (*str)
	{
		ft_putchar(*str, sp);
		str++;
	}
//	free(num);
}



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
//	printf("\n\nalloc_len : %d real_width : %d real_precision : %d sp->zero : %d sp->left : %d sp->minus : %d sp->width : %d sp->precision : %d sp->zero_precision %d\n", alloc_len, real_width, real_precision, sp->zero, sp->left, sp->minus, sp->width, sp->precision, sp->zero_precision);
	i = 0;
	if (!sp->left && !sp->zero)
	{
		while (i < sp->width - sp->precision)
		{
			str[i] = ' ';
			i++;
		}
//		printf("111 %d 111\n", i);
		if (sp->minus && i)
		{
			i--;
			if (i)
				i--;
		}
	}
//		printf("222 %d 222\n", i);
	if (sp->minus)
	{
		str[i] = '0';
		i++;
		str[i] = 'x';
		i++;
	}
//		printf("333 %d 333\n", i);
	if (sp->zero)
	{
		while (i < sp->width - len)
		{
			str[i] = '0';
			i++;
		}
	}
//		printf("444 %d 444\n", i);
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
//		printf("555 %d 555\n", i);
	j = 0;
	while (len--)
	{
		str[i] = num[j];
		i++;
		j++;
	}
//		printf("666 %d 666\n", i);
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
//		printf("777 %d 777\n", i);
	while (*str)
	{
		ft_putchar(*str, sp);
		str++;
	}
	free(num);
}

void				x_proccess(unsigned int x, spec *sp, char c)
{
	char			*num;
	char			*str;
	unsigned int	n;
	int				i;
	int				j;
	int				len;
	unsigned int	alloc_len;
	int				real_width;
	int				real_precision;

	n = x;
	if (c == 'x')
		num = ft_itoa_base(n, 'x');
	else
		num = ft_itoa_base(n, 'X');

	real_width = sp->width;
	real_precision = sp->precision;
	len = ft_strlen(num);
	if (real_precision < len && real_precision != 0)
		sp->zero = 0;
	if (x == 0 && sp->zero_precision)
		len = 0;

	if (sp->precision < len)
		sp->precision = len;
	if (sp->width < sp->precision)
		sp->width = sp->precision;

	if (sp->minus && (real_width < len || real_width < real_precision))
		alloc_len = sp->width + 1;
	else
		alloc_len = sp->width;

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
	if (sp->left)
	{
		j = 0;
		if (sp->minus)
			j++;
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

void				u_proccess(unsigned int u, spec *sp)
{
	char			*num;
	char			*str;
	unsigned int	n;
	int				i;
	int				j;
	int				len;
	unsigned int	alloc_len;
	int				real_width;
	int				real_precision;

	n = u;
	num = ft_itoa(n);

	real_width = sp->width;
	real_precision = sp->precision;
	len = ft_strlen(num);
	if (real_precision < len && real_precision != 0)
		sp->zero = 0;
	if (u == 0 && sp->zero_precision)
		len = 0;

	if (sp->precision < len)
		sp->precision = len;
	if (sp->width < sp->precision)
		sp->width = sp->precision;

	if (sp->minus && (real_width < len || real_width < real_precision))
		alloc_len = sp->width + 1;
	else
		alloc_len = sp->width;

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
	if (sp->left)
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
void				width_check(const char **form, va_list ap, spec *sp)
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

void				precision_check(const char **form, va_list ap, spec *sp)
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
		sp->s_num = -num;
		num = 0;
//		sp->zero_precision = 1;
		sp->minus_precision = 1;
	}
	else if (num == 0)
		sp->zero_precision = 1;
	else
		sp->s_num = num;
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

int				ft_parcel(const char **form, va_list ap, spec *sp)	
{

	(*form)++;
//	printf("parcel 1 !!! & **form = %c \n", **form);
	while (**form == '-' || **form == '0')
	{
		if (**form == '-')								// left
			sp->left = 1;
		if (**form == '0')								// zero
		{
			sp->zero = 1;
			sp->per_zero = 1;
		}
		(*form)++;
	}
	if ((**form >= '0' && **form <= '9') || **form == '*')
		width_check(form, ap, sp);					// width
	if (**form == '.')
	{
		(*form)++;
		precision_check(form, ap, sp);					// precision
	}
	else
		sp->empty_precision = 1;
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
	{
		sp->zero = 0;
		sp->per_zero = 0;
	}
//	return (NULL);
	return (ft_parcel2(form, ap, sp));
}

int				ft_parcel2(const char **form, va_list ap, spec *sp)
{
//	printf("parcel2!!!\n**form!! = %c\n", **form);
	if (**form == 'd' || **form == 'i')	
	{
		d_proccess(va_arg(ap, int), sp);
//		printf("d,i!!!!\n");
	}
	else if (**form == 's')
		s_proccess(va_arg(ap, char *), sp);			// ??????????
	else if (**form == 'p')
		p_proccess(va_arg(ap, long long int), sp);
	else if (**form == 'c')
	{
//		printf("ccc");
		c_proccess(va_arg(ap, int), sp);
	}
	else if (**form == 'u')
		u_proccess(va_arg(ap, unsigned int), sp);
	else if (**form == 'x')
		x_proccess(va_arg(ap, unsigned int), sp, 'x');
	else if (**form == 'X')
		x_proccess(va_arg(ap, unsigned int), sp, 'X');
	else if (**form == '%')							// %%가 들어오는 경우
		per_proccess(sp);
	else
	{
		return (-1);
	}
//	printf("555 %c\n", **form);
//	printf("parcel2 end!!+\n");
	return (0);
}

int					ft_printf(const char *format, ...)
{
	va_list			ap;
	spec			sp;
//	char			*str;

//	str = (char *)format;
	va_start(ap, format);
	init_spec(&sp);
//	printf("\nsss %s sss\n", str);
	while (*format)
	{
//		printf("ccc %c ccc\n", *str);
		if (*format == '%')
		{
			if (ft_parcel(&format, ap, &sp) == -1)
			{
//				if (str = NULL)
//					printf("zzz");
//				printf("1231231");
				return (-1);
			}
			
		}
		else
			ft_putchar(*format, &sp);
//		printf("ddd %c ddd\n", *str);
		format++;


	}
//	printf("zero : %d, left : %d, width : %d, precision : %d, minus : %d, count :  %d\n", sp.zero, sp.left, sp.width, sp.precision, sp.minus, sp.count);
	va_end(ap);
//	printf("width & precision & left_flag & zero & minus & zero_precision\n%d %d %d %d %d %d\n", sp.width, sp.precision, sp.left, sp.zero, sp.minus, sp.zero_precision);
	return (sp.count);
}

//	/*
int		main(void)
{

	printf("%ld\n", -2147483648);
	ft_printf("%d\n", -2147483648);

	return (0);
}
//	 */
