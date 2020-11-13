/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_proccess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 09:48:31 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/13 16:09:50 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			set_widpre(t_spec *sp, int *len, int *alloc_len, char *s)
{
	sp->real_width = sp->width;
	*len = ft_strlen(s);
	sp->real_precision = *len;
	if (sp->zero_precision && sp->s_num == 0)
		sp->real_precision = 0;
	else if (!sp->minus_precision && sp->s_num < *len)
		sp->real_precision = sp->s_num;
	else if (!sp->minus_precision && sp->s_num >= *len)
		sp->real_precision = *len;
	else if (sp->minus_precision && sp->s_num)
		sp->real_precision = *len;
	if (sp->empty_precision)
		sp->real_precision = *len;
	*alloc_len = sp->width;
	if (!sp->width)
		*alloc_len = sp->real_precision;
}

static void			s_flags(t_spec *sp, char **str, int *len)
{
	if (!sp->left && !sp->per_zero)
	{
		while (sp->i < sp->width - sp->real_precision)
			(*str)[(sp->i)++] = ' ';
		if (sp->minus && sp->i)
			(sp->i)--;
	}
	if (sp->per_zero)
	{
		while (sp->i < sp->width - *len)
		{
			(*str)[sp->i] = '0';
			(sp->i)++;
		}
	}
}

static void			s_write(t_spec *sp, char **str)
{
	int				i;

	if (sp->left)
	{
		sp->j = 0;
		if (sp->minus)
			(sp->j)++;
		while (sp->i < sp->width)
		{
			(*str)[sp->i] = ' ';
			(sp->i)++;
		}
	}
	i = 0;
	while ((*str)[i])
		ft_putchar((*str)[i++], sp);
	free(*str);
	*str = NULL;
}

void				s_proccess(char *s, t_spec *sp)
{
	char			*str;
	int				len;
	int				alloc_len;

	if (!s)
		s = ft_strdup("(null)");
	set_widpre(sp, &len, &alloc_len, s);
	if (!(str = (char *)malloc(sizeof(char) * (alloc_len + 1))))
		return ;
	str[alloc_len] = '\0';
	s_flags(sp, &str, &len);
	while (sp->j < sp->real_precision)
		str[sp->i++] = s[sp->j++];
	s_write(sp, &str);
}
