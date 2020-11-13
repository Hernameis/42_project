/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_proccess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 09:46:12 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/13 11:39:59 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			d_widpre(t_spec *sp, int d, int *len, int *alloc_len)
{
	if (sp->real_precision < *len && sp->real_precision != 0)
		sp->zero = 0;
	if (d == 0 && sp->zero_precision)
		*len = 0;
	if (sp->precision < *len)
		sp->precision = *len;
	if (sp->width < sp->precision)
		sp->width = sp->precision;
	if (sp->minus && (sp->real_width < *len
				|| sp->real_width < sp->real_precision))
		*alloc_len = sp->width + 1;
	else
		*alloc_len = sp->width;
}

static void			d_writd(t_spec *sp, char **str, int *len, char **num)
{
	if (sp->minus)
		(*str)[(sp->i)++] = '-';
	if (sp->zero)
		while (sp->i < sp->width - *len)
			(*str)[(sp->i)++] = '0';
	sp->j = 0;
	if (sp->precision)
		while (sp->j++ < sp->precision - *len)
			(*str)[(sp->i)++] = '0';
	sp->j = 0;
	while ((*len)--)
		(*str)[(sp->i)++] = (*num)[(sp->j)++];
	if (sp->left)
	{
		sp->j = 0;
		if (sp->minus)
			(sp->j)++;
		while ((sp->j)++ < sp->width - sp->precision)
			(*str)[(sp->i)++] = ' ';
	}
	while (**str)
		ft_putchar(*((*str)++), sp);
}

static void			d_minus(t_spec *sp, int d, int *n, char **num)
{
	if (d < 0)
	{
		*n = -d;
		sp->minus = 1;
	}
	else
		*n = d;
	*num = ft_itoa(*n);
}

void				d_proccess(int d, t_spec *sp)
{
	char			*num;
	char			*str;
	int				n;
	int				len;
	int				alloc_len;

	d_minus(sp, d, &n, &num);
	sp->real_width = sp->width;
	sp->real_precision = sp->precision;
	len = ft_strlen(num);
	d_widpre(sp, d, &len, &alloc_len);
	if (!(str = (char *)malloc(sizeof(char) * (alloc_len + 1))))
		return ;
	str[alloc_len] = '\0';
	if (!sp->left && !sp->zero)
	{
		while (sp->i < sp->width - sp->precision)
			str[(sp->i)++] = ' ';
		if (sp->minus && sp->i)
			(sp->i)--;
	}
	d_writd(sp, &str, &len, &num);
	free(num);
}
