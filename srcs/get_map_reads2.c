/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_reads2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 13:29:06 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/17 13:46:59 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int				who_needs_a_map(char *line, char *chain2, int tab, int coincide)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		coincide = 0;
		j = 0;
		while (chain2[j] != '\0')
		{
			while (line[i] == '\t')
			{
				tab = 1;
				i++;
			}
			if (line[i] == chain2[j])
				coincide = 1;
			j++;
		}
		if (coincide != 1)
			return (0);
		i++;
	}
	return (who_needs_a_map2(tab, coincide));
}

int				who_needs_a_map2(int tab, int coincide)
{
	if (coincide == 1)
	{
		if (tab == 1)
			print_err("No tabs en el mapa");
		return (1);
	}
	else
		return (0);
}

char			*fill_me(char c, int lenght)
{
	char		*finally;
	int			i;

	i = 0;
	if (!(finally = ((char *)malloc(sizeof(char) * lenght + 2))))
		printf("Malloc ha fallado en: get_map_reads.c");
	while (i <= lenght)
	{
		finally[i] = c;
		i++;
	}
	finally[i] = '\0';
	return (finally);
}

void			valid_map(char **map)
{
	int			i;
	int			j;

	i = 1;
	while (map[i + 1])
	{
		j = 1;
		while (map[i][j + 1])
		{
			valid_map2(map, i, j);
			j++;
		}
		if ((map[i][j] == '9') &&
			(((map[i - 1][j] != '1') && (map[i - 1][j] != '9')) ||
			((map[i + 1][j] != '1') && (map[i + 1][j] != '9')) ||
			((map[i][j - 1] != '1') && (map[i][j - 1] != '9'))))
			print_err("Mapa abierto\n");
		i++;
	}
}

void			valid_map2(char **map, int i, int j)
{
	if ((map[0][j] != '9' && map[0][j] != '1') ||
	(map[i][0] != '9' && map[i][0] != '1') ||
	(map[0][0] != '9' && map[0][0] != '1'))
		print_err("Mapa abierto en primeras lineas\n");
	if ((map[0][j] == '9') &&
	(((map[1][j] != '1') && (map[1][j] != '9')) ||
	((map[0][j + 1] != '1') && (map[0][j + 1] != '9')) ||
	((map[0][j - 1] != '1') && (map[0][j - 1] != '9'))))
		print_err("Mapa abierto\n");
	else if ((map[i][j] == '9') &&
	(((map[i - 1][j] != '1') && (map[i - 1][j] != '9')) ||
	((map[i + 1][j] != '1') && (map[i + 1][j] != '9')) ||
	((map[i][j + 1] != '1') && (map[i][j + 1] != '9')) ||
	((map[i][j - 1] != '1') && (map[i][j - 1] != '9'))))
		print_err("Mapa abierto\n");
}
