/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 13:47:26 by sunmin            #+#    #+#             */
/*   Updated: 2020/11/14 15:42:01 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_printf(const char *fomat, ...);


int		main(void)
{

	ft_printf("[%*.*%]\n", 2, -4);
	printf("[%*.*%]\n", 2, -4);
//	while (1)
//		;
	return (0);
}
