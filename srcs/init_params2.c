#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"


void		reset_rc(t_mlx *mlx, t_config config)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->win_height = config.height;
	mlx->win_width = config.width;
}


void		init_position_N()
{}
void		init_position_S()
{}
void		init_position_E()
{}
void		init_position_W()
{}