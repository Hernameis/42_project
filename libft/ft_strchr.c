#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while(*s != c)
		s++;
	if (!*s)
		return ('\0');
	return (s);
}
