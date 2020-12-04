#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"
#include <math.h>

void	handle_events2(t_mlx *mlx)
{
	double olddirx;
	double oldplanex;

	if (mlx->rc.rot_right)
	{
		olddirx = mlx->rc.player_dir_x;
		mlx->rc.player_dir_x = mlx->rc.player_dir_x * cos(-ROT_SPEED) - mlx->rc.player_dir_y * sin(-ROT_SPEED);
		mlx->rc.player_dir_y = olddirx * sin(-ROT_SPEED) + mlx->rc.player_dir_y * cos(-ROT_SPEED);
		oldplanex = mlx->rc.player_plane_x;
		mlx->rc.player_plane_x = mlx->rc.player_plane_x * cos(-ROT_SPEED) - mlx->rc.player_plane_y * sin(-ROT_SPEED);
		mlx->rc.player_plane_y = oldplanex * sin(-ROT_SPEED) + mlx->rc.player_plane_y * cos(-ROT_SPEED);
	}
	else if (mlx->rc.rot_left)
	{
		olddirx = mlx->rc.player_dir_x;
		mlx->rc.player_dir_x = mlx->rc.player_dir_x * cos(ROT_SPEED) - mlx->rc.player_dir_y * sin(ROT_SPEED);
		mlx->rc.player_dir_y = olddirx * sin(ROT_SPEED) + mlx->rc.player_dir_y * cos(ROT_SPEED);
		oldplanex = mlx->rc.player_plane_x;
		mlx->rc.player_plane_x = mlx->rc.player_plane_x * cos(ROT_SPEED) - mlx->rc.player_plane_y * sin(ROT_SPEED);
		mlx->rc.player_plane_y = oldplanex * sin(ROT_SPEED)	+ mlx->rc.player_plane_y * cos(ROT_SPEED);
	}
}

int		handle_events(t_mlx *mlx, t_config *config)
{
	if (mlx->rc.up == 1)
	{ //MV_SPEED - movespeed
		if (config->mapa.worldMap[(int)(mlx->rc.player_pos_x +
		mlx->rc.player_dir_x * mlx->rc.movespeed)][(int)(mlx->rc.player_pos_y)] == 0)
			mlx->rc.player_pos_x += mlx->rc.player_dir_x * mlx->rc.movespeed;
		if (config->mapa.worldMap[(int)(mlx->rc.player_pos_x)]
			[(int)(mlx->rc.player_pos_y + mlx->rc.player_dir_y * mlx->rc.movespeed)] == 0)
			mlx->rc.player_pos_y += mlx->rc.player_dir_y * mlx->rc.movespeed;
	}
	else if (mlx->rc.down)
	{
		if (config->mapa.worldMap[(int)(mlx->rc.player_pos_x - mlx->rc.player_dir_x
			* mlx->rc.movespeed)][(int)(mlx->rc.player_pos_y)] == 0)
			mlx->rc.player_pos_x -= mlx->rc.player_dir_x * mlx->rc.movespeed;
		if (config->mapa.worldMap[(int)(mlx->rc.player_pos_x)]
			[(int)(mlx->rc.player_pos_y - mlx->rc.player_dir_y * mlx->rc.movespeed)] == 0)
			mlx->rc.player_pos_y -= mlx->rc.player_dir_y * mlx->rc.movespeed;
	}
	handle_events2(mlx);
	move_right(mlx, config);
	move_left(mlx, config);
	return (0);
}

void	move_right(t_mlx *mlx, t_config *config)
{
	if (mlx->rc.right)
	{	//MV_SPEED - movespeed
		if (config->mapa.worldMap[(int)mlx->rc.player_pos_y]
			[(int)(mlx->rc.player_pos_x + mlx->rc.player_plane_x
			* mlx->rc.movespeed)] == 0)
			mlx->rc.player_pos_x += mlx->rc.player_plane_x * mlx->rc.movespeed;
		if (config->mapa.worldMap[(int)(mlx->rc.player_pos_y
			+ mlx->rc.player_plane_y * mlx->rc.movespeed)]
			[(int)mlx->rc.player_pos_x] == 0)
			mlx->rc.player_pos_y += mlx->rc.player_plane_y * mlx->rc.movespeed;
	}
}

void	move_left(t_mlx *mlx, t_config *config)
{
	if (mlx->rc.left)
	{	//MV_SPEED - movespeed
		if (config->mapa.worldMap[(int)mlx->rc.player_pos_y]
			[(int)(mlx->rc.player_pos_x - mlx->rc.player_plane_x * mlx->rc.movespeed)] == 0)
			mlx->rc.player_pos_x -= mlx->rc.player_plane_x * mlx->rc.movespeed;
		if (config->mapa.worldMap[(int)(mlx->rc.player_pos_y - mlx->rc.player_plane_y * mlx->rc.movespeed)]
			[(int)mlx->rc.player_pos_x] == 0)
			mlx->rc.player_pos_y -= mlx->rc.player_plane_y * mlx->rc.movespeed;
	}
}
