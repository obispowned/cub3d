#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"

void	sky_draw(t_mlx *mlx, int x)
{
	int y;
	int pixel;
	int color;

	y = 0;
	color = 0xFFFF00;
	//mlx->rc.draw_start = 300;
	while (y < mlx->rc.draw_start)
	{
		pixel = (y * mlx->win_width + x) * 4;
		if (mlx->image.endian == 1)
		{
			mlx->image.addr[pixel + 0] = (color >> 24);
			mlx->image.addr[pixel + 1] = (color >> 16) & 0xFF;
			mlx->image.addr[pixel + 2] = (color >> 8) & 0xFF;
			mlx->image.addr[pixel + 3] = (color) & 0xFF;
		}
		else if (mlx->image.endian == 0)
		{
			mlx->image.addr[pixel + 0] = (color) & 0xFF;
			mlx->image.addr[pixel + 1] = (color >> 8) & 0xFF;
			mlx->image.addr[pixel + 2] = (color >> 16) & 0xFF;
			mlx->image.addr[pixel + 3] = (color >> 24);
		}
		y++;
	}
}
void	floor_draw(t_mlx *mlx, int x)
{
	int y;
	int pixel;
	int color;

	y = mlx->rc.draw_end;
	color = 0xFF0000;
	//mlx->rc.draw_start = 300;
	while (y < mlx->win_height)
	{
		pixel = (y * mlx->win_width + x) * 4;
		if (mlx->image.endian == 1)
		{
			mlx->image.addr[pixel + 0] = (color >> 24);
			mlx->image.addr[pixel + 1] = (color >> 16) & 0xFF;
			mlx->image.addr[pixel + 2] = (color >> 8) & 0xFF;
			mlx->image.addr[pixel + 3] = (color) & 0xFF;
		}
		else if (mlx->image.endian == 0)
		{
			mlx->image.addr[pixel + 0] = (color) & 0xFF;
			mlx->image.addr[pixel + 1] = (color >> 8) & 0xFF;
			mlx->image.addr[pixel + 2] = (color >> 16) & 0xFF;
			mlx->image.addr[pixel + 3] = (color >> 24);
		}
		y++;
	}
}

