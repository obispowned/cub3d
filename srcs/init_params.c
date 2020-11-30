#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"

t_config reset_t_config()
{
	t_config config;
	
	config.flag = 0;
	config.i = 0;
	config.height = 0;
	config.width = 0;
	config.NO = NULL;
	config.SO = NULL;
	config.EA = NULL;
	config.WE = NULL;
	config.S = NULL;
	config.map_max_lines = 0;
	config.map_max_rows = 0;
	config.maxR = 0;
	config.player_begin[0] = 0;
	config.player_begin[1] = 0;
	config.save = 0;
	init_config(&config);
	return (config);
}

void	init_config(t_config *config)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		config->ceil[i] = -1;
		config->floor[i] = -1;
		i++;
	}
	config->mapa.hexaceil = 0;
	config->mapa.hexafloor = 0;
}

void	init_raycast_params3(t_mlx *mlx, t_config *config)
{
	mlx->rc.tex_height = 64;
	mlx->rc.tex_width = 64;
	mlx->rc.tex_side = 1;
	mlx->rc.movespeed = 0.200;
	mlx->rc.up = 0;
	mlx->rc.down = 0;
	mlx->rc.right = 0;
	mlx->rc.left = 0;
	if (mlx->rc.player_dir == 'E')
	{
		mlx->rc.player_plane_x = 0.66;
		mlx->rc.player_plane_y = 0;
		mlx->rc.dirx = 0;
		mlx->rc.diry = 1;
	}
	else if (mlx->rc.player_dir == 'W')
	{
		mlx->rc.player_plane_x = -0.66;
		mlx->rc.player_plane_y = 0;
		mlx->rc.dirx = 0;
		mlx->rc.diry = -1;
	}
}

void	init_raycast_params2(t_mlx *mlx, t_config *config)
{ /*POSIBLE SEG FAULT AL EQUIVOCAR BEGIN 0 CON BEGIN 1*/
	mlx->rc.player_pos_x = (double)config->player_begin[0] + 0.5;
	mlx->rc.player_pos_y = (double)config->player_begin[1] + 0.5;
	if (mlx->rc.player_dir == 'N')
	{
		mlx->rc.dirx = -1;
		mlx->rc.diry = 0;
		mlx->rc.player_plane_x = 0;
		mlx->rc.player_plane_y = 0.66;
	}
	else if (mlx->rc.player_dir == 'S')
	{
		mlx->rc.player_plane_x = 0;
		mlx->rc.player_plane_y = -0.66;
		mlx->rc.dirx = 1;
		mlx->rc.diry = 0;
	}
}

int		init_raycast_params(t_mlx *mlx)
{
	int i;

	i = 0;
	mlx->ptr = NULL;
	mlx->rc.win = NULL;
	mlx->rc.rot_left = 0;
	mlx->rc.rot_right = 0;
	rc->numsprites = map->numsprites;
	init_raycast_params2(rc, map);
	init_raycast_params3(rc, map, arch);
	init_textures(rc, arch);
	while (i < map->numsprites)
	{
		rc->sprite[i].x = map->sprite[i].y;
		rc->sprite[i].y = map->sprite[i].x;
		i++;
	}
	rc->spr_buffer = (double *)malloc(sizeof(double) * rc->win_x);
	if (!(rc->mlx_ptr = mlx_init()))
		return (ft_puterror("Inicio de Minilibx fallida\n"));
	if (!(rc->win_ptr =
		mlx_new_window(rc->mlx_ptr, rc->win_x, rc->win_y, "cub3d")))
		return (ft_puterror("Proceso de creacion de Ventana fallida\n"));
	return (1);
}
/*
void	init_initialparams(t_validmap *map)
{
	int i;

	i = 0;
	map->m_top = 0;
	map->m_bot = 0;
	map->m_line = 0;
	map->prev_line = "";
	map->map_width = 0;
	map->player_dir = '\0';
	map->colum_spaces = (int *)malloc(sizeof(int) * 255);
	map->colum_nums = (int *)malloc(sizeof(int) * 255);
	map->last_0 = 0;
	while (i < 255)
	{
		map->colum_spaces[i] = 0;
		map->colum_nums[i] = 0;
		i++;
	}
}*/