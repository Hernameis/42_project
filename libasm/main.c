/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:07:34 by sunmin            #+#    #+#             */
/*   Updated: 2021/04/12 14:00:29 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_strlen(char *s);
char	*ft_strcpy(char *s);

int		main(void)
{
	printf("ft_strlen(1234) =  %d\n", ft_strlen("1234"));
	printf("ft_strcpy(1234) = %s\n", ft_strcpy("1234"));
	return (0);
}
