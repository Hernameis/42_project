#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;
	int		i;

	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char * len + 1));
	while (i < len)
	{
		str[i] = s[i]
		i++;
	}
	str[i] = '\0';
	return (str);
}
