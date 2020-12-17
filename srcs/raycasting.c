/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 13:49:23 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/17 09:26:15 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"

int			raycasting(t_mlx *mlx)
{
	int		x;

	x = 0;
	handle_events(mlx);
	if (mlx->image.img)
		mlx_destroy_image(mlx->ptr, mlx->image.img);
	mlx->image.img = mlx_new_image(mlx->ptr, mlx->win_width, mlx->win_height);
	mlx->image.addr = mlx_get_data_addr(mlx->image.img,
	&mlx->image.bpp, &mlx->image.linesize, &mlx->image.endian);
	while (x < mlx->win_width)
	{
		raycasting2(mlx, x);
		x++;
	}
	sprite_casting(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->image.img, 0, 0);
	if (mlx->rc.savebpm == 1 && mlx->flag_bmp == 0)
	{
		mlx->flag_bmp = 1;
		save_bmp(mlx);
	}
	return (0);
}

void		raycasting2(t_mlx *mlx, int x)
{
	motionless_2(mlx, x);
	motionless_3(mlx);
	dda(mlx);
	motionless_4(mlx);
	calcule_wall(mlx);
	sky_draw(mlx, x);
	floor_draw(mlx, x);
	draw_wall(mlx, x);
	mlx->rc.spr_buffer[x] = mlx->rc.perp_wall_dist;
}

void		motionless_2(t_mlx *mlx, int x)
{
	mlx->rc.camerax = 2 * x / (double)mlx->win_width - 1;
	mlx->rc.ray_dir_x = mlx->rc.dirx + mlx->rc.player_plane_x * mlx->rc.camerax;
	mlx->rc.ray_dir_y = mlx->rc.diry + mlx->rc.player_plane_y * mlx->rc.camerax;
	mlx->rc.map_x = (int)mlx->rc.player_pos_x;
	mlx->rc.map_y = (int)mlx->rc.player_pos_y;
	mlx->rc.delta_dist_x = fabs((1 / mlx->rc.ray_dir_x));
	mlx->rc.delta_dist_y = fabs((1 / mlx->rc.ray_dir_y));
	mlx->rc.hit = 0;
}

void		motionless_3(t_mlx *mlx)
{
	if (mlx->rc.ray_dir_x < 0)
	{
		mlx->rc.step_x = -1;
		mlx->rc.side_dist_x = (mlx->rc.player_pos_x - mlx->rc.map_x)
		* mlx->rc.delta_dist_x;
	}
	else
	{
		mlx->rc.step_x = 1;
		mlx->rc.side_dist_x = (mlx->rc.map_x + 1.0 - mlx->rc.player_pos_x)
		* mlx->rc.delta_dist_x;
	}
	if (mlx->rc.ray_dir_y < 0)
	{
		mlx->rc.step_y = -1;
		mlx->rc.side_dist_y = (mlx->rc.player_pos_y - mlx->rc.map_y)
		* mlx->rc.delta_dist_y;
	}
	else
	{
		mlx->rc.step_y = 1;
		mlx->rc.side_dist_y = (mlx->rc.map_y + 1.0 - mlx->rc.player_pos_y)
		* mlx->rc.delta_dist_y;
	}
}

void		motionless_4(t_mlx *mlx)
{
	if (mlx->rc.side == 0)
		mlx->rc.perp_wall_dist = (mlx->rc.map_x -
		mlx->rc.player_pos_x + (1 - mlx->rc.step_x) / 2) / mlx->rc.ray_dir_x;
	else
		mlx->rc.perp_wall_dist = (mlx->rc.map_y -
		mlx->rc.player_pos_y + (1 - mlx->rc.step_y) / 2) / mlx->rc.ray_dir_y;
	mlx->rc.line_height = (int)(mlx->win_height / mlx->rc.perp_wall_dist);
	mlx->rc.draw_start = -mlx->rc.line_height / 2 + mlx->win_height / 2;
	if (mlx->rc.draw_start < 0)
		mlx->rc.draw_start = 0;
	mlx->rc.draw_end = mlx->rc.line_height / 2 + mlx->win_height / 2;
	if (mlx->rc.draw_end >= mlx->win_height)
		mlx->rc.draw_end = mlx->win_height - 1;
}
