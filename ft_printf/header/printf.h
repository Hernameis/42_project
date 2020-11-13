/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 14:25:21 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/13 09:41:55 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "../lib/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_spec
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
	int			real_width;
	int			real_precision;
	int			i;
	int			j;
}					t_spec;

int					ft_printf(const char *format, ...);
void				ft_putchar(char c, t_spec *sp);
void				init_spec(t_spec *sp);
char				*ft_itoa_base(long long n, char x);
void				c_proccess(char c, t_spec *sp);
void				d_proccess(int d, t_spec *sp);
void				p_proccess(long long int p, t_spec *sp);
void				s_proccess(char *s, t_spec *sp);
void				u_proccess(unsigned int u, t_spec *sp);
void				x_proccess(unsigned int x, t_spec *sp, char c);
void				per_proccess(t_spec *sp);
void				width_check(const char **form, va_list ap, t_spec *sp);
int					ft_parcel(const char **form, va_list ap, t_spec *sp);
int					ft_parcel2(const char **form, va_list ap, t_spec *sp);
int					ft_printf(const char *format, ...);
void				width_check(const char **form, va_list ap, t_spec *sp);
void				precision_check(const char **form, va_list ap, t_spec *sp);

#endif
