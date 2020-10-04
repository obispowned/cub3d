/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:26:11 by agutierr          #+#    #+#             */
/*   Updated: 2020/10/04 12:45:36 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
size_t	gnlft_strlen(char *s);
char	*gnlft_strdup(char *s1);
char	*gnlft_strchr(char *s, char c);
char	*gnlft_substr(char *s, unsigned int start, unsigned int len);
char	*gnlft_strjoin(char *s1, char *s2);

#endif
