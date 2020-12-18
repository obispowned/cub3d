/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 12:01:22 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/18 13:35:57 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>

int				ft_strlen(char *str);
char			*ft_strtrim(char *s1, char *set);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin_char(char *str, char c);
char			*ft_strdup(char *str);
char			*ft_strdup2(char *str, char now, int max, int *count_sprites);
void			change_tabs(char *finally, char c, int n);
char			**ft_split(char const *s, char c);
void			double_kill(char **str);
int				what_is_higher(int a, int b);
int				ft_isdigit(char *str);
char			*give_me_digit_without_spaces(char *str);
void			*ft_memset(void *ptr, int x, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_atoi(const char *str);
void			kill(char *str);
void			double_kill(char **str);
void			ace(char *str, ...);
void			print_err(char *str);
void			ft_putchar(char *str);
int				white_spaces(char c);

#endif
