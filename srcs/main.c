#include "../header/cub3d.h"
#include "../header/get_next_line.h"

int main(int argc, char **argv)
{
	t_config config;

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
	system("leaks cub3D");

	return(0);
}
