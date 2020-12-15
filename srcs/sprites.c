#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"

void	sprite_drawing(t_mlx *mlx, int i, int y)
{
	mlx->rc.stripe = mlx->rc.drawstartx;
	while (mlx->rc.stripe < mlx->rc.drawendx)
	{
		mlx->rc.sprtexx = (int)(256 * (mlx->rc.stripe - (-mlx->rc.spritewidth / 2
			+ mlx->rc.spritescreenx)) * mlx->rc.tex_width / mlx->rc.spritewidth) / 256;
		mlx->rc.tex_x = abs((int)(mlx->rc.wallx * (double)(64)));
		y = mlx->rc.drawstarty;
		if (mlx->rc.transformy > 0 && mlx->rc.stripe > 0 && mlx->rc.stripe < mlx->win_width &&
			mlx->rc.transformy < mlx->rc.spr_buffer[mlx->rc.stripe])
			while (y < mlx->rc.drawendy)
			{
				mlx->rc.d = (y) * 256 - mlx->win_height * 128 + mlx->rc.spriteheight * 128;
				mlx->rc.sprtexy = ((mlx->rc.d *
				mlx->rc.tex_height) / mlx->rc.spriteheight) / 256;
				if (mlx->rc.sprite[i].tex.addr[4 * (mlx->rc.sprtexx + 64 * mlx->rc.sprtexy)] != (char)0)
					ft_memcpy(mlx->image.addr + 4 * mlx->win_width * y + mlx->rc.stripe * 4,
						&mlx->rc.sprite[i].tex.addr[mlx->rc.sprtexy % mlx->rc.tex_height *
						mlx->rc.sprite[i].tex.linesize + mlx->rc.sprtexx % mlx->rc.tex_width
						* mlx->rc.sprite[i].tex.bpp / 8], sizeof(int));
				y++;
			}
		mlx->rc.stripe++;
	}
}

void	sprite_casting2(t_mlx *mlx)
{
	mlx->rc.invdet = 1.0 / (mlx->rc.player_plane_x *
				mlx->rc.diry - mlx->rc.dirx * mlx->rc.player_plane_y);
	mlx->rc.transformx = mlx->rc.invdet * (mlx->rc.diry * mlx->rc.spritex - mlx->rc.dirx *
																mlx->rc.spritey);
	mlx->rc.transformy = mlx->rc.invdet * (-mlx->rc.player_plane_y * mlx->rc.spritex +
					mlx->rc.player_plane_x * mlx->rc.spritey);
	mlx->rc.spritescreenx = (int)((mlx->win_width / 2) * (1 + mlx->rc.transformx /
						mlx->rc.transformy));
	mlx->rc.spriteheight = abs((int)(mlx->win_height / (mlx->rc.transformy)));
	mlx->rc.drawstarty = -mlx->rc.spriteheight / 2 + mlx->win_height / 2;
	if (mlx->rc.drawstarty < 0)
		mlx->rc.drawstarty = 0;
	mlx->rc.drawendy = mlx->rc.spriteheight / 2 + mlx->win_height / 2;
	if (mlx->rc.drawendy >= mlx->win_height)
		mlx->rc.drawendy = mlx->win_height - 1;
	mlx->rc.spritewidth = abs((int)(mlx->win_height / (mlx->rc.transformy)));
	mlx->rc.drawstartx = -mlx->rc.spritewidth / 2 + mlx->rc.spritescreenx;
	if (mlx->rc.drawstartx < 0)
		mlx->rc.drawstartx = 0;
	mlx->rc.drawendx = mlx->rc.spritewidth / 2 + mlx->rc.spritescreenx;
	if (mlx->rc.drawendx >= mlx->win_width)
		mlx->rc.drawendx = mlx->win_width - 1;
}

void	sprite_casting(t_mlx *mlx)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (i < mlx->rc.sprites_count)
	{
		mlx->rc.sprite[i].tex = mlx->rc.tex[5];
		mlx->rc.spritex = mlx->rc.sprite[i].x + 0.5 - mlx->rc.player_pos_x;
		mlx->rc.spritey = mlx->rc.sprite[i].y + 0.5 - mlx->rc.player_pos_y;
		sprite_casting2(mlx);
		sprite_drawing(mlx, i, y);
		i++;
	}
}
