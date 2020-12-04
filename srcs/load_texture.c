#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"

void load_textures(t_mlx *mlx)
{
	mlx->rc.tex[1].img = mlx_xpm_file_to_image(mlx->ptr, "textures/stone.xpm",
			&mlx->rc.tex_width, &mlx->rc.tex_height);
//	mlx->rc.tex[1].addr = mlx_get_data_addr(mlx->rc.tex[1].img, &mlx->rc.tex[1].bpp,
//			&mlx->rc.tex[1].linesize, &mlx->rc.tex[1].endian);
	mlx->rc.tex[2].img = mlx_xpm_file_to_image(mlx->ptr, "textures/mossy.xpm",
			&mlx->rc.tex_width, &mlx->rc.tex_height);
//	mlx->rc.tex[2].addr = mlx_get_data_addr(mlx->rc.tex[2].img, &mlx->rc.tex[2].bpp,
//			&mlx->rc.tex[2].linesize, &mlx->rc.tex[2].endian);
	mlx->rc.tex[3].img = mlx_xpm_file_to_image(mlx->ptr, "textures/redbrick.xpm",
			&mlx->rc.tex_width, &mlx->rc.tex_height);
//	mlx->rc.tex[3].addr = mlx_get_data_addr(mlx->rc.tex[3].img, &mlx->rc.tex[3].bpp,
//			&mlx->rc.tex[3].linesize, &mlx->rc.tex[3].endian);
	mlx->rc.tex[4].img = mlx_xpm_file_to_image(mlx->ptr, "textures/wood.xpm",
			&mlx->rc.tex_width, &mlx->rc.tex_height);
//	mlx->rc.tex[4].addr = mlx_get_data_addr(mlx->rc.tex[4].img, &mlx->rc.tex[4].bpp,
//			&mlx->rc.tex[4].linesize, &mlx->rc.tex[4].endian);
	mlx->rc.tex[5].img = mlx_xpm_file_to_image(mlx->ptr, "sprites/pillar.xpm",
			&mlx->rc.tex_width, &mlx->rc.tex_height);
//	mlx->rc.tex[5].addr = mlx_get_data_addr(mlx->rc.tex[5].img, &mlx->rc.tex[5].bpp,
//			&mlx->rc.tex[5].linesize, &mlx->rc.tex[5].endian);
	load_textures_2(mlx);
}

static void load_textures_2(t_mlx *mlx)
{
	mlx->rc.tex[6].img = mlx_xpm_file_to_image(mlx->ptr, "sprites/barrel.xpm",
			&mlx->rc.tex_width, &mlx->rc.tex_height);
//	mlx->rc.tex[6].addr = mlx_get_data_addr(mlx->rc.tex[6].img, &mlx->rc.tex[6].bpp,
//			&mlx->rc.tex[6].linesize, &mlx->rc.tex[6].endian);
	mlx->rc.tex[7].img = mlx_xpm_file_to_image(mlx->ptr, "sprites/light.xpm",
			&mlx->rc.tex_width, &mlx->rc.tex_height);
//	mlx->rc.tex[7].addr = mlx_get_data_addr(mlx->rc.tex[7].img, &mlx->rc.tex[7].bpp,
//			&mlx->rc.tex[7].linesize, &mlx->rc.tex[7].endian);
	mlx->rc.tex[8].img = mlx_xpm_file_to_image(mlx->ptr, "sprites/ghostred.xpm",
			&mlx->rc.tex_width, &mlx->rc.tex_height);
//	mlx->rc.tex[8].addr = mlx_get_data_addr(mlx->rc.tex[8].img, &mlx->rc.tex[8].bpp,
//			&mlx->rc.tex[8].linesize, &mlx->rc.tex[8].endian);
	mlx->rc.tex[9].img = mlx_xpm_file_to_image(mlx->ptr, "sprites/destruction.xpm",
			&mlx->rc.tex_width, &mlx->rc.tex_height);
//	mlx->rc.tex[9].addr = mlx_get_data_addr(mlx->rc.tex[9].img, &mlx->rc.tex[9].bpp,
//			&mlx->rc.tex[9].linesize, &mlx->rc.tex[9].endian);
	mlx->rc.tex[10].img = mlx_xpm_file_to_image(mlx->ptr, "sprites/dead.xpm",
			&mlx->rc.tex_width, &mlx->rc.tex_height);
//	mlx->rc.tex[10].addr = mlx_get_data_addr(mlx->rc.tex[10].img, &mlx->rc.tex[10].bpp,
//			&mlx->rc.tex[10].linesize, &mlx->rc.tex[10].endian);
}