#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub;
	int i;
	int j;

	if(!(sub = (char *)malloc(sizeof(char) * (len - strat))))
		return (NULL);
	i = 0;
	j = start;
	while (start < len)
	{
		sub[i] = s[j];
		i++;
		j++;
	}
	return (sub);
}
