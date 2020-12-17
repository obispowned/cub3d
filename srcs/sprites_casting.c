/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_casting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 09:43:17 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/17 09:43:49 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"

void			sprite_casting2(t_mlx *mlx)
{
	mlx->rc.invdet = 1.0 / (mlx->rc.player_plane_x *
				mlx->rc.diry - mlx->rc.dirx * mlx->rc.player_plane_y);
	mlx->rc.transformx = mlx->rc.invdet * (mlx->rc.diry *
	mlx->rc.spritex - mlx->rc.dirx * mlx->rc.spritey);
	mlx->rc.transformy = mlx->rc.invdet * (-mlx->rc.player_plane_y *
	mlx->rc.spritex + mlx->rc.player_plane_x * mlx->rc.spritey);
	mlx->rc.spritescreenx = (int)((mlx->win_width / 2) *
	(1 + mlx->rc.transformx / mlx->rc.transformy));
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

void			sprite_casting(t_mlx *mlx)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (i < mlx->rc.sprites_count)
	{
		mlx->rc.sprite[i].tex = mlx->rc.tex[5];
		mlx->rc.spritex = mlx->rc.sprite[i].x - mlx->rc.player_pos_x;
		mlx->rc.spritey = mlx->rc.sprite[i].y - mlx->rc.player_pos_y;
		sprite_casting2(mlx);
		sprite_drawing(mlx, i, y);
		i++;
	}
}
