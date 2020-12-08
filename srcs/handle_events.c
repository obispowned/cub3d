#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"

void	handle_events2(t_mlx *mlx)
{
	double olddirx;
	double oldplanex;

	if (mlx->rc.rot_right)
	{
		olddirx = mlx->rc.dirx;
		mlx->rc.dirx = mlx->rc.dirx * cos(-ROT_SPEED) - mlx->rc.diry * sin(-ROT_SPEED);
		mlx->rc.diry = olddirx * sin(-ROT_SPEED) + mlx->rc.diry * cos(-ROT_SPEED);
		oldplanex = mlx->rc.player_plane_x;
		mlx->rc.player_plane_x = mlx->rc.player_plane_x * cos(-ROT_SPEED)
							- mlx->rc.player_plane_y * sin(-ROT_SPEED);
		mlx->rc.player_plane_y = oldplanex * sin(-ROT_SPEED)
							+ mlx->rc.player_plane_y * cos(-ROT_SPEED);
	}
	else if (mlx->rc.rot_left)
	{
		olddirx = mlx->rc.dirx;
		mlx->rc.dirx = mlx->rc.dirx * cos(ROT_SPEED) - mlx->rc.diry * sin(ROT_SPEED);
		mlx->rc.diry = olddirx * sin(ROT_SPEED) + mlx->rc.diry * cos(ROT_SPEED);
		oldplanex = mlx->rc.player_plane_x;
		mlx->rc.player_plane_x = mlx->rc.player_plane_x * cos(ROT_SPEED)
							- mlx->rc.player_plane_y * sin(ROT_SPEED);
		mlx->rc.player_plane_y = oldplanex * sin(ROT_SPEED)
							+ mlx->rc.player_plane_y * cos(ROT_SPEED);
	}
}

void	move_right(t_mlx *mlx)
{
	if (mlx->rc.right)
	{
		if (mlx->finalMap[(int)mlx->rc.player_pos_y]
			[(int)(mlx->rc.player_pos_x + mlx->rc.player_plane_x
			* mlx->rc.movespeed)] == 0)
			mlx->rc.player_pos_x += mlx->rc.player_plane_x
			* mlx->rc.movespeed;
		if (mlx->finalMap[(int)(mlx->rc.player_pos_y
			+ mlx->rc.player_plane_y * mlx->rc.movespeed)]
			[(int)mlx->rc.player_pos_x] == 0)
			mlx->rc.player_pos_y += mlx->rc.player_plane_y
			* mlx->rc.movespeed;
	}
}

void	move_left(t_mlx *mlx)
{
	if (mlx->rc.left)
	{
		if (mlx->finalMap[(int)mlx->rc.player_pos_y]
			[(int)(mlx->rc.player_pos_x - mlx->rc.player_plane_x
			* mlx->rc.movespeed)] == 0)
			mlx->rc.player_pos_x -= mlx->rc.player_plane_x
			* mlx->rc.movespeed;
		if (mlx->finalMap[(int)(mlx->rc.player_pos_y
			- mlx->rc.player_plane_y * mlx->rc.movespeed)]
			[(int)mlx->rc.player_pos_x] == 0)
			mlx->rc.player_pos_y -= mlx->rc.player_plane_y
			* mlx->rc.movespeed;
	}
}

int		handle_events(t_mlx *mlx)
{
	if (mlx->rc.up == 1)
	{
		if (mlx->finalMap[(int)(mlx->rc.player_pos_x + mlx->rc.dirx
			* mlx->rc.movespeed)][(int)(mlx->rc.player_pos_y)] == 0)
			mlx->rc.player_pos_x += mlx->rc.dirx * mlx->rc.movespeed;
		if (mlx->finalMap[(int)(mlx->rc.player_pos_x)]
			[(int)(mlx->rc.player_pos_y + mlx->rc.diry * mlx->rc.movespeed)] == 0)
			mlx->rc.player_pos_y += mlx->rc.diry * mlx->rc.movespeed;
	}
	else if (mlx->rc.down)
	{
		if (mlx->finalMap[(int)(mlx->rc.player_pos_x - mlx->rc.dirx
			* mlx->rc.movespeed)][(int)(mlx->rc.player_pos_y)] == 0)
			mlx->rc.player_pos_x -= mlx->rc.dirx * mlx->rc.movespeed;
		if (mlx->finalMap[(int)(mlx->rc.player_pos_x)]
			[(int)(mlx->rc.player_pos_y - mlx->rc.diry * mlx->rc.movespeed)] == 0)
			mlx->rc.player_pos_y -= mlx->rc.diry * mlx->rc.movespeed;
	}
	handle_events2(mlx);
	move_right(mlx);
	move_left(mlx);
	return (0);
}