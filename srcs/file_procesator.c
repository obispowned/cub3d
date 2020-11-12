#include "../header/cub3d.h"

void	reset_t_config(t_config *config)
{
	int o;

	o = 0;
	config->flag = 0;
	config->i = 0;
	config->height = 0;
	config->width = 0;
	config->NO = NULL;
	config->SO = NULL;
	config->EA = NULL;
	config->WE = NULL;
	config->S = NULL;
	config->map_max_lines = 0;
	config->map_max_rows = 0;
	config->maxR = 0;
	config->player_begin[0] = 0;
	config->player_begin[1] = 0;
	while (o < 3)
	{
		config->ceil[o] = 0;
		config->floor[o] = 0;
		o++;
	}
}

void	check_file(char *line, t_config *config)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((line[i] == 'R') && (white_spaces(line[i + 1])))
			check_R(line, config);
		if (((line[i] == 'N') && (line[i + 1] == 'O') && (white_spaces(line[i + 2]))) ||
		((line[i] == 'S') && (line[i + 1] == 'O') && (white_spaces(line[i + 2]))) ||
		((line[i] == 'W') && (line[i + 1] == 'E') && (white_spaces(line[i + 2]))) ||
		((line[i] == 'E') && (line[i + 1] == 'A') && (white_spaces(line[i + 2]))) ||
		((line[i] == 'S') && (white_spaces(line[i + 1]))))
			check_path(&line[i], config, i);
		if (((line[i] == 'F') && (line[i + 1] == ' ')) ||
		((line[i] == 'C') && (line[i + 1] == ' ')))
			check_ceil_floor(line, config, i);
		if ((line[i] == '1') && ((line[i + 1] == '1') ||
		(line[i + 1] == '2') || (line[i + 1] == '3') ||
		(line[i + 1] == '0') || (line[i + 1] == 'N') ||
		(line[i + 1] == 'S') || (line[i + 1] == 'W') ||
		(line[i + 1] == 'E')) && (config->flag == 8))
		{
			config->map_max_lines++;
			if (ft_strlen(line) > config->map_max_rows)
				config->map_max_rows = ft_strlen(line);
			while (line[i] != '\0')
				i++;
		}
		if (line[i] != '\0')
			i++;
	}
}

void	load_file(char *file, t_config *config)
{ /*le paso el archivo y la estructura y devuelve primera lectura*/
	int		fd;
	char	buf[2];
	int		ret;
	char	*line;

	buf[1] = '\0';
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("Fallo al intentar abrir el archivo.");
	while (((ret = get_next_line(fd, &line)) > 0))
	{
		check_file(line, config);
		kill(line);
	}
	check_file(line, config);
	kill(line);
	close(fd);
	if (config->flag != 8)	/*si no hay 8 valores guardados en la struct*/
		print_error("Faltan datos en el archivo .cub");
}

void	file_procesator(t_config *config, char *file) /*le pasamos el archivo y devuelve la estructura rellenada*/
{
	if (file[ft_strlen(file) - 1] != 'b' && file[ft_strlen(file) - 2] != 'u' &&
	file[ft_strlen(file) - 3] != 'c' && file[ft_strlen(file) - 4] != '.')
		printf("El archivo que ingresa debe ser tener la extension .cub");
	load_file(file, config);
	read_map(file, config);
}
