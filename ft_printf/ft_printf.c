/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 13:04:18 by sunmin            #+#    #+#             */
/*   Updated: 2020/10/30 17:26:49 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

char		*ft_format(const char *s)
{
	char	*str;

	str = NULL;
	return (str);
	str = (char *)s;
}

int			ft_printf(const char *form, ...)
{
	char	*s;

	s = (char *)form;
	while (*s)
	{
		if (*s == '%')
			ft_format(s);
		form++;
	}
	return (ft_strlen(form));
	form = NULL;
}

int			main(void)
{
	int		i;

	i = 0;
	printf("Including %%  : ");
	printf("%s %d\n", "printf ", i);
	printf("Not including %%  : ");
	ft_printf("%s %d\n", "ft_printf ", i);

	printf("abcdefg\n");
	ft_printf("abcdefg\n");
	return (0);
}