int raycasting(int key, t_mlx *mlx)
{
	int x;

	x = 0;
	printf("Funciona Raycasting\n");
	mlx->win_width = 500;
	mlx->win_height = 500;
	printf("----%d",mlx->rc.player_pos_x);/****PASAR A DOUBLE****/
	if (handle_events(key, mlx) != 0)
		return (-1);
	mlx->image.img = mlx_new_image(mlx->ptr, mlx->win_height, mlx->win_width); //cuidao x y
	mlx->image.addr = mlx_get_data_addr(mlx->image.img, &mlx->image.bpp, &mlx->image.linesize, &mlx->image.endian);
	
	while (x < mlx->win_height)
	{
		motionless_2(mlx, x);
		motionless_3(mlx);
		dda(mlx);
		motionless_4(mlx);
		calcule_wall(mlx);
		sky_draw(mlx,x);
		floor_draw(mlx,x);
		//draw_wall(mlx, x); /*SEG FAULT LINUX*/
		x++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->image.img, 0, 0);
	return (0);
}

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
	if (key == KEY_DOWN || key == KEY_UP || key == KEY_RIGHT || key == KEY_LEFT)
	{
		if (key == KEY_UP)
		{
			if (mlx->finalMap[(int)(mlx->rc.player_pos_x + mlx->rc.dirx *
			mlx->rc.movespeed)][(int)(mlx->rc.player_pos_y)] == 0)
				mlx->rc.player_pos_x += mlx->rc.dirx * mlx->rc.movespeed;
			if (mlx->finalMap[(int)(mlx->rc.player_pos_x)][(int)(mlx->rc.player_pos_y + mlx->rc.diry *
			mlx->rc.movespeed)] == 0)
				mlx->rc.player_pos_y += mlx->rc.diry * mlx->rc.movespeed;
				printf("\nArriba\n");
		}
		if (key == KEY_DOWN)
		{
			if (mlx->finalMap[(int)(mlx->rc.player_pos_x - mlx->rc.dirx * MV_SPEED)][(int)(mlx->rc.player_pos_y)] == 0)
				mlx->rc.player_pos_x -= mlx->rc.dirx * MV_SPEED;
			if (mlx->finalMap[(int)(mlx->rc.player_pos_x)][(int)(mlx->rc.player_pos_y - mlx->rc.diry * MV_SPEED)] == 0)
				mlx->rc.player_pos_y -= mlx->rc.diry * MV_SPEED;
				printf("\nAbajo\n");
		}
		if (key == KEY_RIGHT)
		{
			oldDirX = mlx->rc.dirx;
			mlx->rc.dirx = mlx->rc.dirx * cos(-ROT_SPEED) - mlx->rc.diry * sin(-ROT_SPEED);
			mlx->rc.diry = oldDirX * sin(-ROT_SPEED) + mlx->rc.diry * cos(-ROT_SPEED);
			oldPlaneX = mlx->rc.player_plane_x;
			mlx->rc.player_plane_x = mlx->rc.player_plane_x * cos(-ROT_SPEED) - mlx->rc.player_plane_y * sin(-ROT_SPEED);
			mlx->rc.player_plane_y = oldPlaneX * sin(-ROT_SPEED) + mlx->rc.player_plane_y * cos(-ROT_SPEED);
			printf("Derecha\n");
		}
		if (key == KEY_LEFT)
		{
			oldDirX = mlx->rc.dirx;
			mlx->rc.dirx = mlx->rc.dirx * cos(ROT_SPEED) - mlx->rc.diry * sin(ROT_SPEED);
			mlx->rc.diry = oldDirX * sin(ROT_SPEED) + mlx->rc.diry * cos(ROT_SPEED);
			oldPlaneX = mlx->rc.player_plane_x;
			mlx->rc.player_plane_x = mlx->rc.player_plane_x * cos(ROT_SPEED) - mlx->rc.player_plane_y * sin(ROT_SPEED);
			mlx->rc.player_plane_y = oldPlaneX * sin(ROT_SPEED) + mlx->rc.player_plane_y * cos(ROT_SPEED);
			printf("\nIzquierda\n");
		}
	}
	return (0);
}

static void motionless_2(t_mlx *mlx, int x)
{
	mlx->rc.camerax = 2 * x / (double)mlx->win_height - 1;
	mlx->rc.ray_dir_x = mlx->rc.dirx + mlx->rc.player_plane_x * mlx->rc.camerax;
	mlx->rc.ray_dir_y = mlx->rc.diry + mlx->rc.player_plane_y * mlx->rc.camerax;
	mlx->rc.map_x = (int)mlx->rc.player_pos_x;
	mlx->rc.map_y = (int)mlx->rc.player_pos_y;
	mlx->rc.delta_dist_x = fabs((1 / mlx->rc.ray_dir_x));
	mlx->rc.delta_dist_y = fabs((1 / mlx->rc.ray_dir_y));
	mlx->rc.hit = 0;
}

static void motionless_3(t_mlx *mlx)
{
	if (mlx->rc.ray_dir_x < 0)
	{
		mlx->rc.step_x = -1;
		mlx->rc.side_dist_x = (mlx->rc.player_pos_x - mlx->rc.map_x) * mlx->rc.delta_dist_x;
	}
	else
	{
		mlx->rc.step_x = 1;
		mlx->rc.side_dist_x = (mlx->rc.map_x + 1.0 - mlx->rc.player_pos_x) * mlx->rc.delta_dist_x;
	}
	if (mlx->rc.ray_dir_y < 0)
	{
		mlx->rc.step_y = -1;
		mlx->rc.side_dist_y = (mlx->rc.player_pos_y - mlx->rc.map_y) * mlx->rc.delta_dist_y;
	}
	else
	{
		mlx->rc.step_y = 1;
		mlx->rc.side_dist_y = (mlx->rc.map_y + 1.0 - mlx->rc.player_pos_y) * mlx->rc.delta_dist_y;
	}
}

