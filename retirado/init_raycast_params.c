#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"

void	init_raycast_params3(t_mlx *mlx, t_config *config)
{
	mlx->rc.tex_height = 64;
	mlx->rc.tex_width = 64;
	mlx->rc.tex_side = 1;
	mlx->rc.movespeed = 0.200;
	mlx->rc.up = 0;
	mlx->rc.down = 0;
	mlx->rc.right = 0;
	mlx->rc.left = 0;
	if (mlx->rc.player_dir == 'E') /****EXTRAER DIR DE JUGADOR NA MAS EMPIEZA****/
	{
		mlx->rc.player_plane_x = 0.66;
		mlx->rc.player_plane_y = 0;
		mlx->rc.dirx = 0;
		mlx->rc.diry = 1;
	}
	else if (mlx->rc.player_dir == 'W')
	{
		mlx->rc.player_plane_x = -0.66;
		mlx->rc.player_plane_y = 0;
		mlx->rc.dirx = 0;
		mlx->rc.diry = -1;
	}
}

void	init_raycast_params2(t_mlx *mlx, t_config *config)
{ /*POSIBLE SEG FAULT AL EQUIVOCAR BEGIN 0 CON BEGIN 1*/
	mlx->rc.player_pos_x = (double)config->player_begin[0] + 0.5;
	mlx->rc.player_pos_y = (double)config->player_begin[1] + 0.5;
	if (mlx->rc.player_dir == 'N')
	{
		mlx->rc.dirx = -1;
		mlx->rc.diry = 0;
		mlx->rc.player_plane_x = 0;
		mlx->rc.player_plane_y = 0.66;
	}
	else if (mlx->rc.player_dir == 'S')
	{
		mlx->rc.player_plane_x = 0;
		mlx->rc.player_plane_y = -0.66;
		mlx->rc.dirx = 1;
		mlx->rc.diry = 0;
	}
}

void		init_raycast_params(t_mlx *mlx, t_config *config)
{
	mlx->rc.player_pos_x = config->player_begin[0];
	mlx->rc.player_pos_y = config->player_begin[1];
	mlx->rc.player_dir = config->player_pos_begin;
	mlx->rc.rot_left = 0;
	mlx->rc.rot_right = 0;
	mlx->rc.hexafloor = (int)config->hexafloor;
	mlx->rc.hexaceil = (int)config->hexaceil;
	init_raycast_params2(mlx, config);
	init_raycast_params3(mlx, config);
//	mlx->rc.spr_buffer = (double *)malloc(sizeof(double) * mlx->win_width);
}