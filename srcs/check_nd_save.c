#include "../header/cub3d.h"

t_config check_R(char *line, t_config config)
{
	char **splitter;
	splitter = ft_split(line, ' ');
	if ((splitter[3]) || (ft_isdigit(splitter[1]) != 1) || (ft_isdigit(splitter[2]) != 1))
	{
		printf("ERROR: Formato de Resolucion incorrecto.");
		exit(-1);
	}
	config.width = atoi(splitter[1]);
	config.height = atoi(splitter[2]);
	double_kill(splitter);
	return (config);
}

t_config check_path(char *line, t_config config)
{
	char **splitter;

	splitter = ft_split((const char *)line, ' ');
	if ((splitter[2]) || ((splitter[1][ft_strlen(splitter[1]) -1] != 'm') && (splitter[1][ft_strlen(splitter[1]) -2] != 'p')
	 && (splitter[1][ft_strlen(splitter[1]) -3] != 'x')  && (splitter[1][ft_strlen(splitter[1]) -4] != '.')))
	{
		printf("ERROR: Formato de texturas incorrecto.");
		exit(-1);
	}
	if ((line[config.i] == 'N') && (line[config.i+1] == 'O') && (line[config.i+2] == ' '))
		config.NO = ft_strdup(splitter[1]);
	else if ((line[config.i] == 'S') && (line[config.i+1] == 'O') && (line[config.i+2] == ' '))
		config.SO = ft_strdup(splitter[1]);
	else if	((line[config.i] == 'W') && (line[config.i+1] == 'E') && (line[config.i+2] == ' '))
		config.WE = ft_strdup(splitter[1]);
	else if ((line[config.i] == 'E') && (line[config.i+1] == 'A') && (line[config.i+2] == ' '))
		config.EA = ft_strdup(splitter[1]);
	else if ((line[config.i] == 'S') && (line[config.i+1] == ' '))
		config.S = ft_strdup(splitter[1]);
	else
	{
		printf("ERROR: Formato de texturas incorrecto.");
		exit(-1);
	}
	double_kill(splitter);
	return (config);
}

t_config check_ceil_floor(char *line, t_config config)
{
	char **splitter;
	int i;
	char conmut;

	i = 0;
	conmut = line[i]; //para saber si lo guardaremos en config.ceil[3] o en config.floor[3]/
	while ((line[i] != '\0') && ((line[i] < '0') || (line[i] > '9')))
		i++;
	splitter = ft_split(&line[i], ',');
	if ((splitter[3]) || (ft_isdigit(splitter[0]) != 1) || (ft_isdigit(splitter[1]) != 1) || (ft_isdigit(splitter[2]) != 1))
	{
		printf("ERROR: Formato de ceil/floor incorrecto.");
		exit(-1);
	}
	if (conmut == 'C')
	{
		config.ceil[0] = atoi(splitter[0]);
		config.ceil[1] = atoi(splitter[1]);
		config.ceil[2] = atoi(splitter[2]);
	}
	if (conmut == 'F')
	{
		config.floor[0] = atoi(splitter[0]);
		config.floor[1] = atoi(splitter[1]);
		config.floor[2] = atoi(splitter[2]);
	}
	double_kill(splitter);
	return (config);

}
