#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"

void	init_raycast_params(t_mlx *mlx, t_config *config)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->win_width = config->width;
	mlx->win_height = config->height;
	mlx->rc.player_pos_y = (double)config->player_begin[0] + 0.5;
	mlx->rc.player_pos_x = (double)config->player_begin[1] + 0.5;
//	init_player(mlx, config);
	mlx->rc.map_lines = config->map_max_lines;
	mlx->rc.map_rows = config->map_max_rows;
	mlx->rc.tex_height = 64;
	mlx->rc.tex_width = 64;
	mlx->rc.movespeed = 0.400;

	if (config->player_pos_begin == 'N')
	{ 
		mlx->rc.dirx = -1;
		mlx->rc.diry = 0;
		mlx->rc.player_plane_x = 0;
		mlx->rc.player_plane_y = 0.66;
//		mlx->rc.initial_pos++;
	}
	else if (config->player_pos_begin == 'S')
	{
		mlx->rc.player_plane_x = 0;
		mlx->rc.player_plane_y = -0.66;
		mlx->rc.dirx = 1;
		mlx->rc.diry = 0;
	}
	else if (config->player_pos_begin == 'E')
	{
		mlx->rc.player_plane_x = 0.66;
		mlx->rc.player_plane_y = 0;
		mlx->rc.dirx = 0;
		mlx->rc.diry = 1;
	}
	else if (config->player_pos_begin == 'W')
	{
		mlx->rc.player_plane_x = -0.66;
		mlx->rc.player_plane_y = 0;
		mlx->rc.dirx = 0;
		mlx->rc.diry = -1;
	}
	printf("Posicion Inicial: x:%f - y:%f\n", mlx->rc.player_pos_x, mlx->rc.player_pos_y);
}

void		init_player(t_mlx *mlx, t_config *config)
{
	if (config->muro_arriba_abajo == 1)
		mlx->rc.player_pos_y = (double)config->player_begin[0] + 0.5;
	else if (config->muro_arriba_abajo == -1)
		mlx->rc.player_pos_y = (double)config->player_begin[0] + 0.5;
	if (config->muro_izq_dcha == 1)
		mlx->rc.player_pos_x = (double)config->player_begin[1] + 0.5;
	else if (config->muro_izq_dcha == -1)
		mlx->rc.player_pos_x = (double)config->player_begin[1] + 0.5;
	printf("%d-%d\n", config->player_begin[0], config->player_begin[1]);
}