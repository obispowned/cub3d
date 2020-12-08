#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"


int		key_press(int key, t_mlx *mlx)
{
	if (key == KEY_UP || key == KEY_W)
		mlx->rc.up = 1;
	else if (key == KEY_DOWN || key == KEY_S)
		mlx->rc.down = 1;
	else if (key == KEY_RIGHT)
		mlx->rc.rot_right = 1;
	else if (key == KEY_D)
		mlx->rc.right = 1;
	else if (key == KEY_LEFT)
		mlx->rc.rot_left = 1;
	else if (key == KEY_A)
		mlx->rc.left = 1;
	else if (key == KEY_ESC)
		close_success(rc);
	return (0);
}

int		key_release(int key, t_mlx *mlx)
{
	if (key == KEY_UP || key == KEY_W)
		mlx->rc.up = 0;
	else if (key == KEY_DOWN || key == KEY_S)
		mlx->rc.down = 0;
	else if (key == KEY_RIGHT)
		mlx->rc.rot_right = 0;
	else if (key == KEY_D)
		mlx->rc.right = 0;
	else if (key == KEY_LEFT)
		mlx->rc.rot_left = 0;
	else if (key == KEY_A)
		mlx->rc.left = 0;
	return (0);
}