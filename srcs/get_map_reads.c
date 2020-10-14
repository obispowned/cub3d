#include "../header/cub3d.h"

t_config		read_map(char *file, t_config config)
{	//segunda lectura de mapa para guardarlo para posteriormente chekearlo
	int fd;
	char buf[2];
	int ret;
	char *line;
	char **map;
	int i;

	i = 0;
	buf[1] = '\0';
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR: Fallo al intentar abrir el archivo .cub");
		exit(-1);
	}
	if(!(map = (char **)calloc(sizeof(char **) * what_is_higher(config.map_max_lines, config.map_max_rows), 1)))
	{
		printf("Error de malloc |get_map_reads.c|");
		exit(-1);
	}
//	map[what_is_higher(config.map_max_lines, config.map_max_rows) + 1] = NULL;
	while((ret = get_next_line(fd, &line)) > 0)
	{
		if (who_needs_a_map(line) == 1)
		{
			map[i] = ft_strdup(line);
			printf("%s\n", map[i]);
			i++;
		}
		free(line);
	}
	/*CONTINUAR AQUI*/
	free (line);
	close(fd);
 	double_kill(map);
	return (config);
}

int		who_needs_a_map(char *line)
{
	int		i;
	int		final;

	final = 0;
	i = 0;
	while (line[i] != '\0')
	{
		while (line[i] == ' ')
			i++;
		if ((line[i] == 'C') || (line[i] == 'R') || (line[i] == 'F') ||
		((line[i] == 'N') && (line[i+1] == 'O')) || ((line[i] == 'S') && (line[i+1] == 'O')) ||
		((line[i] == 'W') && (line[i+1] == 'E')) || ((line[i] == 'E') && (line[i+1] == 'A')) ||
		((line[i] == 'S') && (line[i+1] == ' ')))
			break;
		if ((line[i] == '1') &&
		((line[i+1] == '0') || (line[i+1] == '1') ||
		(line[i+1] == 'N') || (line[i+1] == 'S') ||
		(line[i+1] == 'E') || (line[i+1] == 'W')) &&
		((line[i+2] == '0') || (line[i+2] == '1') ||
		(line[i+2] == 'N') || (line[i+2] == 'S') ||
		(line[i+2] == 'E') || (line[i+2] == 'W')))
			final = 1;
		i++;
	}
	return (final);
}
