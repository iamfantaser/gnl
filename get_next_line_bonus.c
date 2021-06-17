#include "get_next_line_bonus.h"
 
static int check(char **tail, char **line, char **buf)
{
	char *tmp;
	char *n_ptr;
	
	tmp = NULL;
	free(*buf);
	n_ptr = ft_strchr(*tail, '\n');
	if (n_ptr)
	{
		*n_ptr = '\0';
		tmp = ft_strdup(++n_ptr);
	}
	free(*line);
	*line = ft_strdup(*tail);
	free(*tail);
	*tail = tmp;
	if (*tail)
		return (1);
	else 
	{
		free(*tail);
		*tail = NULL;
		return (0);
	}
}

int get_next_line(int fd, char **line)
{
	char *buf;
	int n;
	static char *tail[1024];
	char *n_ptr;
	char *tmp;
	
	if ((read(fd, 0, 0) < 0) || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	*line  = ft_strdup("");
	buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	n = 1;
	while (n)
	{
		n = read(fd, buf, BUFFER_SIZE);
		buf[n] = '\0';
		n_ptr = ft_strchr(buf, '\n');
		tmp = tail[fd];
		tail[fd] = ft_strjoin(tmp, buf);
		free (tmp);
		if (n_ptr)
			break ;
	}
	return (check(&tail[fd], line, &buf));
}

