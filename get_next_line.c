/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaleh <msaleh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 19:30:13 by msaleh            #+#    #+#             */
/*   Updated: 2022/08/23 18:21:23 by msaleh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buf;
	int			read_value;
	char		*line;
	static char	*next;

	if (fd < 0 || BUFFER_SIZE < 0) //error = NULL
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf) //error = NULL
		return (NULL);
	read_value = 1;
	while (!(ft_strchr(next, '\n')) && read_value != 0)
	{
		read_value = read(fd, buf, BUFFER_SIZE);
		if (read_value <= 0) // error = NULL
			break ;
		buf[read_value] = '\0';
		next = ft_strjoin(next, buf); /*save the read characters in a static variable (strjoin the buffer to the static)*/
	}

	free(buf);
	line = get_current(next);
	next = get_next(next);
	return (line);
}

char	*get_next(char *str)
{
	char	*result;
	int		i;
	int		j;

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
	result = malloc(sizeof(char) * ft_strlen(str) + 2);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (str[i]) //looping read characters from str to memory
	{
		result[i] = str[i];
		i++;
		if (str[i - 1] == '\n')
			break ;
	}
	result[i] = '\0';
	return (result);
}

int main(void)
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
}
