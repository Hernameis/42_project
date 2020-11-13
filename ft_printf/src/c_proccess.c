/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_proccess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 10:01:25 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/13 17:08:59 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			width_precision(t_spec *sp, int *len, int *alloc_len)
{
	if (sp->precision < *len)
		sp->precision = *len;
	if (sp->width < sp->precision)
		sp->width = sp->precision;
	*alloc_len = sp->width;
}

static void			c_flags(t_spec *sp, char **str, char c)
{
	if (!sp->left && !sp->per_zero)
	{
		while (sp->i < sp->width - 1)
		{
			(*str)[sp->i] = ' ';
			(sp->i)++;
		}
		if (sp->minus && sp->i)
			(sp->i)--;
	}
	if (sp->minus)
	{
		(*str)[sp->i] = c;
		(sp->i)++;
	}
	if (sp->per_zero)
	{
		while (sp->i < sp->width - 1)
		{
			(*str)[sp->i] = '0';
			(sp->i)++;
		}
	}
}

static void			c_write(char **str, t_spec *sp)
{
	if (sp->left)
	{
		sp->j = 0;
		if (sp->minus)
			sp->j++;
		while (sp->i < sp->width)
		{
			(*str)[sp->i] = ' ';
			(sp->i)++;
		}
	}
	sp->i = 0;
	while (sp->i < sp->width)
		ft_putchar((*str)[(sp->i)++], sp);
	free(*str);
	*str = NULL;
}

void				c_proccess(char c, t_spec *sp)
{
	char			*str;
	int				len;
	int				alloc_len;

	alloc_len = 0;
	len = 1;
	width_precision(sp, &len, &alloc_len);
	if (!(str = (char *)malloc(sizeof(char) * (alloc_len + 1))))
		return ;
	str[alloc_len] = '\0';
	c_flags(sp, &str, c);
	sp->precision = 1;
	while (sp->j < 1)
	{
		str[sp->i] = c;
		sp->i++;
		sp->j++;
	}
	c_write(&str, sp);
}
