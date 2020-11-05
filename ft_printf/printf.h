/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:25:21 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/05 15:28:21 by sunmin           ###   ########.fr       */
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
	int			left;
	int			minus;
	int			width;
	int			precision;
	int			count;
}				spec;

void			ft_putchar(char c, spec *sp);
void			init_spec(spec *sp);
void			d_proccess(int d, spec *sp);
char			**ft_parcel(char **form, va_list ap, spec *sp);
char			**ft_parcel2(char **form, va_list ap, spec *sp);
int				ft_printf(const char *format, ...);
void			width_check(char **form, va_list ap, spec *sp);
void			precision_check(char **form, va_list ap, spec *sp);

#endif
