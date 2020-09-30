#include "libft.h"

void	*memechr(const void* ptr, int value, size_t n)
{
	int i;

	i = 0;
	while(i < n)
	{
		if ((int)*ptr != value)
		{
			(int)*ptr = value;
			ptr++;
		}
		i++;
	}
}
