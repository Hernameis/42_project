#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int i;

	i = 0;
	while(i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0'
	return (dest);
}
