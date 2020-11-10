/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:25:21 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/10 11:22:43 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include "./libft/libft.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	specifier
{
	int			zero;
	int			per_zero;
	int			left;
	int			minus;
	int			width;
	int			precision;
	int			zero_precision;
	int			count;
	int			s_num;
	int			minus_precision;
	int			empty_precision;
}				spec;

void			ft_putchar(char c, spec *sp);
void			init_spec(spec *sp);
void			d_proccess(int d, spec *sp);
int				ft_parcel(const char **form, va_list ap, spec *sp);
int				ft_parcel2(const char **form, va_list ap, spec *sp);
int				ft_printf(const char *format, ...);
void			width_check(const char **form, va_list ap, spec *sp);
void			precision_check(const char **form, va_list ap, spec *sp);
char			*ft_itoa_base(long long n, char x);

#endif
