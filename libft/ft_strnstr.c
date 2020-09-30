#include "libft.h"

char *ft_strnstr(char *str, char *s, size_t len)
{
	int i;
	int j;
	int k;

	if (*s == '\0')
		return (str);
	i = 0;
	j = 0;
	k = 0;
	while (s[j])
	{
		if (str[i] != s[j])
			j++;
		else
		{
			while(str[i + k] == s[j + k])
				k++;
		}
	}
	if (str[i + k] == '\0' && s[j + k] == '\0')
		return (&str[i]);
	return ('\0');
}
