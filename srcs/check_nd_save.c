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

	splitter = ft_split(line, ' ');
	if ((splitter[2]) || ((splitter[1][ft_strlen(splitter[1]) -1] != 'm') && (splitter[1][ft_strlen(splitter[1]) -2] != 'p')
	 && (splitter[1][ft_strlen(splitter[1]) -3] != 'x')  && (splitter[1][ft_strlen(splitter[1]) -4] != '.')))
	{
		printf("ERROR: Formato de texturas incorrecto.");
		exit(-1);
	}
	if ((line[config.i] == 'N') && (line[config.i+1] == 'O') && (line[config.i+2] == ' '))
		config.NO = splitter[1];
	else if ((line[config.i] == 'S') && (line[config.i+1] == 'O') && (line[config.i+2] == ' '))
		config.SO = splitter[1];
	else if	((line[config.i] == 'W') && (line[config.i+1] == 'E') && (line[config.i+2] == ' '))
		config.WE = splitter[1];
	else if ((line[config.i] == 'E') && (line[config.i+1] == 'A') && (line[config.i+2] == ' '))
		config.EA = splitter[1];
	else if ((line[config.i] == 'S') && (line[config.i+1] == ' '))
		config.S = splitter[1];
	else
	{
		printf("ERROR: Formato de texturas incorrecto.");
		exit(-1);
	}
	double_kill(splitter);
	return (config);
}
