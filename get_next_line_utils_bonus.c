#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!s2)
		return (NULL);
	else
	{
		while (s1[i])
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
		return (s2);
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*str;
	int lena;

	lena = ft_strlen(s1);
	if (!s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (lena + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2 && s2[i] != '\0')
	{
		str[lena + i] = s2[i];
		i++;
	}
	str[lena + i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == (char)c)
			return ((char *)s - 1);
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;
	size_t	subs_len;
	size_t	n;

	if (!s)
		return (NULL);
	subs_len = ft_strlen(s) - start;
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (subs_len <= len)
		subs = (char *)malloc(sizeof(char) * (subs_len + 1));
	else
		subs = (char *)malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (NULL);
	i = start;
	n = 0;
	while (i < ft_strlen(s) && n < len)
	{
		subs[n++] = s[i++];
	}
	subs[n] = '\0';
	return (subs);
}
