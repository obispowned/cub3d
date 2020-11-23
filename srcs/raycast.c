#include <mlx.h>
#include "../header/game.h"
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



/*int		screenshot(t_mlx *mlx)
{//ADAPTAR ESTA ESTA FUNCION
	int x;

	x = 0;
	handle_events(mlx);
	mlx->img = mlx_new_image(mlx->ptr, mlx->win_height, mlx->win_width);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->linesize, &mlx->endian);
	while (x < mlx->win_height)
	{
		motionless_2(mlx, x);
		motionless_3(mlx);
//		dda(rc);
//		motionless_4(rc);
//		calcule_wall(rc);
//		floor_draw(rc, x);
//		sky_draw(rc, x);
//		draw_wall(rc, x);
//		rc->spr_buffer[x] = rc->perp_wall_dist;*/
//		x++;
//	}
//	sprite_casting(rc);
//	mlx_put_image_to_window(rc->mlx_ptr, rc->win_ptr,
//							rc->img_ptr, 0, 0);
//	save_bmp(rc);
//	return (0);
//}

/*int		raycast(t_mlx *mlx)
{
	int x;

	x = 0;
//	handle_events(rc);
	rc->img_ptr = mlx_new_image(rc->mlx_ptr, rc->win_x, rc->win_y);
	rc->img_data = mlx_get_data_addr(rc->img_ptr,
					&rc->bpp, &rc->size_line, &rc->endian);
	while (x < rc->win_x)
	{
		motionless_2(mlx, x);
		motionless_3(mlx);*/
//		dda(rc);
//		motionless_4(rc);
//		calcule_wall(rc);
//		floor_draw(rc, x);
//		sky_draw(rc, x);
//		draw_wall(rc, x);
//		rc->spr_buffer[x] = rc->perp_wall_dist;
//		x++;
//	}
//	sprite_casting(rc);
//	mlx_put_image_to_window(rc->mlx_ptr, rc->win_ptr,
//					rc->img_ptr, 0, 0);
//	return (0);
//}

/*void	raycast_2(t_mlx *mlx, int x)
{
	mlx->rc.camerax = 2 * x / (double)mlx->win_height - 1;
	mlx->rc.ray_dir_x = mlx->rc.player_dir_x + mlx->rc.player_plane_x * mlx->rc.camerax;
	mlx->rc.ray_dir_y = mlx->rc.player_dir_y + mlx ->rc.player_plane_y * mlx->rc.camerax;
	mlx->win_height = (int)mlx->rc.player_pos_x;
	mlx->win_width = (int)mlx->rc.player_pos_y;
	mlx->rc.delta_dist_x = fabs((1 / mlx->rc.ray_dir_x));
	mlx->rc.delta_dist_y = fabs((1 / mlx->rc.ray_dir_y));
	mlx->rc.hit = 0;
}*/ /*fabs: Calcula el valor absoluto del número de coma flotante, x.*/

/*void	raycast_3(t_mlx *mlx)
{
	if (mlx->rc.ray_dir_x < 0)
	{
		mlx->rc.step_x = -1;
		mlx->rc.side_dist_x = (mlx->rc.player_pos_x - mlx->win_height) * mlx->rc.delta_dist_x;
	}
	else
	{
		mlx->rc.step_x = 1;
		mlx->rc.side_dist_x = (mlx->win_height + 1.0 - mlx->rc.player_pos_x) * mlx->rc.delta_dist_x;
	}
	if (mlx->rc.ray_dir_y < 0)
	{
		mlx->rc.step_y = -1;
		mlx->rc.side_dist_y = (mlx->rc.player_pos_y - mlx->win_width) * mlx->rc.delta_dist_y;
	}
	else
	{
		mlx->rc.step_y = 1;
		mlx->rc.side_dist_y = (mlx->win_width + 1.0 - mlx->rc.player_pos_y) * mlx->rc.delta_dist_y;
	}*/
//}