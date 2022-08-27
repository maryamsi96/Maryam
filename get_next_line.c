#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char				*buf;
	int					read_value;
	char				*line;
	static char	*next = NULL;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	read_value = 1;
	while ((ft_strchr(next, '\n') == NULL) && read_value != 0)
	{
		read_value = read(fd, buf, BUFFER_SIZE);
		if (read_value <= 0)
			break ;
		buf[read_value] = '\0';
		next = ft_strjoin(next, buf);
	}
	free(buf);
	line = get_current(next);
	next = get_next(next);
	return (line);
}

char	*get_next(char *str)
{
	int		i;
	int		j;
	char	*result;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
		return (free(str), NULL);
	if (str[i])
		i++;
	result = malloc(sizeof(char) * ft_strlen(str + i) + 1);
	if (result == NULL)
		return (free(str), NULL);
	j = 0;
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}

char	*get_current(char *str)
{
	char	*result;
	int		i;

	if (str == NULL)
		return (NULL);
	result = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
		if (str[i - 1] == '\n')
			break ;
	}
	result[i] = '\0';
	return (result);
}

/*int main(void)
{
	char	*temp;
	int	fd;

	fd = open("test.txt", O_RDONLY);

	while(1)
	{
		temp = get_next_line(fd);
		if (!temp)
		break ;
		printf("%s", temp);
		free(temp);
	}
	return (0);
}*/