static void dda(t_mlx *mlx)
{
	while (mlx->rc.hit == 0)
	{
		if (mlx->rc.side_dist_x < mlx->rc.side_dist_y)
		{
			mlx->rc.side_dist_x += mlx->rc.delta_dist_x;
			mlx->rc.map_x += mlx->rc.step_x;
			mlx->rc.side = 0;
		}
		else
		{
			mlx->rc.side_dist_y += mlx->rc.delta_dist_y;
			mlx->rc.map_y += mlx->rc.step_y;
			mlx->rc.side = 1;
		}
		if (mlx->finalMap[mlx->rc.map_x][mlx->rc.map_y] > 0)
			mlx->rc.hit = 1;
	}
}

static void motionless_4(t_mlx *mlx)
{
	if (mlx->rc.side == 0)
		mlx->rc.perp_wall_dist = (mlx->rc.map_x - mlx->rc.player_pos_x + (1 - mlx->rc.step_x) / 2) / mlx->rc.ray_dir_x;
	else
		mlx->rc.perp_wall_dist = (mlx->rc.map_y - mlx->rc.player_pos_y + (1 - mlx->rc.step_y) / 2) / mlx->rc.ray_dir_y;
	mlx->rc.line_height = (int)(mlx->win_height / mlx->rc.perp_wall_dist);
	mlx->rc.draw_start = -mlx->rc.line_height / 2 + mlx->win_width / 2;
	if (mlx->rc.draw_start < 0)
		mlx->rc.draw_start = 0;
	mlx->rc.draw_end = mlx->rc.line_height / 2 + mlx->win_width / 2;
	if (mlx->rc.draw_end >= mlx->win_width)
		mlx->rc.draw_end = mlx->win_height - 1;
	mlx->rc.textnum = mlx->finalMap[mlx->rc.map_x][mlx->rc.map_y] - 1;
}

void calcule_wall(t_mlx *mlx)
{
//	mlx->rc.tex_id = mlx->finalMap[mlx->rc.map_x][mlx->rc.map_y] + mlx->rc.tex_side;
	if (mlx->rc.side == 0)
		mlx->rc.wallx = mlx->rc.player_pos_y + mlx->rc.perp_wall_dist * mlx->rc.ray_dir_y;
	else
		mlx->rc.wallx = mlx->rc.player_pos_x + mlx->rc.perp_wall_dist * mlx->rc.ray_dir_x;
	mlx->rc.wallx -= floor(mlx->rc.wallx);
	mlx->rc.tex_x = abs((int)(mlx->rc.wallx * (double)(64)));
}

void draw_wall(t_mlx *mlx, int x)
{
	while (mlx->rc.draw_start <= mlx->rc.draw_end)
	{
		//mlx->rc.tex_y = abs((((mlx->rc.draw_start * 256 - mlx->win_width * 128 +
		//mlx->rc.line_height * 128) * 64) / mlx->rc.line_height) / 256); /*SEG FAULT*/
		/*printf("\nheight %d | draw_start %d | texy %d | texheight %d | linesize %d | tex_x %d |  texwidth %d | bpp %d",
		mlx->win_height, mlx->rc.draw_start, mlx->rc.tex_y, mlx->rc.tex_height, mlx->rc.tex[1].linesize,
		mlx->rc.tex_x, mlx->rc.tex_width, mlx->rc.tex[1].bpp);*/
		/*ft_memcpy(mlx->image.addr + 4 * mlx->win_height * mlx->rc.draw_start + x * 4,
				  &mlx->rc.tex[1].addr[mlx->rc.tex_y % mlx->rc.tex_height *
									   mlx->rc.tex[1].linesize +
								   mlx->rc.tex_x % mlx->rc.tex_width *
									   mlx->rc.tex[1].bpp / 8], sizeof(int));*/
				 /*SEG FAULT LINUX EN MEMCPY*/
		mlx->rc.draw_start++;
	}
}
