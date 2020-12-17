/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:48:59 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/17 12:22:45 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"

void			reset_t_config(t_config *config)
{
	config->flag = 0;
	config->i = 0;
	config->height = -1;
	config->width = -1;
	config->no = NULL;
	config->so = NULL;
	config->ea = NULL;
	config->we = NULL;
	config->s = NULL;
	config->map_max_lines = 0;
	config->map_max_rows = 0;
	config->maxr = 0;
	config->player_begin[0] = 0;
	config->player_begin[1] = 0;
	config->muro_izq_dcha = 0;
	config->muro_arriba_abajo = 0;
	init_config(config);
}

void			init_config(t_config *config)
{
	int	i;

	i = 0;
	config->numsprites = 0;
	config->save = 0;
	config->player_pos_begin = '\0';
	while (i < 3)
	{
		config->ceil[i] = -1;
		config->floor[i] = -1;
		i++;
	}
	config->hexaceil = 0;
	config->hexafloor = 0;
}
