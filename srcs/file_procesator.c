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

t_config check_file(char *line, t_config config)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((line[i] == 'R') && (line[i+1] == ' '))
			config = check_R(line, config, i);
		if (((line[i] == 'N') && (line[i+1] == 'O')) ||
		((line[i] == 'S') && (line[i+1] == 'O')) ||
		((line[i] == 'W') && (line[i+1] == 'E')) ||
		((line[i] == 'E') && (line[i+1] == 'A')) ||
		((line[i] == 'S') && (line[i+1] == ' ')))
			config = check_path(line, config, i);
		i++;
	}

/*	config = check_ceil_floor(line, config);
	config = check_map(line, config);*/

	return (config);
}

t_config load_file(char *file, t_config config)
{ //le paso el archivo y la estructura y devuelve primera lectura
	int fd;
	char buf[2];
	int ret;
	int  numero_de_lineas;
	char *line;

	numero_de_lineas = 0;
	buf[1] = '\0';
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR: Fallo al intentar abrir el archivo .cub");
		exit(-1);
	}
	while((ret = get_next_line(fd, &line)) > 0)
	{
		numero_de_lineas++;
		config = check_file(line, config);
		if ((int)ft_strlen(line) > config.mapR)
			config.mapR = ft_strlen(line);
	}
	if (config.mapR < numero_de_lineas)
	{
		printf("mayor numero de caracteres: %d\n", config.mapR);
		printf("numero de lineas: %d\n", numero_de_lineas);
		config.mapR = numero_de_lineas;
		printf("mapR final: %d\n", config.mapR);

	}
	close(fd);
	printf("mapR final: %d\n", config.mapR);
	return (config);
}

t_config file_procesator(char *file) //le pasamos el archivo y devuelve la estructura rellenada
{
	t_config config;

	if (file[ft_strlen(file) -1] != 'b' && file[ft_strlen(file) -2] != 'u' &&
	file[ft_strlen(file) -3] != 'c' && file[ft_strlen(file) -4] != '.')
	{
		printf("ERROR: El archivo que ingresa debe ser tener la extension .cub");
		exit(-1);
	}
	config = reset_t_config();
	config = load_file(file, config);
	config = check_map(file, config);
	return (config);
}
