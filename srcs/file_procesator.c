#include "../header/cub3d.h"

t_config reset_t_config()
{
	t_config config;
	int i;

	i = 0;
	config.height = 0;
	config.width = 0;
	config.NO = NULL;
	config.SO = NULL;
	config.EA = NULL;
	config.WE = NULL;
	config.S = NULL;
	config.mapR = 0;

	while (i < 3)
	{
		config.ceil[i] = 0;
		config.floor[i] = 0;
		i++;
	}
	return (config);
}

t_config load_file(char *file, t_config config)
{
	int fd;
	int i;
	char buf[2];

	buf[1] = '\0';
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("ERROR: fallo en la lectura .cub file");
	while ((read(fd, &buf[0], 1)) > 0)
	{
		config = check_file(config); /**ESTOY AQUI**/
		if(buf[0] == '\n')
			break;
	}
	close(fd);
	return (config);
}

t_config file_procesator(char *file)
{
	t_config config;

	config = reset_t_config();
	config = load_file(file, config);
//	config = check_map(file, config);
	return (config);
}
