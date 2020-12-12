#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"

void	sprite_drawing(t_mlx *mlx, int i, int y)
{
	rc->stripe = rc->drawstartx;
	while (rc->stripe < rc->drawendx)
	{
		rc->sprtexx = (int)(256 * (rc->stripe - (-rc->spritewidth / 2
			+ rc->spritescreenx)) * rc->tex_width / rc->spritewidth) / 256;
		rc->tex_x = abs((int)(rc->wallx * (double)(64)));
		y = rc->drawstarty;
		if (rc->transformy > 0 && rc->stripe > 0 && rc->stripe < mlx->win_width &&
			rc->transformy < rc->spr_buffer[rc->stripe])
			while (y < rc->drawendy)
			{
				rc->d = (y) * 256 - rc->win_height * 128 + rc->spriteheight * 128;
				rc->sprtexy = ((rc->d *
				rc->tex_height) / rc->spriteheight) / 256;
				if (rc->sprite[i].tex.data[4 * (rc->sprtexx + 64 * rc->sprtexy)]
				!= (char)0)
					ft_memcpy(rc->img_data + 4 * mlx->win_width * y + rc->stripe * 4,
						&rc->sprite[i].tex.data[rc->sprtexy % rc->tex_height *
						rc->sprite[i].tex.size_l + rc->sprtexx % rc->tex_width
						* rc->sprite[i].tex.bpp / 8], sizeof(int));
				y++;
			}
		rc->stripe++;
	}
}

void	sprite_casting2(t_mlx *mlx) /*adapptation*/
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
	while (i < mlx->rc.numsprites) /*implementar variables*/
	{
		mlx->rc.sprite[i].tex = mlx->rc.tex[5];
		mlx->rc.spritex = mlx->rc.sprite[i].x + 0.5 - mlx->rc.player_pos_x;
		mlx->rc.spritey = mlx->rc.sprite[i].y + 0.5 - mlx->rc.player_pos_y;
		sprite_casting2(mlx);
		sprite_drawing(mlx, i, y);
		i++;
	}
}