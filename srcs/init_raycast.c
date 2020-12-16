/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:45:54 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/16 13:28:45 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"

void		init_raycast_params(t_mlx *mlx, t_config *config)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->win_width = config->width;
	mlx->win_height = config->height;
	mlx->hexa_ceil = config->hexaceil;
	mlx->hexa_floor = config->hexafloor;
	init_player(mlx, config);
	mlx->rc.map_lines = config->map_max_lines;
	mlx->rc.map_rows = config->map_max_rows;
	mlx->rc.tex_height = 64;
	mlx->rc.tex_width = 64;
	mlx->rc.movespeed = 0.060;
	mlx->rc.tex_side = 1;
	mlx->rc.up = 0;
	mlx->flag_bmp = 0;
	mlx->rc.down = 0;
	mlx->rc.right = 0;
	mlx->rc.left = 0;
	mlx->rc.savebpm = config->save;
	mlx->rc.sprites_count = config->numsprites;
	mlx->rc.sprite = calloc(sizeof(t_sprite) * config->numsprites, 1);
	mlx->rc.spr_buffer = (double *)malloc(sizeof(double) * mlx->win_width);
	init_raycast_params2(config, mlx);
	init_raycast_params3(config, mlx);
}

void		init_player(t_mlx *mlx, t_config *config)
{
	mlx->rc.player_pos_y = (double)config->player_begin[0] + 0.5;
	mlx->rc.player_pos_x = (double)config->player_begin[1] + 0.5;
}

void		init_raycast_params2(t_config *config, t_mlx *mlx)
{
	if (config->player_pos_begin == 'N')
	{
		mlx->rc.dirx = -1;
		mlx->rc.diry = 0;
		mlx->rc.player_plane_x = 0;
		mlx->rc.player_plane_y = 0.66;
	}
	else if (config->player_pos_begin == 'S')
	{
		mlx->rc.dirx = 1;
		mlx->rc.diry = 0;
		mlx->rc.player_plane_x = 0;
		mlx->rc.player_plane_y = -0.66;
	}
}

void		init_raycast_params3(t_config *config, t_mlx *mlx)
{
	if (config->player_pos_begin == 'E')
	{
		mlx->rc.dirx = 0;
		mlx->rc.diry = 1;
		mlx->rc.player_plane_x = 0.66;
		mlx->rc.player_plane_y = 0;
	}
	else if (config->player_pos_begin == 'W')
	{
		mlx->rc.dirx = 0;
		mlx->rc.diry = -1;
		mlx->rc.player_plane_x = -0.66;
		mlx->rc.player_plane_y = 0;
	}
}
