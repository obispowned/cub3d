#include "../header/cub3d.h"
#include "../header/get_next_line.h"

int main(int argc, char **argv)
{
	t_config	config;

	if (argc != 2)
	{
		printf("ERROR: Incluya un archivo .cub como argumento");
		exit(-1);
	}
	else
	{
		config = file_procesator(argv[1]);
//		game_loading();

	}

	printf("width %d, height %d\n", config.width, config.height);

	printf("path  NO: %s\n", config.NO);
	printf("path  SO: %s\n", config.SO);
	printf("path  WE: %s\n", config.WE);
	printf("path  EA: %s\n", config.EA);
	printf("path  S: %s\n", config.S);
	printf("floor: | %d,%d,%d |\n", config.floor[0], config.floor[1],  config.floor[2]);
	printf("ceil: | %d,%d,%d |\n", config.ceil[0], config.ceil[1], config.ceil[2]);
	printf("flag: | %d |\n", config.flag);
	printf("lines: | %d |\n", config.map_max_lines);
	printf("max rows: | %d |\n", config.map_max_rows);


	printf("\n");
	printf("\n");


	system("leaks cub3D");

	return(0);
}
