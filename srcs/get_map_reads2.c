/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_reads2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 13:29:06 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/15 13:47:36 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int			who_needs_a_map(char *line)
{
	int		i;
	int		j;
	int		coincide;
	char	*chain2;
	int		tab;

	coincide = 0;
	tab = 0;
	chain2 = "102 NSWE\t";
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
	if (coincide == 1)
	{
		if (tab == 1)
			print_error("No tabs en el mapa");
		return (1);
	}
	else
		return (0);
}

char		*fill_me(char c, int lenght)
{
	char	*finally;
	int		i;

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

void			check_wall(t_config *config, char **map, int i, int j)
{
	if (map[i - 1][j] == 1)
		config->muro_arriba_abajo = 1;
	else if (map[i + 1][j] == 1)
		config->muro_arriba_abajo = -1;
	if (map[i][j - 1] == 1)
		config->muro_izq_dcha = 1;
	else if (map[i][j + 1] == 1)
		config->muro_arriba_abajo = -1;
}
