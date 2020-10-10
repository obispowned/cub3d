#ifndef UTILS_H
# define UTILS_H

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int		ft_strlen(char *str);
char	*ft_strjoin_char(char *str, char c);
char	*my_strdup(char *str);
char	**ft_split(char const *s, char c);
void	double_kill(char **str);

#endif
