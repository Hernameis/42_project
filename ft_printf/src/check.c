/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 10:43:58 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/12 13:54:13 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			num_proccess(const char **form, int *i, int *j)
{
	while (**form >= '0' && **form <= '9')
	{
		(*form)++;
		(*i)++;
	}
	*j = 0;
	while (*j < *i)
	{
		(*form)--;
		(*j)++;
	}
}

void				sub_width(const char **form, int *i, int *num, t_spec *sp)
{
	int				j;

	sp->width = *num;
	j = 0;
	while (j < *i)
	{
		(*form)++;
		(j)++;
	}
}

void				width_check(const char **form, va_list ap, t_spec *sp)
{
	int				i;
	int				j;
	int				num;
	char			*tmp;

	num = 0;
	tmp = NULL;
	i = 0;
	if (**form == '*')
	{
		num = va_arg(ap, int);
		(*form)++;
	}
	else
	{
		num_proccess(form, &i, &j);
		tmp = ft_substr(*form, 0, i);
		num = ft_atoi(tmp);
	}
	if (num < 0)
	{
		sp->left = 1;
		num = -num;
	}
	sub_width(form, &i, &num, sp);
}

void				sub_precision(int *num, t_spec *sp)
{
	if (*num < 0)
	{
		sp->s_num = -*num;
		*num = 0;
		sp->minus_precision = 1;
	}
	else if (*num == 0)
		sp->zero_precision = 1;
	else
		sp->s_num = *num;
	sp->precision = *num;
}

void				precision_check(const char **form, va_list ap, t_spec *sp)
{
	int				i;
	int				j;
	int				num;
	char			*tmp;

	i = 0;
	if (**form == '*')
	{
		num = va_arg(ap, int);
		(*form)++;
	}
	else
	{
		num_proccess(form, &i, &j);
		tmp = ft_substr(*form, 0, i);
		num = ft_atoi(tmp);
	}
	sub_precision(&num, sp);
	j = 0;
	while (j < i)
	{
		(*form)++;
		j++;
	}
}
