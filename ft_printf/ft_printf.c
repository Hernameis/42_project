/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:04:18 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/01 15:55:27 by sunmin           ###   ########.fr       */
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
	char			*width;
	char			*precision;
}					p_flags;

void			ft_format(int n)
{
//	p_flags		fl;
	char		*str;

	str = ft_itoa(n);
	write(1, str, ft_strlen(str));
	return ;
}

int				ft_printf(const char *form, ...)
{
	va_list		ap;

	va_start(ap, form);
	while (*form)
	{
		if (*form == '%')
		{
			if (*form == '%' && *(form + 1) == '%')
			{
				write(1, "%", 1);
			}
			else if (*form == '%' && *(form + 1) == 'd')
			{
				ft_format(va_arg(ap, int));
			}
			form++;
		}
		else
			write(1, form, 1);
		form++;
	}
	va_end(ap);
	return (0);
}

int				main(void)
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
