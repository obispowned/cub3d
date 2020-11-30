#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"
#include <math.h>

void		reset_rc(t_mlx *mlx, t_config config)
{
	mlx->rc.player_pos_x = config.player_begin[0];
	mlx->rc.player_pos_y = config.player_begin[1];
	mlx->rc.player_dir_x = -1;
	mlx->rc.player_dir_y = 0;
	mlx->rc.player_plane_x = 0;
	mlx->rc.player_plane_y = 0.66;
	mlx->win_height = config.height;
	mlx->win_width = config.width;
}

int		screenshot_1(t_mlx *mlx, t_config *config)
{
	int x;

	x = 0;
	handle_events(mlx, config);
	mlx->img = mlx_new_image(mlx->ptr, mlx->win_height, mlx->win_width);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->linesize, &mlx->endian);
	while (x < mlx->win_width)
	{
		raycast_2(mlx, x);
		raycast_3(mlx);
		dda(mlx, config);
		raycast_4(mlx);
		calcule_wall(mlx, config);
		floor_draw(mlx, x);
		sky_draw(mlx, x);
		draw_wall(mlx, x);
		mlx->rc.spr_buffer[x] = mlx->rc.perp_wall_dist;
		x++;
	}
	sprite_casting(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0, 0);
	save_bmp(mlx);
	return (0);
}

int		raycast_1(t_mlx *mlx, t_config *config)
{
	int x;

	x = 0;
	handle_events(mlx, config);
	mlx->img = mlx_new_image(mlx->ptr, mlx->win_height, mlx->win_width);
	mlx->addr = mlx_get_data_addr(mlx->img,	&mlx->bpp, &mlx->linesize, &mlx->endian);
	while (x < mlx->win_width)
	{
		raycast_2(mlx, x);
		raycast_3(mlx);
		dda(mlx, config);
		raycast_4(mlx);
		calcule_wall(mlx, config);
		floor_draw(mlx, x);
		sky_draw(mlx, x);
		draw_wall(mlx, x);
		mlx->rc.spr_buffer[x] = mlx->rc.perp_wall_dist;
		x++;
	}
	sprite_casting(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win,	mlx->img, 0, 0);
	return (0);
}

void	raycast_2(t_mlx *mlx, int x)
{
	mlx->rc.camerax = 2 * x / (double)mlx->win_width - 1;
	mlx->rc.ray_dir_x = mlx->rc.player_dir_x + mlx->rc.player_plane_x * mlx->rc.camerax;
	mlx->rc.ray_dir_y = mlx->rc.player_dir_y + mlx ->rc.player_plane_y * mlx->rc.camerax;
	mlx->win_width = (int)mlx->rc.player_pos_x;
	mlx->win_height = (int)mlx->rc.player_pos_y;
	mlx->rc.delta_dist_x = fabs((1 / mlx->rc.ray_dir_x));
	mlx->rc.delta_dist_y = fabs((1 / mlx->rc.ray_dir_y));
	mlx->rc.hit = 0;
} /*fabs: Calcula el valor absoluto del número de coma flotante, x.*/

void	raycast_3(t_mlx *mlx)
{
	if (mlx->rc.ray_dir_x < 0)
	{
		mlx->rc.step_x = -1;
		mlx->rc.side_dist_x = (mlx->rc.player_pos_x - mlx->win_width) * mlx->rc.delta_dist_x;
	}
	else
	{
		mlx->rc.step_x = 1;
		mlx->rc.side_dist_x = (mlx->win_width + 1.0 - mlx->rc.player_pos_x) * mlx->rc.delta_dist_x;
	}
	if (mlx->rc.ray_dir_y < 0)
	{
		mlx->rc.step_y = -1;
		mlx->rc.side_dist_y = (mlx->rc.player_pos_y - mlx->win_height) * mlx->rc.delta_dist_y;
	}
	else
	{
		mlx->rc.step_y = 1;
		mlx->rc.side_dist_y = (mlx->win_height + 1.0 - mlx->rc.player_pos_y) * mlx->rc.delta_dist_y;
	}
}

void	raycast_4(t_mlx *mlx)
{
	if (mlx->rc.side == 0)
		mlx->rc.perp_wall_dist = (mlx->rc.map_x - mlx->rc.player_pos_x + (1 - mlx->rc.step_x) / 2) / mlx->rc.ray_dir_x;
	else
		mlx->rc.perp_wall_dist = (mlx->rc.map_y - mlx->rc.player_pos_y + (1 - mlx->rc.step_y) / 2) / mlx->rc.ray_dir_y;
	mlx->rc.line_height = (int)(mlx->win_height / mlx->rc.perp_wall_dist);
	mlx->rc.draw_start = - mlx->rc.line_height / 2 + mlx->win_height / 2;
	if (mlx->rc.draw_start < 0)
		mlx->rc.draw_start = 0;
	mlx->rc.draw_end = mlx->rc.line_height / 2 + mlx->win_height / 2;
	if (mlx->rc.draw_end >= mlx->win_height)
		mlx->rc.draw_end = mlx->win_height - 1;
}