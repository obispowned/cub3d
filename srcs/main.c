#include "../header/cub3d.h"
#include "../get_next_line/get_next_line.h"
#include "utils.h"

int main(int argc, char **argv)
{
	t_config	config;

	if (argc != 2)
		print_error("Incluya un archivo .cub como argumento");
	else
	{
		config = file_procesator(argv[1]);
//		game_loading();

	}

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


	printf("\n");
	printf("\n");

	ace(config.NO, config.SO, config.WE, config.EA, config.S, NULL);

	system("leaks cub3D");

	return(0);
}
