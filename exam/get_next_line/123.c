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


// 그니까 이 함수가 머냐면,
// line과 buff를 붙이는 문자열을 만드는 함수다 이말이야
// 0. result 만들고
// 1. 거기에 malloc하고
// 2. line 붙이고
// 3. buff 붙이고
// 4. null 붙이고
// 5. line free 하면
// 6. 리턴하고 끝
char	*ft_charappend(char *line, char buff)
{
	int		i = 0;
	char	*result;

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


// *line에 1 malloc (buffsize만큼)
//	read값이 0보다 클동안 계속 리드하면서
//	buff가 개행이면 1리턴
//	라인에 버프를 붙이고
//	라인이 없으면 0리턴
//	n이 -1이면 -1리턴

int		get_next_line(char **line)
{
	int		n;
	char	buff;

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
