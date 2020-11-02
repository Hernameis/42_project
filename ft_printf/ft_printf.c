/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:04:18 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/02 16:53:01 by sunmin           ###   ########.fr       */
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

void				ft_putchar(char c, p_flags *fl)
{
	write(1, &c, 1);
	fl->count++;
}

char				*ft_format(char *str, va_list ar, p_flags *fl)
{
	while (*str != 'd')
	{
		ft_flag(&str, ar, &fl);
		str++;
		fl->count++;
	}
	return (str);
}

int					ft_printf(const char *form, ...)
{
	va_list			ap;
	int				count;
	char			*str;
	p_flags			fl;

	str = (char *)form;
	fl.count = 0;
	va_start(ap, form);
	while (*str)
	{
		if (*str == '%')
		{
			ft_format(str, ap, &fl);
		}
		else
			ft_putchar(*str, &fl);
		str++;
	}
	printf("return value : %d\n", fl.count);
	return (fl.count);
}

/*
int					main(void)
{
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
