#include "get_next_line.h"

static void	ft_free_all(char *to_free)
{
	if (to_free == NULL)
		return ;
	free(to_free);
	to_free = NULL;
}

static char	*in_buffer(int fd, char *buffer)
{
	char	*buff;
	int		bytes_read;
	
	if (!buffer)
		buffer = ft_calloc(sizeof(char), 1);
	buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	while (!ft_strchr(buff, '\n') && bytes_read != 0)
	{
		buff = read(fd, buff, BUFFER_SIZE);
		if (read == -1)
		{
			free(buff);
			free(buffer);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		buff = ft_strjoin(buffer, buff);
	}
	free(buff);
	return (buffer);
}

static char	*procc_line(char *buffer)
{
	int		i;
	char	*line;

	if(buffer[0])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i ++;
	line = ft_substr(buffer, 0, i + 1);
	return (line);
}

static char	*sep_line(char *buffer)
{
	int		i;
	char	*aux;

	if(buffer[0])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i ++;
	aux = ft_substr(buffer, i + 1, ft_strlen(buffer) - 1);
	free(buffer);
	buffer = aux;
}

char	*get_next_line(int fd)
{
	static char	*rcvr;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		ft_free_all(rcvr);
	rcvr = in_buffer(fd, rcvr);
	line = procc_line(rcvr);
	sep_line(&rcvr);
	if (line && *line == '\0' )
	{
		free(line);
		free(rcvr);
		line = NULL;
		rcvr = NULL;
	}
	return (line);
}