#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	int		i;

	str = (void *)malloc(size * count);
	i = 0;
	while (i < count)
	{
		(int)str[i] = 0;
		i++;
	}
	return (str);
}
