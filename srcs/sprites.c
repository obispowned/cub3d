/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 13:08:31 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/17 09:44:11 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"

void			sprite_drawing(t_mlx *mlx, int i, int y)
{
	sprite_order(mlx);
	mlx->rc.stripe = mlx->rc.drawstartx;
	while (mlx->rc.stripe < mlx->rc.drawendx)
	{
		mlx->rc.sprtexx = (int)(256 * (mlx->rc.stripe -
		(-mlx->rc.spritewidth / 2 + mlx->rc.spritescreenx))
		* mlx->rc.tex_width / mlx->rc.spritewidth) / 256;
		mlx->rc.tex_x = abs((int)(mlx->rc.wallx * (double)(64)));
		y = mlx->rc.drawstarty;
		if (mlx->rc.transformy > 0 && mlx->rc.stripe > 0 &&
		mlx->rc.stripe < mlx->win_width && mlx->rc.transformy
		< mlx->rc.spr_buffer[mlx->rc.stripe])
			while (y < mlx->rc.drawendy)
			{
				sprite_drawing2(mlx, i, y);
				y++;
			}
		mlx->rc.stripe++;
	}
}

void			sprite_drawing2(t_mlx *mlx, int i, int y)
{
	mlx->rc.d = (y) * 256 - mlx->win_height * 128 + mlx->rc.spriteheight * 128;
	mlx->rc.sprtexy = ((mlx->rc.d *
	mlx->rc.tex_height) / mlx->rc.spriteheight) / 256;
	if (mlx->rc.sprite[i].tex.addr[4 * (mlx->rc.sprtexx + 64 *
	mlx->rc.sprtexy)] != (char)0)
		ft_memcpy(mlx->image.addr + 4 * mlx->win_width * y + mlx->rc.stripe * 4,
		&mlx->rc.sprite[i].tex.addr[mlx->rc.sprtexy % mlx->rc.tex_height *
		mlx->rc.sprite[i].tex.linesize + mlx->rc.sprtexx % mlx->rc.tex_width
		* mlx->rc.sprite[i].tex.bpp / 8], sizeof(int));
}

void			sprite_order(t_mlx *mlx)
{
	int			i;
	int			j;
	t_sprite	tmp;

	sprite_preorder(mlx);
	i = 0;
	while (i < mlx->rc.sprites_count)
	{
		j = i + 1;
		while (j < mlx->rc.sprites_count)
		{
			if (mlx->rc.sprite[i].dist < mlx->rc.sprite[j].dist && (i != 0))
			{
				tmp = mlx->rc.sprite[i];
				mlx->rc.sprite[i] = mlx->rc.sprite[j];
				mlx->rc.sprite[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void			sprite_preorder(t_mlx *mlx)
{
	int			i;

	i = 0;
	while (i < mlx->rc.sprites_count)
	{
		mlx->rc.sprite[i].dist = pow((mlx->rc.player_pos_x -
		mlx->rc.sprite[i].x), 2) + pow((mlx->rc.player_pos_y -
		mlx->rc.sprite[i].y), 2);
		i++;
	}
}
