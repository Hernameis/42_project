#include <unistd.h>
#include <stdlib.h>

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
	char	*result;
	int		i;

	if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(line) + 2))))
		return (-1);
	i = 0;
	while (line[i])
	{
		result[i] = line[i];
		i++;
	}
	result[i] = buff;
	i++;
	result[i] = '\0';
	free(line);			//  혹시 모르니까 free는 마지막에 하도록 하자
	return (result);
}

int		get_next_line(char **line)
{
	char	buff;
	int		n;

	if (!(*line = (char *)malloc(1)))
		return (-1);
	(*line)[0] = '\0';						// *line에 괄호 잘 하기
	while ((n = read(1, &buff, 1)) > 0)		// read의 첫번째 인자는 0으로 해야함
	{
		if (buff == '\n')
			return (1);
		*line = ft_append(*line, buff);
		if (!line)
			return (0);
	}
	if (n < 0)
		return (-1);
	return (0);
}
