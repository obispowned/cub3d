#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"


void		reset_mlx(t_mlx *mlx, t_config config)
{
	mlx->ptr = NULL;
	mlx->win = NULL;
	mlx->win_height = config.height;
	mlx->win_width = config.width;
	mlx->finalMap = config.mapa.worldMap;
}


void		init_position_N()
{}
void		init_position_S()
{}
void		init_position_E()
{}
void		init_position_W()
{}