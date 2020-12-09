#include <mlx.h>
#include <math.h>
#include "../header/game.h"
#include "../header/cub3d.h"

void load_textures(t_mlx *mlx, t_config *config)
{
	if(!(mlx->rc.tex[1].img = mlx_xpm_file_to_image(mlx->ptr, config->NO,
			&mlx->rc.tex_width, &mlx->rc.tex_height)))
			print_error("Textura NO no existe");
	mlx->rc.tex[1].addr = mlx_get_data_addr(mlx->rc.tex[1].img, &mlx->rc.tex[1].bpp,
			&mlx->rc.tex[1].linesize, &mlx->rc.tex[1].endian);
	if(!(mlx->rc.tex[2].img = mlx_xpm_file_to_image(mlx->ptr, config->SO,
			&mlx->rc.tex_width, &mlx->rc.tex_height)))
			print_error("Textura SO no existe");
	mlx->rc.tex[2].addr = mlx_get_data_addr(mlx->rc.tex[2].img, &mlx->rc.tex[2].bpp,
			&mlx->rc.tex[2].linesize, &mlx->rc.tex[2].endian);
	if(!(mlx->rc.tex[3].img = mlx_xpm_file_to_image(mlx->ptr, config->WE,
			&mlx->rc.tex_width, &mlx->rc.tex_height)))
			print_error("Textura WE no existe");
	mlx->rc.tex[3].addr = mlx_get_data_addr(mlx->rc.tex[3].img, &mlx->rc.tex[3].bpp,
			&mlx->rc.tex[3].linesize, &mlx->rc.tex[3].endian);
	if(!(mlx->rc.tex[4].img = mlx_xpm_file_to_image(mlx->ptr, config->EA,
			&mlx->rc.tex_width, &mlx->rc.tex_height)))
			print_error("Textura EA no existe");
	mlx->rc.tex[4].addr = mlx_get_data_addr(mlx->rc.tex[4].img, &mlx->rc.tex[4].bpp,
			&mlx->rc.tex[4].linesize, &mlx->rc.tex[4].endian);
	if(!(mlx->rc.tex[5].img = mlx_xpm_file_to_image(mlx->ptr, config->S,
			&mlx->rc.tex_width, &mlx->rc.tex_height)))
			print_error("Textura de Sprite no existe");
	mlx->rc.tex[5].addr = mlx_get_data_addr(mlx->rc.tex[5].img, &mlx->rc.tex[5].bpp,
			&mlx->rc.tex[5].linesize, &mlx->rc.tex[5].endian);
}