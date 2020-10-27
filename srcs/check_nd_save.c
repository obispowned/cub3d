#include "../header/cub3d.h"

t_config check_R(char *line, t_config config)
{
	char **splitter;
	splitter = ft_split(line, ' ');
	if ((splitter[3]) || (ft_isdigit(splitter[1]) != 1) || (ft_isdigit(splitter[2]) != 1))
		print_error("Formato de Resolucion incorrecto.");
	config.width = atoi(splitter[1]);
	config.height = atoi(splitter[2]);
	config.flag += 1;
	double_kill(splitter);
	return (config);
}

t_config check_path(char *line, t_config config)
{
	char **splitter;

	splitter = ft_split((const char *)line, ' ');
	if ((splitter[2]) || ((splitter[1][ft_strlen(splitter[1]) -1] != 'm') && (splitter[1][ft_strlen(splitter[1]) -2] != 'p')
	 && (splitter[1][ft_strlen(splitter[1]) -3] != 'x')  && (splitter[1][ft_strlen(splitter[1]) -4] != '.')))
		print_error("Formato de texturas incorrecto.");
	if ((line[config.i] == 'N') && (line[config.i+1] == 'O') && (line[config.i+2] == ' ') && (!config.NO))
		config.NO = ft_strdup(splitter[1]);
	else if ((line[config.i] == 'S') && (line[config.i+1] == 'O') && (line[config.i+2] == ' ') && (!config.SO))
		config.SO = ft_strdup(splitter[1]);
	else if	((line[config.i] == 'W') && (line[config.i+1] == 'E') && (line[config.i+2] == ' ') && (!config.WE))
		config.WE = ft_strdup(splitter[1]);
	else if ((line[config.i] == 'E') && (line[config.i+1] == 'A') && (line[config.i+2] == ' ') && (!config.EA))
		config.EA = ft_strdup(splitter[1]);
	else if ((line[config.i] == 'S') && (line[config.i+1] == ' ') && (!config.S))
		config.S = ft_strdup(splitter[1]);
	else
		print_error("Formato de texturas incorrecto.");
	double_kill(splitter);
	config.flag += 1;
	return (config);
}

t_config check_ceil_floor(char *line, t_config config)
{
	char **splitter;
	char conmut;

	conmut = line[config.i]; //para saber si lo guardaremos en config.ceil[3] o en config.floor[3]/
	while ((line[config.i] != '\0') && ((line[config.i] < '0') || (line[config.i] > '9')))
		config.i++;
	splitter = ft_split(&line[config.i], ',');
	if (ft_isdigit(splitter[2]) != 1)
		splitter[2] = give_me_digit_without_spaces(splitter[2]);
	if ((splitter[3]) || (ft_isdigit(splitter[0]) != 1) || (ft_isdigit(splitter[1]) != 1) || (ft_isdigit(splitter[2]) != 1))
		print_error("Formato de ceil/floor incorrecto.");
	if (conmut == 'C')
	{
		config.ceil[0] = atoi(splitter[0]);
		config.ceil[1] = atoi(splitter[1]);
		config.ceil[2] = atoi(splitter[2]);
		config.flag += 1;
	}
	if (conmut == 'F')
	{
		config.floor[0] = atoi(splitter[0]);
		config.floor[1] = atoi(splitter[1]);
		config.floor[2] = atoi(splitter[2]);
		config.flag += 1;
	}
	while (line[config.i])
		config.i++;
	double_kill(splitter);
	return (config);
}


