/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_proccess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 10:01:45 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/13 16:16:30 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			p_0x(t_spec *sp, char **str, int *len)
{
	if (!sp->left && !sp->zero)
	{
		while (sp->i < sp->width - sp->precision)
			(*str)[(sp->i)++] = ' ';
		if (sp->minus && sp->i)
		{
			sp->i--;
			if (sp->i)
				sp->i--;
		}
	}
	if (sp->minus)
	{
		(*str)[sp->i] = '0';
		sp->i++;
		(*str)[sp->i] = 'x';
		sp->i++;
	}
	if (sp->zero)
	{
		while (sp->i < sp->width - *len)
			(*str)[(sp->i)++] = '0';
	}
}

static void			p_w(t_spec *sp, int *len, unsigned int *a_l,
		long long int p)
{
	if (sp->real_precision < *len && sp->real_precision != 0)
		sp->zero = 0;
	if (p == 0 && sp->zero_precision)
		*len = 0;
	if (sp->precision < *len)
		sp->precision = *len;
	if (sp->width < sp->precision)
		sp->width = sp->precision;
	if (sp->minus && (sp->real_width < *len ||
		sp->real_width < sp->real_precision))
		*a_l = sp->width + 2;
	else
		*a_l = sp->width;
}

static void			p_write(int *len, char **str, t_spec *sp, char **num)
{
	int				i;

	while ((*len)--)
		(*str)[(sp->i)++] = (*num)[(sp->j)++];
	if (sp->left)
	{
		sp->j = 0;
		if (sp->minus)
		{
			(sp->j)++;
			(sp->j)++;
		}
		while ((sp->j)++ < sp->width - sp->precision)
			(*str)[(sp->i)++] = ' ';
	}
	i = 0;
	while ((*str)[i])
		ft_putchar((*str)[i++], sp);
	free(*str);
	*str = NULL;
}

void				p_proccess(long long int p, t_spec *sp)
{
	char			*num;
	char			*str;
	long long int	n;
	int				len;
	unsigned int	a_l;

	n = p;
	num = ft_itoa_base(n, 'p');
	sp->minus = 1;
	sp->real_width = sp->width;
	sp->real_precision = sp->precision;
	len = ft_strlen(num);
	p_w(sp, &len, &a_l, p);
	if (!(str = (char *)malloc(sizeof(char) * (a_l + 1))))
		return ;
	str[a_l] = '\0';
	p_0x(sp, &str, &len);
	if (sp->precision)
		while ((sp->j)++ < sp->precision - len)
			str[(sp->i)++] = '0';
	p_write(&len, &str, sp, &num);
}
