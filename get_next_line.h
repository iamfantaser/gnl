#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <stdlib.h>
#if defined(__unix__)
	# include <unistd.h>
#else
	# include <io.h>
# endif
# ifndef BUFFER_SIZE
	#define BUFFER_SIZE 64
# endif

int get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);

#endif
