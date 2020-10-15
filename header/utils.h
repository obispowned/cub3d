#ifndef UTILS_H
# define UTILS_H

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int		ft_strlen(char *str);
char	*ft_strjoin_char(char *str, char c);
char	*ft_strdup(char *str);
char	*ft_strdup_sustitute_char(char *str, char now, char final, int max);
char	**ft_split(char const *s, char c);
void	double_kill(char **str);
int 	what_is_higher(int a, int b);
int  	ft_isdigit(char *str);
void	*ft_memset(void *ptr, int x, size_t n);
void	*ft_calloc(size_t count, size_t size);

#endif
