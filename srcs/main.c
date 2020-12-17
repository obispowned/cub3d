/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 13:48:46 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/17 13:47:11 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"
#include "../header/game.h"
#include "../get_next_line/get_next_line.h"
#include "../header/utils.h"

int				main(int argc, char **argv)
{
	t_config	config;
	t_mlx		mlx;

	if (argc < 2 || argc > 3)
		print_err("Numero de argumentos invalido");
	config = file_procesator(argv[1], argc);
	if (argc == 3)
	{
		check_arg(argv[2]);
		config.save = 1;
	}
	final_check(&config);
	//print_values(config);
	reset_mlx(&mlx, config);
	init_raycast_params(&mlx, &config);
	save_sprites_position(&mlx);
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, mlx.win_width, mlx.win_height, "CUB3D");
	load_textures(&mlx, &config);
	mlx_hook(mlx.win, 2, 1L << 0, &key_press, &mlx);
	mlx_hook(mlx.win, 3, 1L << 1, &key_release, &mlx);
	mlx_loop_hook(mlx.ptr, &raycasting, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, exit_game, &mlx);
	mlx_loop(mlx.ptr);
	ace(config.no, config.so, config.we, config.ea, config.s, NULL);
	return (0);
}

void			final_check(t_config *config)
{
	config->width > 2560 ? config->width = 2560 : config->width;
	config->width < 200 ? config->width = 200 : config->width;
	config->height > 1440 ? config->height = 1440 : config->height;
	config->height < 100 ? config->height = 100 : config->height;
}

void			save_sprites_position(t_mlx *mlx)
{
	int			i;
	int			j;
	int			cont;

	i = 0;
	cont = 0;
	while (i < mlx->rc.map_lines)
	{
		j = 0;
		while (j < mlx->rc.map_rows)
		{
			if (mlx->finalmap[i][j] == 2)
			{
				mlx->rc.sprite[cont].id = cont;
				mlx->rc.sprite[cont].x = (double)i + 0.5;
				mlx->rc.sprite[cont].y = (double)j + 0.5;
				cont++;
			}
			j++;
		}
		i++;
	}
}

void			print_values(t_config config)
{
	printf("width %d, height %d\n", config.width, config.height);
	printf("path  NO: %s\n", config.no);
	printf("path  SO: %s\n", config.so);
	printf("path  WE: %s\n", config.we);
	printf("path  EA: %s\n", config.ea);
	printf("path  S: %s\n", config.s);
	printf("floor: | %d,%d,%d |\n", config.floor[0],
	config.floor[1], config.floor[2]);
	printf("ceil: | %d,%d,%d |\n",
	config.ceil[0], config.ceil[1], config.ceil[2]);
	printf("Elementos guardados sin contar el **map: | %d |\n", config.flag);
	printf("Cantidad de lineas: | %d |\n", config.map_max_lines);
	printf("Cantidad de columnas: | %d |\n", config.map_max_rows);
	printf("Coordenadas de cominezo: | %d-%d |\n",
	config.player_begin[0], config.player_begin[1]);
	printf("El jugador empieza mirando a: %c\n", config.player_pos_begin);
	printf("numero de sprites: %d\n", config.numsprites);
	printf("config.save: %d\n", config.save);
}
