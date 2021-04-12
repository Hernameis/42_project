/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:07:34 by sunmin            #+#    #+#             */
/*   Updated: 2021/04/12 14:48:45 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *s);
char	*ft_strcpy(char *dst, char *src);

int		main(void)
{
	char *a;

	a = malloc(100);
	printf("ft_strlen(1234) =  %d\n", ft_strlen("1234"));
	ft_strcpy(a, "1");
	printf("%s\n",a);
	printf("ft_strcpy(1234) = %s\n", ft_strcpy(a, "1"));
	printf("ft_strcpy(1234) = %s\n", ft_strcpy(a, "12"));
	printf("ft_strcpy(1234) = %s\n", ft_strcpy(a, "123"));
	printf("ft_strcpy(1234) = %s\n", ft_strcpy(a, "1234"));
	return (0);
}
