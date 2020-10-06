/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:26:41 by agutierr          #+#    #+#             */
/*   Updated: 2020/01/24 11:53:18 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t				ft_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char				*ft_strdup(char *s1)
{
	char			*new;
	int				i;
	int				size;

	size = 0;
	while (s1[size])
		++size;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char				*ft_strchr(char *s, char c)
{
	while (*s && *s != c)
		s++;
	return ((*s == c) ? s : NULL);
}

char				*ft_strjoin(char *s1, char *s2)
{
	int				i;
	int				j;
	int				count;
	char			*s;

	i = 0;
	count = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(s = malloc(sizeof(char) * count)))
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		s[i] = s2[j];
		i++;
		j++;
	}
	s[i] = '\0';
	return (s);
}

char				*ft_substr(char *s, unsigned int start, unsigned int len)
{
	char			*dest;
	unsigned int	i;
	unsigned int	total;
	unsigned int	lenglo;

	lenglo = ft_strlen(s);
	if (start > lenglo)
		return (ft_strdup(""));
	i = 0;
	total = start + len;
	if (len < (lenglo - start))
		dest = (char*)malloc(sizeof(char) * (len + 1));
	else
		dest = (char*)malloc(sizeof(char) * (lenglo - start + 1));
	if (!dest)
		return (NULL);
	while (start < total)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}
