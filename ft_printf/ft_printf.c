/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:04:18 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/03 14:22:36 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

typedef	struct		flags
{
	char			flag;
	int				width;
	int				precision;
	int				count;
}					p_flags;

void				ft_putchar(char c, p_flags *fl)			// write와 기능은 비슷한데
{															// 나중에 return할 값이 추가됨.
	write(1, &c, 1);
	(*fl).count++;
}

void				init_fl(p_flags *fl)					// 플래그 구조체 초기화.
{
		(*fl).flag = '\0';
		(*fl).width = 0;
		(*fl).precision = 0;
		(*fl).count = 0;
}

void				ft_d(char **str, int n, p_flags *fl)
{
	printf("%c\n", (*fl).flag);
	printf("%d\n %d\n %d\n", (*fl).width, (*fl).precision, (*fl).count);

}

char				**ft_format(char **str, va_list ap, p_flags *fl)
{
	int				res;

	res = 0;
	if (**str == '-' || **str == '0')						// 플래그를 넣고
	{
		if (**str == '-')
			(*fl).flag = '-';
		else
			(*fl).flag = '0';
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')					// 폭 넣고
	{
		res = (res * 10) + **str - '0';
		(*str)++;
	}
	(*fl).width = res;
	if (**str == '.')										// . 건너뛰고
		(*str)++;
	res = 0;
	while (**str >= '0' && **str <= '9')					// 정밀도 넣고
	{
		res = (res * 10) + **str - '0';
		(*str)++;
	}
	(*fl).precision = res;
	if (**str == 'd' || **str == 'i')						// 서식 지정자에 따라 다르게 넣어줌.
		ft_d(str, va_arg(ap, int), fl);
/*	else if (**str == 'c')
		ft_c(str, va_arg(ap, char));
	else if (**str == 's')
		ft_s(str, va_arg(ap, char));		// char가 아닐 것 같음
	else if (**str == 'p')
		ft_p(str, va_arg(ap, char *));
	else if (**str == 'u')
		ft_u(str, va_arg(ap, int));
	else if (**str == 'x')
		ft_x(str, va_arg(ap, int));
	else if (**str == 'X')
		ft_xx(str, va_arg(ap, int));
	else
*/
		return NULL;
}

int					ft_printf(const char *form, ...)		// while문으로 돌려서
{															// %가 있을때와 없을때로 나눔.
	va_list			ap;
	int				count;
	char			**str;
	p_flags			fl;

	init_fl(&fl);
	*str = (char *)form;
	va_start(ap, form);
	while (**str)
	{
		if (**str == '%')
		{
			ft_format(str, ap, &fl);
		}
		else
			ft_putchar(**str, &fl);
		(*str)++;
	}
	printf("ft_return value : %d\n", fl.count);
	return (fl.count);
}




int					main(void)
{
	printf("Hello%7.3dWorld\n", 5);
	printf("==================\n");
	printf("printf(\"print%%%%%%dta\\\\n\", 5);\n");
	printf("prin%%%dta\n", 5);
	ft_printf("prin%%%dta\n", 5);
	printf("==================\n");

	printf("printf(\"%%%%\\n\");\n");
	printf("%%\n");
	ft_printf("%%\n");
	printf("==================\n");

	printf("printf\"movemove\\n\");\n");
	printf("movemove\n");
	ft_printf("movemove\n");
	printf("==================\n");

	printf("printf(\"%%d\\n\", 5);\n");
	printf("%d\n", 5);
	ft_printf("%d\n", 5);
	printf("==================\n");

	printf("printf(\"%%+d\\n\", 5);\n");
	printf("%+d\n", 5);
	ft_printf("%+d\n", 5);
	printf("==================\n");

	printf("printf(\"%%+5d\\n\", 5);\n");
	printf("%+5d\n", 5);
	ft_printf("%+5d\n", 5);
	printf("==================\n");

	printf("printf(\"%%+7.2d\\n\", 5);\n");
	printf("%+7.2d\n", 5);
	ft_printf("%+7.2d\n", 5);
	printf("==================\n");

	return (0);
}
