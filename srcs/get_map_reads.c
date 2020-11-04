/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_reads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:05:06 by agutierr          #+#    #+#             */
/*   Updated: 2020/11/04 12:31:47 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

t_config		read_map(char *file, t_config config)
{	//segunda lectura de mapa para guardarlo para posteriormente checkearlos
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
	
	check_map(&config, map);
	valid_map(map);

	/*CONTINUAR AQUI*/
	close(fd);
 	double_kill(map);
	return (config);
}

void		valid_map(char **map)
{ //validamos que en todos los 9 del mapa no haya al lado un 0
	int i;
	int j;

	i = 1;
	while(map[i+1])
	{
		j = 1;
		while (map[i][j+1]) 
		{
			if ((map[0][j] == '9') &&
			(((map[1][j] != '1') && (map[1][j] != '9')) ||
			((map[0][j+1] != '1') && (map[0][j+1] != '9')) ||
			((map[0][j-1] != '1') && (map[0][j-1] != '9'))))
			{
				printf("Coordenadas: %d-%d \n", i, j);
				print_error("Mapa abierto\n");
			}
			else if ((map[i][j] == '9') &&
			(((map[i-1][j] != '1') && (map[i-1][j] != '9')) ||
			((map[i+1][j] != '1') && (map[i+1][j] != '9')) ||
			((map[i][j+1] != '1') && (map[i][j+1] != '9')) ||
			((map[i][j-1] != '1') && (map[i][j-1] != '9'))))
			{
				printf("Coordenadas: %d-%d \n", i, j);
				print_error("Mapa abierto\n");
			}
			j++;
		}
		if ((map[i][j] == '9') &&
			(((map[i-1][j] != '1') && (map[i-1][j] != '9')) ||
			((map[i+1][j] != '1') && (map[i+1][j] != '9')) ||
			((map[i][j-1] != '1') && (map[i][j-1] != '9'))))
				print_error("Mapa abierto\n");
		i++;
	}
	printf("| El mapa es VALIDO |\n");
}

int		who_needs_a_map(char *line)
{
	int i;
	int j;
	int coincide;
	char *chain2;

	coincide = 0;
	chain2 = "102 NSWE\t";
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

void		check_map(t_config *config, char **map)
{
	int i;
	int j;

	i = 0;
	print_map(map);
	while(map[i])
	{
		j = 0;
		while (map[i][j])
		{	//COMPRUEBO PRIMERAS POSICIONES DEL MAPA Y QUE SOLO HAYA UNA POSICION DE JUGADOR
			if (((i == 0) && (map[i][j] != '9') && (map[i][j] != '1')) ||
				((j == 0) && (map[i][j] != '9') && (map[i][j] != '1')))
				print_error("Mapa malamente Cerrao.");
			if (((map[i][j] == 'N') || (map[i][j] == 'S') ||
				(map[i][j] == 'E') || (map[i][j] == 'W')) &&
				(config->player_begin[0] == 0 && config->player_begin[1] == 0))
			{
				config->player_begin[0] = i;
				config->player_begin[1] = j;
			}
			else if (((map[i][j] == 'N') || (map[i][j] == 'S') ||
				(map[i][j] == 'E') || (map[i][j] == 'W')) &&
				(config->player_begin[0] != 0 && config->player_begin[1] != 0))
				print_error("Ya existe otra posicion para el jugador");
			j++;
		}
		i++;
	}
}



void		print_map(char **map)
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
