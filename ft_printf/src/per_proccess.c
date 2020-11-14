/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   per_proccess.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 10:02:27 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/14 15:43:59 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			per_write(t_spec *sp, int *len, char **str)
{
	if (sp->minus)
		(*str)[(sp->i)++] = '%';
	if (sp->per_zero)
	{
		while (sp->i < sp->width - *len)
			(*str)[(sp->i)++] = '0';
	}
	sp->precision = 1;
	while ((sp->j)++ < 1)
		(*str)[(sp->i)++] = '%';
	if (sp->left)
	{
		sp->j = 0;
		if (sp->minus)
			(sp->j)++;
		while (sp->i < sp->width)
			(*str)[(sp->i)++] = ' ';
	}
	sp->i = 0;
	while ((*str)[sp->i])
		ft_putchar((*str)[(sp->i)++], sp);
}

void				per_proccess(t_spec *sp)
{
	char			*num;
	char			*str;
	int				len;
	int				alloc_len;

	num = "%";
	sp->real_width = sp->width;
	sp->real_precision = sp->precision;
	len = 1;
	if (sp->precision < len)
		sp->precision = len;
	alloc_len = len;
	if (!(str = (char *)malloc(sizeof(char) * (alloc_len + 1))))
		return ;
	str[alloc_len] = '\0';
	if (!sp->left && !sp->per_zero)
	{
		while (sp->i < sp->width - 1)
			str[(sp->i)++] = ' ';
		if (sp->minus && sp->i)
			(sp->i)--;
	}
	per_write(sp, &len, &str);
}
