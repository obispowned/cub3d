#ifndef UTILS_H
# define UTILS_H

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdarg.h>

int		ft_strlen(char *str);
char	*ft_strjoin_char(char *str, char c);
char	*ft_strdup(char *str);
char		*ft_strdup_sustitute_char(char *str, char now, char final, int max, int *count_sprites);
void	change_tabs(char *finally, char c, int n);
char	**ft_split(char const *s, char c);
void	double_kill(char **str);
int 	what_is_higher(int a, int b);
int  	ft_isdigit(char *str);
char    *give_me_digit_without_spaces(char *str);
void	*ft_memset(void *ptr, int x, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);

//liberacion de memoria
void	kill(char *str);
void	double_kill(char **str); //liberar un doble puntero
void	ace(char *str, ...); //liberar cualquier cantidad de punteros
void 	print_error(char *str);
////
int		white_spaces(char c);

#endif
