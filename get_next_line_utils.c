#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	aux;

	aux = 0;
	if(!str)
		return(0);
	while (str[aux])
		aux ++;
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
	size_t	i;
	char	*copy;

	i = 0;
	copy = malloc(nmemb * size);
	if (copy == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		copy[i] = 0;
		i ++;
	}
	return (copy);
}


char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = ft_strlen(s);
	if (!s || start >= j || len == 0)
		return (NULL);
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*result;
	size_t	sr1;
	size_t	sr2;

	sr1 = ft_strlen(s1);
	sr2 = ft_strlen(s2);
	if (!s2)
		return (NULL);
	result = malloc(sr1 + sr2 + 1);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (i < sr1)
		result[j++] = s1[i++];
	i = 0;
	while (i < sr2)
		result[j++] = s2[i++];
	result[j] = '\0';
	return (result);
}

// char	*ft_substr(char *s, unsigned int start, size_t len)
// {
// 	char	*aux;
// 	size_t	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	if (ft_strlen(s) <= start)
// 		return (0);
// 	if (ft_strlen(&s[start]) < len)
// 		len = ft_strlen(&s[start]);
// 	aux = (char *)malloc(len + 1 * sizeof(char));
// 	if (!aux)
// 		return (0);
// 	while (s[start] != 0 && i < len)
// 		aux[i++] = s[start++];
// 	aux[i] = 0;
// 	return (aux);
// }
