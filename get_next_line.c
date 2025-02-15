#include "get_next_line.h"


static char	*in_buffer(int fd, char *buffer)
{
	char	*buff;
	int		bytes_read;
	
	bytes_read = 1;
	if (!buffer)
		buffer = NULL;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
        return (NULL);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, buff);
		if (ft_strchr(buff, '\n'))
			break;			
	}
	free(buff);
	return (buffer);
}

static char	*procc_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if(!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
	{
		i++;
	}
	line = ft_substr(buffer, 0, i + 1);
	return (line);
}

static char	*sep_line(char *buffer)
{
	int		i;
	char	*aux;

	i = 0;
	if(!buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i ++;
	aux = ft_substr(buffer, i + 1, ft_strlen(buffer) - i);
	if (!aux)
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*rcvr;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(rcvr);
		rcvr = NULL;
		return (NULL);
	}
	rcvr = in_buffer(fd, rcvr);
	if (!rcvr)
		return (NULL);
	line = procc_line(rcvr);
	rcvr = sep_line(rcvr);
	if (line && *line == '\0' )
	{
		free(line);
		free(rcvr);
		rcvr = NULL;
		return (NULL);
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*str;
// 	int		i;

// 	i = 0;
// 	fd = open("prueba.txt", O_RDONLY);
// 	while ((i <= 6))
// 	{
// 		str = get_next_line(fd);
// 		printf("line %i => [%s]\n", i + 1, str);
// 		if (!str)
// 			break;
// 		free(str);
// 		i++;
// 	}
// 	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
// 	close(fd);
// 	return (0);
// }


// static char *ft_free(char *buffer, char *buff)
// {
// 	char *aux;

// 	aux = ft_strjoin(buffer, buff);
// 	free(buffer);
// 	return(aux);
// }

// static char	*in_buffer(int fd, char *buffer)
// {
// 	char	*buff;
// 	int		bytes_read;
	
// 	bytes_read = 1;
// 	if (!buffer)
// 		buffer = malloc(sizeof(char) * 1);
// 	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	while (bytes_read > 0)
// 	{
// 		bytes_read = read(fd, buff, BUFFER_SIZE);
// 		if (bytes_read == -1)
// 		{
// 			free(buff);
// 			return (NULL);
// 		}
// 		buff[bytes_read] = '\0';
// 		printf("buff::%s\n", buff);
// 		buffer = ft_free(buffer, buff);
// 		if (ft_strchr(buffer, '\n') )
// 			break;
// 	}
// 	free(buff);
// 	return (buffer);
// }