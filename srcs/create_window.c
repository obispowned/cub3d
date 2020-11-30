#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"

void	game_loading(t_config config)
{
	create_window(config);
}

int		exit_game(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	exit(-1);
	return(0);
}

int		close_win(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		exit_game(mlx);
	return (0); //me da warning si no pongo return pero podriamos evitarlo.
}

void	create_window(t_config config)
{
	t_mlx mlx; // estructura que contendrá todas las "cosas MLX"

	reset_rc(&mlx.rc, config);
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window (mlx.ptr , config.height, config.width, "cub3D");
//	mlx.img = mlx_new_image (mlx.ptr , config.width, config.height);
//	mlx.addr = mlx_get_data_addr(mlx.img, mlx.bpp, &mlx.linesize, &mlx.endian);
//	my_pixel_put();

//	if (config.save == 1) //si hay --save
//		mlx_loop_hook(mlx.ptr, &screenshot_1, &mlx.rc);
//	else
//		mlx_loop_hook(rc.mlx_ptr, &raycasting_1, &rc);
	mlx_hook(mlx.win, 17, 1L << 17, exit_game, &mlx); //cerramos ventana al dar a la "equis"
	mlx_key_hook(mlx.win, close_win, &mlx);
	mlx_loop(mlx.ptr);


}