#include "libft.h"

char *ft_strrchr(char *s, char c)
{
	while(*s)
		s++;
	while(*s != c)
		s--;
	s++;
	if (*s == s[0])
		return ('\0')
	return (s);
}
