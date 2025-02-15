/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncheniou <ncheniou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:19:09 by ncheniou          #+#    #+#             */
/*   Updated: 2025/02/15 18:29:13 by ncheniou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	aux;

	aux = 0;
	if (!str)
		return (0);
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
		return (free(s1), s1 = NULL);
	i = 0;
	j = 0;
	while (i < sr1)
		result[j++] = s1[i++];
	i = 0;
	while (i < sr2)
		result[j++] = s2[i++];
	result[j] = '\0';
	free(s1);
	return (result);
}
