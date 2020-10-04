#include "../header/cub3d.h"
#include "../header/get_next_line.h"
#include "../libft/libft.h"

int main(int argc, char **argv)
{
	t_config config;

	if (argc != 2)
	{
		printf("ERROR: Incluya un archivo .cub como argumento");
	}
	else
	{
		config = file_procesator(argv[1]);
//		game_loading();
	}

	return(0);
}
