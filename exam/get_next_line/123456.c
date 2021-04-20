#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_append(char *line, char buff)
{
	int		i;
	char	*result;

	if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(line) + 2))))
		return NULL;
	i = 0;
	while (line[i])
	{
		result[i] = line[i];
		i++;
	}
	result[i] = buff;
	i++;
	result[i] = '\0';
	return (result);
}

int		get_next_line(char **line)
{
	int		n;
	char	buff;

	if (!(*line = (char *)malloc(1)))
		return (-1);
	(*line)[0] = '\0';
	while ((n = read(0, &buff, 1)) > 0)
	{
		if (buff == '\n')
			return (1);
		*line = ft_append(*line, buff);
		if (!*line)
			return (0);
	}
	if (n < 0)
		return (-1);
	return (0);
}
