#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"

int handle_events(int key, t_mlx *mlx)
{
	double oldDirX;
	double oldPlaneX;

	if (key == KEY_ESC)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		free(mlx->ptr);
		exit(-1);
	}
	if (key == KEY_S || key == KEY_W || key == KEY_RIGHT || key == KEY_LEFT || key == KEY_A || key == KEY_D)
	{
		if (key == KEY_W)
		{
			if (mlx->finalMap[(int)(mlx->rc.player_pos_x + mlx->rc.dirx *
			mlx->rc.movespeed)][(int)(mlx->rc.player_pos_y)] == 0)
				mlx->rc.player_pos_x += mlx->rc.dirx * mlx->rc.movespeed;
			if (mlx->finalMap[(int)(mlx->rc.player_pos_x)][(int)(mlx->rc.player_pos_y + mlx->rc.diry *
			mlx->rc.movespeed)] == 0)
				mlx->rc.player_pos_y += mlx->rc.diry * mlx->rc.movespeed;
				printf("\nArriba\n");
		}
		if (key == KEY_S)
		{
			if (mlx->finalMap[(int)(mlx->rc.player_pos_x - mlx->rc.dirx * MV_SPEED)][(int)(mlx->rc.player_pos_y)] == 0)
				mlx->rc.player_pos_x -= mlx->rc.dirx * MV_SPEED;
			if (mlx->finalMap[(int)(mlx->rc.player_pos_x)][(int)(mlx->rc.player_pos_y - mlx->rc.diry * MV_SPEED)] == 0)
				mlx->rc.player_pos_y -= mlx->rc.diry * MV_SPEED;
				printf("\nAbajo\n");
		}
		if (key == KEY_D)
		{
			if (mlx->finalMap[(int)(mlx->rc.player_pos_x + mlx->rc.player_plane_x *
			mlx->rc.movespeed)][(int)(mlx->rc.player_pos_y)] == 0)
				mlx->rc.player_pos_x += mlx->rc.player_plane_x * mlx->rc.movespeed;
			if (mlx->finalMap[(int)(mlx->rc.player_pos_x)][(int)(mlx->rc.player_pos_y + mlx->rc.player_plane_y *
			mlx->rc.movespeed)] == 0)
				mlx->rc.player_pos_y += mlx->rc.player_plane_y * mlx->rc.movespeed;
			printf("\nDerecha\n");
		}
		if (key == KEY_A)
		{
			if (mlx->finalMap[(int)(mlx->rc.player_pos_x - mlx->rc.player_plane_x * MV_SPEED)][(int)(mlx->rc.player_pos_y)] == 0)
				mlx->rc.player_pos_x -= mlx->rc.player_plane_x * MV_SPEED;
			if (mlx->finalMap[(int)(mlx->rc.player_pos_x)][(int)(mlx->rc.player_pos_y - mlx->rc.player_plane_y * MV_SPEED)] == 0)
				mlx->rc.player_pos_y -= mlx->rc.player_plane_y * MV_SPEED;
				printf("\nIzquierda\n");
		}
		if (key == KEY_RIGHT)
		{
			oldDirX = mlx->rc.dirx;
			mlx->rc.dirx = mlx->rc.dirx * cos(-ROT_SPEED) - mlx->rc.diry * sin(-ROT_SPEED);
			mlx->rc.diry = oldDirX * sin(-ROT_SPEED) + mlx->rc.diry * cos(-ROT_SPEED);
			oldPlaneX = mlx->rc.player_plane_x;
			mlx->rc.player_plane_x = mlx->rc.player_plane_x * cos(-ROT_SPEED) - mlx->rc.player_plane_y * sin(-ROT_SPEED);
			mlx->rc.player_plane_y = oldPlaneX * sin(-ROT_SPEED) + mlx->rc.player_plane_y * cos(-ROT_SPEED);
			printf("Rot_Derecha\n");
		}
		if (key == KEY_LEFT)
		{
			oldDirX = mlx->rc.dirx;
			mlx->rc.dirx = mlx->rc.dirx * cos(ROT_SPEED) - mlx->rc.diry * sin(ROT_SPEED);
			mlx->rc.diry = oldDirX * sin(ROT_SPEED) + mlx->rc.diry * cos(ROT_SPEED);
			oldPlaneX = mlx->rc.player_plane_x;
			mlx->rc.player_plane_x = mlx->rc.player_plane_x * cos(ROT_SPEED) - mlx->rc.player_plane_y * sin(ROT_SPEED);
			mlx->rc.player_plane_y = oldPlaneX * sin(ROT_SPEED) + mlx->rc.player_plane_y * cos(ROT_SPEED);
			printf("\nRot_Izquierda\n");
		}
	}
	return (0);
}