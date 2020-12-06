#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"

void	sky_draw(t_mlx *mlx, int x)
{
	int y;
	int pixel;
	int color;

	y = 0;
	color = 0x00aae4;
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
	color = 0xD7D0B7;
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
