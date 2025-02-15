#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <strings.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char			*get_next_line(int fd);
int			ft_strlen(char *str);
char			*ft_strchr(const char *s, int c);
char	        *ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
void			*ft_calloc(size_t nmemb, size_t size);

#endif