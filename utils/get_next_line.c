/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:26:00 by agutierr          #+#    #+#             */
/*   Updated: 2020/10/04 12:57:33 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/get_next_line.h"
//#include <get_next_line.h>

void				destroy(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}

char				*feed(char *aux, char **line, int *len)
{
	int				i;
	char			*temp;

	i = 0;
	while (aux[i] != '\n' && aux[i] != '\0')
		i++;
	if (aux[i] == '\n')
	{
		*line = gnlft_substr(aux, 0, i);
		temp = gnlft_substr(aux, i + 1, gnlft_strlen(aux) - i - 1);
		destroy(&aux);
		aux = temp;
		*len = 1;
	}
	else
	{
		*line = gnlft_strdup(aux);
		destroy(&aux);
		*len = 0;
	}
	return (aux);
}

int					check_error(int len, char *aux, char **line)
{
	if (len < 0)
		return (-1);
	else if (len == 0 && aux == 0)
	{
		*line = gnlft_strdup("");
		return (0);
	}
	return (1);
}

int					get_next_line(int fd, char **line)
{
	int				len;
	char			buff[BUFFER_SIZE + 1];
	static char		*aux[4096];
	char			*temp;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((len = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[len] = '\0';
		if (!aux[fd])
			aux[fd] = gnlft_strdup(buff);
		else
		{
			temp = gnlft_strjoin(aux[fd], buff);
			destroy(&aux[fd]);
			aux[fd] = temp;
		}
		if (gnlft_strchr(aux[fd], '\n'))
			break ;
	}
	if (check_error(len, aux[fd], &*line) < 1)
		return (check_error(len, *aux, &*line));
	aux[fd] = feed(aux[fd], line, &len);
	return (len);
}
