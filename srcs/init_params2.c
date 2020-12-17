/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:35:10 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/17 12:19:38 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"

void		reset_mlx(t_mlx *mlx, t_config config)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->win_height = config.height;
	mlx->win_width = config.width;
	mlx->finalmap = config.mapa.worldmap;
}
