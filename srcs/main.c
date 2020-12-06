#include "../header/cub3d.h"
#include "../header/game.h"
#include "../get_next_line/get_next_line.h"
#include "../header/utils.h"

int main(int argc, char **argv)
{
	t_config	config;
	t_mlx mlx;

	if (argc < 2 || argc > 3)
		print_error("Numero de argumentos invalido");
	config = file_procesator(argv[1], argc);
	if (argc == 3)
	{
		if (argc == 3)
		{
			check_arg(argv[2]);
			config.save = 1;
		}
	}
	print_values(config);
	reset_mlx(&mlx, config);
	init_raycast_params(&mlx, &config);
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, mlx.win_width, mlx.win_height, "CUB3D");
	/*if (config.save == 1) //si hay --save
	{
		mlx_loop_hook(mlx.ptr, &screenshot_1, &mlx.rc);
	}
	else
	{
		mlx_loop_hook(mlx.ptr, &raycast_1, &mlx);
	}*/
	load_textures(&mlx);
	mlx_hook(mlx.win, 2, 1L << 0, &raycasting, &mlx); //pulsar
	mlx_hook(mlx.win, 3, 1L << 1, &raycasting, &mlx); //soltar
	mlx_hook(mlx.win, 17, 1L << 17, exit_game, &mlx); //cerramos ventana al dar a la "equis"
	mlx_loop(mlx.ptr);
	ace(config.NO, config.SO, config.WE, config.EA, config.S, NULL);
	return(0);
}

void 	print_values(t_config config)
{
	printf("\n");
	printf("width %d, height %d\n", config.width, config.height);

	printf("path  NO: %s\n", config.NO);
	printf("path  SO: %s\n", config.SO);
	printf("path  WE: %s\n", config.WE);
	printf("path  EA: %s\n", config.EA);
	printf("path  S: %s\n", config.S);

	printf("floor: | %d,%d,%d |\n", config.floor[0], config.floor[1],  config.floor[2]);
	printf("ceil: | %d,%d,%d |\n", config.ceil[0], config.ceil[1], config.ceil[2]);

	printf("Elementos guardados sin contar el **map: | %d |\n", config.flag);
	printf("Cantidad de lineas: | %d |\n", config.map_max_lines);
	printf("Cantidad de columnas: | %d |\n", config.map_max_rows);

	printf("Coordenadas de cominezo: | %d-%d |\n", config.player_begin[0], config.player_begin[1]);
	printf("El jugador empieza mirando a: %c\n", config.player_pos_begin);
	printf("numero de sprites: %d\n", config.numsprites);
	printf("config.save: %d\n", config.save);
	
	printf("\n");
	printf("\n");
}
