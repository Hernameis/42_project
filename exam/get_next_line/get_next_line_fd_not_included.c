#include <unistd.h>
#include <stdlib.h>

size_t ft_strlen(char *s)
{
	size_t i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	unsigned int i = 0, leng;
	if (!str)
		return (NULL);
	leng = ft_strlen(str);
	while (*str != '\0' && *str != c)
	{
		str++;
		i++;
	}
	if (*str != c && i == leng)
		return (NULL);
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char *dest;
	int i = 0;
	if (!(dest = malloc(ft_strlen(s1)+ ft_strlen(s2) + 1)))
		return (NULL);
	while (*s1 != '\0')
		dest[i++] = *s1++;
	while (*s2!= '\0')
		dest[i++] = *s2++;
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *str)
{
	int i = 0;
	char *dest;
	if (!(dest = malloc(ft_strlen(str) + 1)))
		return (NULL);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		get_next_line(int fd, char **line)
{
	static char *remain[4096];
	char		*buff;
	char		*temp;
	int			n;

	if (fd < 0 || fd > 4096 || !line)											// 예외 처리
		return (-1);
	if (!(buff = (char *)malloc(sizeof(char) * 2)))								// 동적할당
		return (-1);
	if (remain[fd] == NULL)
		remain[fd] = ft_strdup("");												// 빈문자열 복사
	while (!(temp = is_new(remain[fd], '\n')) && (n = read(fd, buff, 2)) > 0)	// 개행을 안만났거나, 읽은 값이 있을 때
	{
		buff[n] = '\0';									// buff의 마지막을 널문자로 바꾸고
		temp = ft_strjoin(remain[fd], buff);			// temp에 리메인에다 버프를 갖다 붙인 걸 복사하고
		free(remain[fd]);								// 리메인은 프리해주고
		remain[fd] = temp;								// 다시 리메인이 템프를 가리키게 한다
	}
	free(buff);											// 이제는 프리도 필요 없으니까 버프해줌
	if (n < 0)											// 만약에 n이 0보다 작으면 -1을 리턴해준다
		return (-1);
	return (push_gnl(&remain[fd], temp, line));
}

static int	push_gnl(char **remain, char *temp, char **line)
{
	char	*next;

	if (temp)		// 개행이 있는 경우
	{
		*temp = '\0';
		*line = ft_strdup(*remain);
		next = ft_strdup(temp + 1);
		free(*remain);
		*remain = next;
		return (1);
	}
	if (*remain)	// eof인 경우
	{
		*line = ft_strdup(*remain);
		free(*remain);
		*remain = NULL;
	}
	else			// remain에 남은게 없는 경우
		*remain = ft_strdup("");
	return (0);
}
