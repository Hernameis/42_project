/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_proccess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 10:02:04 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/13 17:08:45 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			u_widpre(t_spec *sp, int *len,
		unsigned int *alloc_len, unsigned int u)
{
	if (sp->real_precision < *len && sp->real_precision != 0)
		sp->zero = 0;
	if (u == 0 && sp->zero_precision)
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

static void			u_write(t_spec *sp, int *len, char **str, char **num)
{
	if (sp->minus)
		(*str)[(sp->i)++] = '-';
	if (sp->zero)
		while (sp->i < sp->width - *len)
			(*str)[(sp->i)++] = '0';
	if (sp->precision)
	{
		while ((sp->j)++ < sp->precision - *len)
			(*str)[(sp->i)++] = '0';
	}
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

static void			u_free(char **str, char **num)
{
	free(*str);
	*str = NULL;
	free(*num);
	*num = NULL;
}

void				u_proccess(unsigned int u, t_spec *sp)
{
	char			*num;
	char			*str;
	unsigned int	n;
	int				len;
	unsigned int	alloc_len;

	n = u;
	num = ft_itoa(n);
	sp->real_width = sp->width;
	sp->real_precision = sp->precision;
	len = ft_strlen(num);
	u_widpre(sp, &len, &alloc_len, u);
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
	u_write(sp, &len, &str, &num);
	u_free(&str, &num);
}
