#include "../header/cub3d.h"

t_config		read_map(char *file, t_config config)
{	//segunda lectura de mapa para guardarlo para posteriormente chekearlo
	int fd;
	char buf[2];
	int ret;
	char *line;

	buf[1] = '\0';
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR: Fallo al intentar abrir el archivo .cub");
		exit(-1);
	}
	while((ret = get_next_line(fd, &line)) > 0)
	{
		config.i = 0;

		free(line);
	}
	free (line);

	close(fd);

	return (config);
}


