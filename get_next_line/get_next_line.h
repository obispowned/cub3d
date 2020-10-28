#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int		ft_strlen_gnl(char *str);
char	*ft_strjoint(char *str, char c);
int		get_next_line(int fd, char **line);

#endif
