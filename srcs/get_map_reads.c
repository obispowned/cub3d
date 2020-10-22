#include "../header/cub3d.h"

t_config		read_map(char *file, t_config config)
{	//segunda lectura de mapa para guardarlo para posteriormente chekearlo
	int fd;
	int ret;
	char *line;
	char **map;
	int i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR: Fallo al intentar abrir el archivo .cub");
		exit(-1);
	}
	if(!(map = (char **)calloc(sizeof(char *) * what_is_higher(config.map_max_lines, config.map_max_rows) + 3 , 1)))
	{
		printf("Error de malloc en archivo: get_map_reads.c");
		exit(-1);
	}
	while((ret = get_next_line(fd, &line)) > 0)
	{
		if (who_needs_a_map(line) == 1)
		{
			map[i] = ft_strdup_sustitute_char(line, ' ', '9', what_is_higher(config.map_max_lines, config.map_max_rows));
			i++;
		}
		free(line);
	}
	while(i < what_is_higher(config.map_max_lines, config.map_max_rows))
	{
		map[i] = fill_me('9', what_is_higher(config.map_max_lines, config.map_max_rows));
		i++;
	}

	check_map(map);

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

char 		*fill_me(char c, int lenght)
{
	char 	*finally;
	int 	i;

	i = 0;
	if(!(finally = ((char *)malloc(sizeof(char) * lenght + 1))))
	{
		printf("Error: Malloc ha fallado en fill_me()");
		exit (-1);
	}
	while(i <= lenght)
	{
		finally[i] = c;
		i++;
	}
	finally[i] = '\0';
	return (finally);
}

void		check_map(char **map)
{
	int j, i;

	i = 0;
	while(map[i])
	{
		j = 0;
		printf("\n");
		while(map[i][j])
		{
			printf("%c", map[i][j]);
/*			if ((map[i][j] == '9') &&
			((check_me_baby(map[i+1][j], "0NSW2E") == 0) ||
			(check_me_baby(map[i-1][j], "0NSW2E") == 0) ||
			(check_me_baby(map[i][j+1], "0NSW2E") == 0) ||
			(check_me_baby(map[i][j-1], "0NSW2E") == 0)))
			{
				printf("ERROR: Mapa abierto por algun lugar");
				exit (-1);
			}*/
			j++;
		}
		i++;
	}
}


/*int		check_me_baby(char c, char *str)
{
	int i;

	i = 0;
	if (!c)
		return (1);
	while (str[i])
	{
		if (str[i] == c)
			return (0);
	}
	return (1);
}*/
