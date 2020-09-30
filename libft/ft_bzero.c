#include "libft.h"

void	ft_bzero(void *ptr, size_t size)
{
	int i;

	i = 0;
	while(i < size)
	{
		ptr[i] = 0;
		i++;
	}
}
