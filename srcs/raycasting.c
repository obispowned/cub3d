/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 13:49:23 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/15 13:54:43 by agutierr         ###   ########.fr       */
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
		motionless_2(mlx, x);
		motionless_3(mlx);
		dda(mlx);
		motionless_4(mlx);
		calcule_wall(mlx);
		sky_draw(mlx, x);
		floor_draw(mlx, x);
		draw_wall(mlx, x);
		mlx->rc.spr_buffer[x] = mlx->rc.perp_wall_dist;
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

void		dda(t_mlx *mlx)
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
		if (mlx->finalMap[mlx->rc.map_x][mlx->rc.map_y] == 1)
			mlx->rc.hit = 1;
	}
}

void		calcule_wall(t_mlx *mlx)
{
	mlx->rc.tex_id = mlx->finalMap[mlx->rc.map_x]
	[mlx->rc.map_y] + mlx->rc.tex_side;
	if (mlx->rc.side == 0)
		mlx->rc.wallx = mlx->rc.player_pos_y +
		mlx->rc.perp_wall_dist * mlx->rc.ray_dir_y;
	else
		mlx->rc.wallx = mlx->rc.player_pos_x +
		mlx->rc.perp_wall_dist * mlx->rc.ray_dir_x;
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

void		draw_wall(t_mlx *mlx, int x)
{
	while (mlx->rc.draw_start <= mlx->rc.draw_end)
	{
		mlx->rc.tex_y = abs((((mlx->rc.draw_start * 256 -
		mlx->win_height * 128 + mlx->rc.line_height * 128)
		* 64) / mlx->rc.line_height) / 256);
		ft_memcpy(mlx->image.addr + 4 * mlx->win_width *
		mlx->rc.draw_start + x * 4,
				&mlx->rc.tex[mlx->rc.tex_id].addr[mlx->rc.tex_y
				% mlx->rc.tex_height *
				mlx->rc.tex[mlx->rc.tex_id].linesize +
				mlx->rc.tex_x % mlx->rc.tex_width *
				mlx->rc.tex[mlx->rc.tex_id].bpp / 8], sizeof(int));
		mlx->rc.draw_start++;
	}
}
