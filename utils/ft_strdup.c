/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 08:33:02 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/17 13:47:18 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/utils.h"
#include "../header/cub3d.h"

char		*ft_strdup(char *str)
{
	char	*finally;
	int		i;

	i = 0;
	if (!(finally = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		printf("Malloc ha fallado en: ft_strdup.c");
	while (str[i] != '\0')
	{
		finally[i] = str[i];
		i++;
	}
	finally[i] = '\0';
	return (finally);
}

char		*ft_strdup2(char *str, char now, int max, int *count_sprites)
{
	char	*finally;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!(finally = (char *)malloc(sizeof(char) * max + 2)))
		print_err("Malloc ha fallado en: ft_strdup.c");
	while (str[++i] != '\0')
	{
		if (str[i] == '2')
			*count_sprites += 1;
		if (str[i] == '\t')
			print_err("No debe haber tabulaciones al empezar el mapa");
		else if (str[i] == now)
			finally[j] = '9';
		else
			finally[j] = str[i];
		j++;
	}
	while (j < max + 1)
		finally[j++] = '9';
	finally[j] = '\0';
	return (finally);
}

void		change_tabs(char *finally, char c, int n)
{
	int		i;

	i = 0;
	while (i < n)
		finally[i++] = c;
}
