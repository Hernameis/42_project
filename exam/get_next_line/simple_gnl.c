#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_charappend(char *line, char buff)
{
	int i = 0;
	char *result;

	if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(line) + 2))))
		return (NULL);
	while (line[i])
	{
		result[i] = line[i];
		i++;
	}
	result[i] = buff;
	i++;
	result[i] = 0;
	free(line);
	return (result);
}

int get_next_line(char **line)
{
	int n;
	char buff;						// 어차피 버퍼사이즈가 1이기 때문에 buff는 char *가 아니라 char로 선언
	if (!(*line = malloc(1)))
		return (-1);
	(*line)[0] = 0;
	while ((n = read(0, &buff, 1)) > 0)
	{
		if (buff == '\n')
			return (1);
		*line = ft_charappend(*line, buff);
		if (!*line)
			return (0);
	}
	if (n == -1)
		return (-1);
	return (0);
}
