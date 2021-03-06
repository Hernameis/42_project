/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunmin <msh4287@naver.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 09:07:34 by sunmin            #+#    #+#             */
/*   Updated: 2021/04/24 09:43:36 by sunmin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int		ft_strlen(char *s);
char	*ft_strcpy(char *dst, char *src);
int		ft_strcmp(char *dst, char *src);
char	*ft_strdup(char *s);
int		ft_read(int fd, char *buff, size_t	count);
ssize_t	ft_write(int fd, void *buf, size_t nbytes);

int		main(void)
{
	char *a;
	char *b;

	char s1[10] = "1234567890";
	char s2[10] = "1234567899";
	char s3[0] = "";
	char s4[1] = "1";
	char s5[2] = "11";
	char s6[2] = "12";
	char s7[2] = "13";
	char s8[3] = "123";

	a = malloc(100);
	printf("ft_strlen(1234) =  %d\n", ft_strlen("1234"));
	printf("\n");
	printf("ft_strcpy(1234) = %s\n", ft_strcpy(a, "1"));
	printf("ft_strcpy(1234) = %s\n", ft_strcpy(a, "12"));
	printf("ft_strcpy(1234) = %s\n", ft_strcpy(a, "123"));
	printf("ft_strcpy(1234) = %s\n", ft_strcpy(a, "1234"));
	printf("\n");
	printf("ft_strcmp(1234567890, 1234567899) = %d\n", ft_strcmp(s1, s2));
	printf("ft_strcmp( , 1) = %d\n", ft_strcmp(s3 ,s4));
	printf("ft_strcmp(1 , ) = %d\n", ft_strcmp(s4 ,s3));
	printf("ft_strcmp( , ) = %d\n", ft_strcmp(s3 ,s3));
	printf("ft_strcmp(11 , 12) = %d\n", ft_strcmp(s5 ,s6));
	printf("ft_strcmp(13 , 12) = %d\n", ft_strcmp(s7 ,s6));
	printf("ft_strcmp(13 , 123) = %d\n", ft_strcmp(s7 ,s8));
	printf("ft_strcmp(123 , 13) = %d\n", ft_strcmp(s8 ,s7));
	printf("ft_strcmp(12, 12) = %d\n", ft_strcmp(s2, s2));
	printf("ft_strcmp(12, 12) = %d\n", ft_strcmp("12", "12"));
	printf("ft_strcmp(\\xfe, \\xff), strcmp(\\xfe, \\xff) %d %d\n", ft_strcmp("\xfe", "\xff"), strcmp("\xfe", "\xff"));
	char *s = "\xfe";
	char *ss = "\xff";
	printf("strcmp : %d xfe = %d , xff = %d\n", strcmp("\xfe", ""), *s, *ss);

	printf("\n");
	b = ft_strdup("123");
	printf("ft_strdup(123) = %s\n", b);

	ft_write(1, "1234a\n", 6);

	return (0);
}
