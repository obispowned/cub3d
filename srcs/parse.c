/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 13:08:24 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/15 13:08:25 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../header/cub3d.h"
#include "../header/game.h"

t_mapi			parserico(char **map, t_config *config)
{ /*PARSEAMOS EL MAPA EN CHAR A MAPA EN INTS*/
	int		i;
	int		j;

	config->hexaceil = 0;	//inicializo para evitar errorees
	config->hexafloor = 0;
	i = 0;
	config->mapa.worldMap = (int **)malloc(sizeof(int *) * config->map_max_lines);
	while (config->map_max_lines > i)
	{
		config->mapa.worldMap[i] = (int *)malloc(sizeof(int) * config->map_max_rows);
		j = 0;
		while (j < config->map_max_rows)
		{
			if (map[i][j] == '9')
			{
				config->mapa.worldMap[i][j] = 0;
				printf("%d", config->mapa.worldMap[i][j]);
			}
			else
			{
				config->mapa.worldMap[i][j] = (int)(map[i][j] - '0');
				printf("%d", config->mapa.worldMap[i][j]);
			}
			j++;
		}
		printf("\n");
		i++;
	}
	ceil_floor_parsing(&config->mapa, config);
	return (config->mapa);
}

void	ceil_floor_parsing(t_mapi	*mapa, t_config *config)
{
	config->hexaceil = createRGB(config->ceil[0], config->ceil[1], config->ceil[2]);
	config->hexafloor = createRGB(config->floor[0], config->floor[1], config->floor[2]);
}

unsigned long createRGB(int r, int g, int b)
{
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

float   radians_to_grads(float radians)
{
	return(radians * (180.0 / PI));
}

float   grads_to_radians(float grads)
{
	return(grads * (PI / 180.0));
}
