#include "../header/cub3d.h"

void	drifting_R_PATH(char *line, t_config *config)
{
	if ((line[config->i] == 'R') && (white_spaces(line[config->i + 1])))
		*config = check_R(line, *config);
	if (((line[config->i] == 'N') && (line[config->i + 1] == 'O') && (white_spaces(line[config->i + 2]))) ||
	((line[config->i] == 'S') && (line[config->i + 1] == 'O') && (white_spaces(line[config->i + 2]))) ||
	((line[config->i] == 'W') && (line[config->i + 1] == 'E') && (white_spaces(line[config->i + 2]))) ||
	((line[config->i] == 'E') && (line[config->i + 1] == 'A') && (white_spaces(line[config->i + 2]))) ||
	((line[config->i] == 'S') && (white_spaces(line[config->i + 1]))))
		*config = check_path(&line[config->i], *config);
}

t_config check_file(char *line, t_config config)
{
	config.i = 0;
	while (line[config.i] != '\0')
	{
		drifting_R_PATH(line, &config);
		if (((line[config.i] == 'F') && (line[config.i + 1] == ' ')) ||
		((line[config.i] == 'C') && (line[config.i + 1] == ' ')))
			config = check_ceil_floor(line, config);
		if ((line[config.i] == '1') && ((line[config.i + 1] == '1') ||
		(line[config.i + 1] == '2') || (line[config.i + 1] == '3') ||
		(line[config.i + 1] == '0') || (line[config.i + 1] == 'N') ||
		(line[config.i + 1] == 'S') || (line[config.i + 1] == 'W') ||
		(line[config.i + 1] == 'E')) && (config.flag == 8))
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

int		check_lines(char *line, char *chars)
{
	int		i;
	int		j;
	int		coincide;

	coincide = 0;
	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		while (chars[j] != '\0')
		{
			if (line[i] == chars[j])
				return(1);
			j++;
		}
		i++;
	}
	return (0);
}

t_config	load_file(char *file, t_config config)
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
		if ((check_lines(line, " NSR\tECFW") == 0 && line[0] != '\0')
		&& (who_needs_a_map(line) == 0))
			print_error("Elimine los caracteres sobrantes.");
		if (who_needs_a_map(line) == 1 && config.flag != 8)
			print_error("Debe declarar los parametros delante del mapa");
		config.i = 0;
		config = check_file(line, config);
		kill(line);
	}
	config = check_file(line, config);
	kill(line);
	close(fd);
	check_params(config);
	return (config);
}

void	check_params(t_config config)
{
	if (config.flag != 8)	/*si no hay 8 valores guardados en la struct*/
		print_error("Faltan datos en el archivo .cub");
	if ((config.ceil[0] < 0 || config.ceil[0] > 255) ||
	(config.ceil[1] < 0 || config.ceil[1] > 255) ||
	(config.ceil[2] < 0 || config.ceil[2] > 255) ||
	(config.floor[0] < 0 || config.floor[0] > 255) ||
	(config.floor[1] < 0 || config.floor[1] > 255) ||
	(config.floor[2] < 0 || config.floor[2] > 255))
		print_error("Los valores de ceil/floor deben ser entre 0 y 255.");

}

t_config		file_procesator(char *file, int argc) /*le pasamos el archivo y devuelve la estructura rellenada*/
{
	t_config	config;

	if (file[ft_strlen(file) - 1] != 'b' && file[ft_strlen(file) - 2] != 'u' &&
	file[ft_strlen(file) - 3] != 'c' && file[ft_strlen(file) - 4] != '.')
		printf("El archivo que ingresa debe ser tener la extension .cub");
	config = reset_t_config();

	//CHECK ARGC PENDIENTE
	config = load_file(file, config);
	config.mapa = read_map(file, &config);
	if (config.player_begin[0] == 0 && config.player_begin[1] == 0)
		print_error("Este mapa no puede ser usado sin un jugador");
	return (config);
}

void	check_arg(char *argum)
{
	int i;

	i = 0;
	if (!((ft_strlen(argum) == 6) && (argum[0] == '-')
	 && (argum[1] == '-') && (argum[2] == 's')
	  && (argum[3] == 'a') && (argum[4] == 'v')
	   && (argum[5] == 'e')))
		print_error("El tercer argumento debe ser '--save'");
}
