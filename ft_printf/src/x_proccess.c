/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_proccess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 10:02:17 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/13 17:08:54 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			x_check(unsigned int *n, unsigned int x, char c, char **num)
{
	*n = x;
	if (c == 'x')
		*num = ft_itoa_base(*n, 'x');
	else
		*num = ft_itoa_base(*n, 'X');
}

static void			x_write(t_spec *sp, int *len, char **str, char **num)
{
	if (sp->minus)
		(*str)[(sp->i)++] = '-';
	if (sp->zero)
	{
		while (sp->i < sp->width - *len)
			(*str)[(sp->i)++] = '0';
	}
	if (sp->precision)
		while ((sp->j)++ < sp->precision - *len)
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
	sp->i = 0;
	while ((*str)[sp->i])
		ft_putchar((*str)[(sp->i)++], sp);
}

static void			x_widpre(t_spec *sp, unsigned int x, int *len,
		unsigned int *alloc_len)
{
	if (sp->real_precision < *len && sp->real_precision != 0)
		sp->zero = 0;
	if (x == 0 && sp->zero_precision)
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

static void			x_free(char **str, char **num)
{
	free(*str);
	*str = NULL;
	free(*num);
	*num = NULL;
}

void				x_proccess(unsigned int x, t_spec *sp, char c)
{
	char			*num;
	char			*str;
	unsigned int	n;
	int				len;
	unsigned int	alloc_len;

	x_check(&n, x, c, &num);
	sp->real_width = sp->width;
	sp->real_precision = sp->precision;
	len = ft_strlen(num);
	x_widpre(sp, x, &len, &alloc_len);
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
	x_write(sp, &len, &str, &num);
	x_free(&str, &num);
}
