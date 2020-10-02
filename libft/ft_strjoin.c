#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len1;
	int		len2;
	int		i;
	int		j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if(!(str = (char *)malloc(sizeof(char) * (s1 + s2 + 1))))
		return (NULL);
	i = 0;
	while(i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	i = len1;
	j = 0;
	while(j < len 2)
	{
		str[i] = s1[j];
		i++;
		j++;
	}
	return (str);
}
