#include <mlx.h>
#include "../header/game.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{	//color hemos de pasarlo como hexadecimal /*https://htmlcolorcodes.com/es/*/
    char    *dst;

    dst = mlx->addr + (y * mlx->linesize + x * (mlx->bpp / 8));
    *(unsigned int*)dst = color;
}