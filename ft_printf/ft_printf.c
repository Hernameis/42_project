/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:04:18 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/02 15:07:50 by sunmin           ###   ########.fr       */
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
}					p_flags;

void				ft_format(char *str, va_list ar)
{

}

int					ft_printf(const char *form, ...)
{

	va_list			ar;
	int				count;

	count = 0;
	va_start(ar, form);
	while (*form)
	{
		if (*form == '%')
		{
			ft_format(form, ar);
		}
		form++;
	}
	return (count);
}

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
