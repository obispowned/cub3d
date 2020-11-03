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
		print_error("Fallo al intentar abrir el archivo .cub");
	config.maxR = what_is_higher(config.map_max_lines, config.map_max_rows);
	if(!(map = (char **)calloc(sizeof(char *) * config.maxR + 1, 1)))
		printf("Malloc ha fallado en: get_map_reads.c");
	while(((ret = get_next_line(fd, &line)) > 0) )
	{
		if (who_needs_a_map(line) == 1)
			map[i++] = ft_strdup_sustitute_char(line, ' ', '9', config.maxR);
		kill(line);
	}
	if (who_needs_a_map(line) == 1)
		map[i++] = ft_strdup_sustitute_char(line, ' ', '9', config.maxR);
	kill(line);
	while(i < config.maxR)
		map[i++] = fill_me('9', config.maxR);
	check_map(map);

	/*CONTINUAR AQUI*/
	close(fd);
 	double_kill(map);
	return (config);
}

int		who_needs_a_map(char *line)
{
	int i;
	int j;
	int coincide;
	char *chain2;

	coincide = 0;
	chain2 = "102 NSWE";
	i = 0;
	j = 0;
	while(line[i] != '\0')
	{
		coincide = 0;
		j = 0;
		while(chain2[j] != '\0')
		{
			if(line[i] == chain2[j])
				coincide = 1;
			j++;
		}
		if (coincide != 1)
			return(0);
		i++;
	}
	if (coincide == 1)
		return (1);
	else
		return (0);
}


char 		*fill_me(char c, int lenght)
{
	char 	*finally;
	int 	i;

	i = 0;
	if(!(finally = ((char *)malloc(sizeof(char) * lenght + 1))))
		printf("Malloc ha fallado en: get_map_reads.c");
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
	int i;

	i = 0;
	while(map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

/*
int		check_me_baby(char c, char *str)
{
	int i;

	i = 0;
	if (!c)
		return (1);
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}*/
