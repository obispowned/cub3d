#include "../header/cub3d.h"

t_config reset_t_config()
{
	t_config config;
	int o;

	o = 0;
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

	while (o < 3)
	{
		config.ceil[o] = 0;
		config.floor[o] = 0;
		o++;
	}
	return (config);
}

t_config check_file(char *line, t_config config)
{
	while (line[config.i] != '\0')
	{
		if ((line[config.i] == 'R') && (line[config.i+1] == ' '))
			config = check_R(line, config);
		if (((line[config.i] == 'N') && (line[config.i+1] == 'O') && (line[config.i+2] == ' ')) ||
		((line[config.i] == 'S') && (line[config.i+1] == 'O') && (line[config.i+2] == ' ')) ||
		((line[config.i] == 'W') && (line[config.i+1] == 'E') && (line[config.i+2] == ' ')) ||
		((line[config.i] == 'E') && (line[config.i+1] == 'A') && (line[config.i+2] == ' ')) ||
		((line[config.i] == 'S') && (line[config.i+1] == ' ')))
			config = check_path(line, config);
		if (((line[config.i] == 'F') && (line[config.i+1] == ' ')) ||
		((line[config.i] == 'C') && (line[config.i+1] == ' ')))
			config = check_ceil_floor(line, config);
		if ((line[config.i] == '1') && ((line[config.i+1] == '1') ||
		(line[config.i+1] == '2') || (line[config.i+1] == '3') ||
		(line[config.i+1] == '0') || (line[config.i+1] == 'N')||
		(line[config.i+1] == 'S') || (line[config.i+1] == 'W')||
		(line[config.i+1] == 'E')) && (config.flag == 8))
		{
			if (ft_strlen(line) > config.map_max_rows)
				config.map_max_rows = ft_strlen(line);
			config.map_max_lines += 1;
			while (line[config.i] != '\0')
				config.i++;

		}
		if (line[config.i] != '\0')
			config.i++;
	}
	return (config);
}

t_config load_file(char *file, t_config config)
{ //le paso el archivo y la estructura y devuelve primera lectura
	int fd;
	char buf[2];
	int ret;
	char *line;

	buf[1] = '\0';
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("Fallo al intentar abrir el archivo.");
	while(((ret = get_next_line(fd, &line)) > 0) || ((ret = get_next_line(fd, &line)) == EOF ))
	{
		config.i = 0;
		config = check_file(line, config);
		free(line);
	}
	close(fd);
	if (config.flag != 8)	//si no hay 8 valores guardados en la struct
		print_error("Faltan datos en el archivo .cub");
	return (config);
}

t_config file_procesator(char *file) //le pasamos el archivo y devuelve la estructura rellenada
{
	t_config config;

	if (file[ft_strlen(file) -1] != 'b' && file[ft_strlen(file) -2] != 'u' &&
	file[ft_strlen(file) -3] != 'c' && file[ft_strlen(file) -4] != '.')
		printf("El archivo que ingresa debe ser tener la extension .cub");
	config = reset_t_config();
	config = load_file(file, config);
	config = read_map(file, config);
	return (config);
}
