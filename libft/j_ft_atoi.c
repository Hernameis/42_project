/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: begrey <begrey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 16:55:59 by begrey            #+#    #+#             */
/*   Updated: 2020/10/06 17:51:22 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char* str)
{
    int i;
    int minus;
    int total;

    i = 0;
    minus = 0;
    total = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-')
    {
        minus = 1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    if (str[i] !='\0' && (str[i] >= '0' && str[i] <= '9'))
        total += str[i++] - '0';
    while (str[i] !='\0' && (str[i] >= '0' && str[i] <= '9'))
    {
        total *= 10;
        total += str[i] - '0';
        i++;
    }
    if (minus == 1)
        total *= -1;
    return (total);
}
