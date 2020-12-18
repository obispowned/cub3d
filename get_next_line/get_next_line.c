/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 11:42:52 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/18 11:44:49 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_strlen_gnl(char *str)
{
	int			i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_strjoint(char *str, char c)
{
	int			i;
	char		*final;

	i = 0;
	if (!(final = ((char *)malloc(sizeof(char) * (ft_strlen_gnl(str) + 2)))))
		return (NULL);
	while (str[i])
	{
		final[i] = str[i];
		i++;
	}
	final[i] = c;
	final[i + 1] = '\0';
	free(str);
	return (final);
}

char			*ft_strdup_gnl(char *str)
{
	int			i;
	char		*final;

	i = 0;
	if (!(final = ((char *)malloc(sizeof(char) * (ft_strlen_gnl(str) + 1)))))
		return (NULL);
	while (str[i])
	{
		final[i] = str[i];
		i++;
	}
	final[i] = '\0';
	return (final);
}

int				get_next_line(int fd, char **line)
{
	int			ret;
	char		buf[2];

	if (!line || !(*line = ft_strdup_gnl("")))
		return (-1);
	buf[1] = '\0';
	while ((ret = read(fd, buf, 1)) > 0)
	{
		if (ret == -1)
			return (-1);
		if (buf[0] == '\n')
			break ;
		*line = ft_strjoint(*line, buf[0]);
	}
	return (ret);
}
