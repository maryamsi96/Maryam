#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char	*get_next_line(int fd);
char	*get_next(char	*str);
char    *get_current(char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

#endif