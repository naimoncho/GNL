#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	aux;

	aux = 0;
	while (str[aux] != '\0')
	{
		aux ++;
	}
	return (aux);
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	to_find;

	to_find = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == to_find)
			return ((char *)&s[i]);
		i ++;
	}
	if (to_find == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
void	*ft_calloc(size_t nmemb, size_t size)
{
	int		i;
	char	*copy;

	copy = malloc(nmemb * size);
	if (copy == NULL)
		return (NULL);
	while (copy[i] != '\0')
	{
		copy[i] = '0';
		i ++;
	}
	return (copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = ft_strlen(s);
	if (!s || start >= j || len == 0)
		return (ft_strdup(""));
	if (j - start < len)
		len = j - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i ++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)+ 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		result[j] = s1[i];
		j ++;
		i ++;
	}
	i = 0;
	while (s2[i])
	{
		result[j] = s2[i];
		j ++;
		i ++;
	}
    free(s1);
	return (result);
}
