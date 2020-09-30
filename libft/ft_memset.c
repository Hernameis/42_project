#include "libft.h"

void	*memset(void *ptr, int value, size_t n)
{
	int i;

	i = 0;
	while(i < n)
	{
		ptr[i] = (int)value;
		i++;
	}
	return (ptr);
}
