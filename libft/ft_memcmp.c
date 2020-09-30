#include "libft.h"

int		ft_memcmp(void *src1, void *src2, size_t n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (src1[i] > src2[i])
			return (1);
		else if (src1[i] < src2[i])
			return (-1);
		i++;
	}
	return (0);
}
