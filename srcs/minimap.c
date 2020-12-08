#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"

void	draw_player(t_mlx *mlx, int num)
{
	int x;
	int y;
	int color;
	int pixel;

	color = RED;
	y = mlx->rc.player_pos_y * num - 1;
	while (y < (mlx->rc.player_pos_y * num + 1))
	{
		x = mlx->rc.player_pos_x * num - 1;
		while (x < (mlx->rc.player_pos_x * num + 1))
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
			x++;
		}
		x = 0;
		y++;
	}
}

void	draw_map(t_mlx *mlx)
{
	int y;
	int x;
	int num;
	int color;
	int pixel;

	if (2000 < mlx->win_width)
		num = 5;
	else if (1000 < mlx->win_width)
		num = 3;
	else
		num = 2;
	x = 0;
	y = 0;
	color = BLACK;
	draw_player(mlx, num);
	//printf("mapy: %d -- mapx; %d\n", mlx->rc.map_y, mlx->rc.map_x);
	while (x < mlx->rc.map_y)
	{
		while (y < mlx->rc.map_x)
		{
			if (mlx->finalMap[x][y] == 1 || mlx->finalMap[x][y] == 2)
			{
				pixel = ((y * num) * mlx->win_width + (x * num)) * 4;
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
			}
			y++;
		}
		y = 0;
		x++;
	}
}