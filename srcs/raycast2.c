#include <mlx.h>
#include <math.h>
#include "../header/game.h"
#include "../header/cub3d.h"

void	dda(t_mlx *mlx, t_config *config)
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
		if (config->mapa.worldMap[mlx->rc.map_x][mlx->rc.map_y] > 0)
			mlx->rc.hit = 1;
	}
}

void	sky_draw(t_mlx *mlx, int x)
{
	int y;
	int pixel;
	int color;

	y = 0;
	color = mlx->rc.hexaceil; //HEXADECIMAL
	while (y < mlx->rc.draw_start)
	{
		pixel = (y * mlx->win_width + x) * 4;
		if (mlx->endian == 1)
		{
			mlx->addr[pixel + 0] = (color >> 24);
			mlx->addr[pixel + 1] = (color >> 16) & 0xFF;
			mlx->addr[pixel + 2] = (color >> 8) & 0xFF;
			mlx->addr[pixel + 3] = (color) & 0xFF;
		}
		else if (mlx->endian == 0)
		{
			mlx->addr[pixel + 0] = (color) & 0xFF;
			mlx->addr[pixel + 1] = (color >> 8) & 0xFF;
			mlx->addr[pixel + 2] = (color >> 16) & 0xFF;
			mlx->addr[pixel + 3] = (color >> 24);
		}
		y++;
	}
}

void	floor_draw(t_mlx *mlx, int x)
{
	int y;
	int pixel;
	int color;

	color = mlx->rc.hexafloor;
	y = mlx->rc.draw_start;
	while (y < mlx->win_height)
	{
		pixel = (y * mlx->win_width + x) * 4;
		if (mlx->endian == 1)
		{
			mlx->addr[pixel + 0] = (color >> 24);
			mlx->addr[pixel + 1] = (color >> 16) & 0xFF;
			mlx->addr[pixel + 2] = (color >> 8) & 0xFF;
			mlx->addr[pixel + 3] = (color) & 0xFF;
		}
		else if (mlx->endian == 0)
		{
			mlx->addr[pixel + 0] = (color) & 0xFF;
			mlx->addr[pixel + 1] = (color >> 8) & 0xFF;
			mlx->addr[pixel + 2] = (color >> 16) & 0xFF;
			mlx->addr[pixel + 3] = (color >> 24);
		}
		y++;
	}
}

void	draw_wall(t_mlx *mlx, int x)
{
	while (mlx->rc.draw_start <= mlx->rc.draw_end)
	{
		mlx->rc.tex_y = abs((((mlx->rc.draw_start * 256 - mlx->win_width * 128 + mlx->rc.line_height * 128) * 64) / mlx->rc.line_height) / 256);
		ft_memcpy(mlx->addr + 4 * mlx->win_height * mlx->rc.draw_start + x * 4, &mlx->rc.tex[mlx->rc.tex_id].data[mlx->rc.tex_y %
		mlx->rc.tex_height * mlx->rc.tex[mlx->rc.tex_id].size_l + mlx->rc.tex_x % mlx->rc.tex_width * mlx->rc.tex[mlx->rc.tex_id].bpp / 8], sizeof(int));
		mlx->rc.draw_start++;
	}
}

void	calcule_wall(t_mlx *mlx, t_config *config)
{
	mlx->rc.tex_id = config->mapa.worldMap[mlx->rc.map_x][mlx->rc.map_y] + mlx->rc.tex_side;
	if (mlx->rc.side == 0)
		mlx->rc.wallx = mlx->rc.player_pos_y + mlx->rc.perp_wall_dist * mlx->rc.ray_dir_y;
	else
		mlx->rc.wallx = mlx->rc.player_pos_x + mlx->rc.perp_wall_dist * mlx->rc.ray_dir_x;
	mlx->rc.wallx -= floor(mlx->rc.wallx);
	mlx->rc.tex_x = abs((int)(mlx->rc.wallx * (double)(64)));
	if (mlx->rc.side == 0 && mlx->rc.ray_dir_x > 0)
		mlx->rc.tex_side = 1;
	else if (mlx->rc.side == 0 && mlx->rc.ray_dir_x < 0)
		mlx->rc.tex_side = 0;
	else if (mlx->rc.side == 1 && mlx->rc.ray_dir_y > 0)
		mlx->rc.tex_side = 2;
	else
		mlx->rc.tex_side = 3;
	if (mlx->rc.draw_end < 0)
		mlx->rc.draw_end = mlx->win_height;
}