/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 13:08:24 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/17 12:19:49 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"
#include "../header/game.h"

t_mapi			parserico(char **map, t_config *config)
{
	int		i;
	int		j;

	config->hexaceil = 0;
	config->hexafloor = 0;
	i = 0;
	config->mapa.worldmap = (int **)malloc(sizeof(int *)
	* config->map_max_lines);
	while (config->map_max_lines > i)
	{
		config->mapa.worldmap[i] = (int *)malloc(sizeof(int)
		* config->map_max_rows);
		j = 0;
		while (j < config->map_max_rows)
		{
			if (map[i][j] == '9')
				config->mapa.worldmap[i][j] = 0;
			else
				config->mapa.worldmap[i][j] = (int)(map[i][j] - '0');
			j++;
		}
		i++;
	}
	ceil_floor_parsing(&config->mapa, config);
	return (config->mapa);
}

void			ceil_floor_parsing(t_mapi *mapa, t_config *config)
{
	config->hexaceil = creatergb(config->ceil[0],
	config->ceil[1], config->ceil[2]);
	config->hexafloor = creatergb(config->floor[0],
	config->floor[1], config->floor[2]);
}

unsigned long	creatergb(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

float			radians_to_grads(float radians)
{
	return (radians * (180.0 / PI));
}

float			grads_to_radians(float grads)
{
	return (grads * (PI / 180.0));
}
