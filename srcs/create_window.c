#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"

void	game_loading(t_config config)
{
	t_mlx *mlx;

	reset_rc(mlx, config);
	create_window(mlx, config);
}

int		exit_game(t_mlx *mlx)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	free(mlx->ptr);
	exit(-1);
	return(0);
}

int		close_win(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		exit_game(mlx);
	return (0); //me da warning si no pongo return pero podriamos evitarlo.
}

void	create_window(t_mlx *mlx, t_config config)
{
	system("leaks cub3D");
	if (!(mlx->ptr = mlx_init()))
		print_error("Inicio de Minilibx fallida\n");
//	if (!(mlx->win = mlx_new_window(mlx->ptr, 500, 500, "CUB3D")))
//		print_error("Fallo al abrir la ventana\n");
//	if (config.save == 1) //si hay --save
//	{
//		mlx_loop_hook(mlx.ptr, &screenshot_1, &mlx.rc);
//	}
//	else
//	{
//		mlx_loop_hook(mlx.ptr, &raycast_1, &mlx);
//	}
//	mlx_hook(mlx->win, 17, 1L << 17, exit_game, mlx); //cerramos ventana al dar a la "equis"
//	mlx_key_hook(mlx->win, close_win, mlx);
	mlx_loop(mlx->ptr);
}