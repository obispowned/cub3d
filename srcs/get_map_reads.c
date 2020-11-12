/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_reads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:05:06 by agutierr          #+#    #+#             */
/*   Updated: 2020/11/12 11:56:29 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void		read_map(char *file, t_config *config)
{	//segunda lectura de mapa para guardarlo para posteriormente checkearlos
	int			fd;
	int			ret;
	char		*line;
	char		**map;
	int			i;
	int			j;
	
	j = 0;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("Fallo al intentar abrir el archivo .cub");
	if (!(map = (char **)malloc(sizeof(char *) * config->map_max_lines + 2)))
		printf("Malloc ha fallado en: get_map_reads.c");
	map[config->map_max_lines + 1] = NULL;
	while (((ret = get_next_line(fd, &line)) > 0))
	{
		if (who_needs_a_map(line, "102 NSWE\t") == 1)
		{
			map[i] = ft_strdup_sustitute_char(line, ' ', '9', config->map_max_rows + 1); /**/
			i++;
		}
		kill(line);
	}
	if (who_needs_a_map(line, "102 NSWE\t") == 1)
	{
		map[i] = ft_strdup_sustitute_char(line, ' ', '9', config->map_max_rows + 1); /**/
		i++;
	}
	map[i] = calloc(sizeof(char) * config->map_max_rows + 2, 1);
	while (j < config->map_max_rows + 1)
	{
		map[i][j] = '9';
		j++;
	}
	map[i][j] = '\0';
	check_map(config, map);
	valid_map(map);
	close(fd);
	kill(line);
	print_map(map);
 	double_kill(map);
}

void		valid_map(char **map)
{ //validamos que en todos los 9 del mapa no haya al lado un 0
	int		i;
	int		j;

	i = 1;
	while (map[i + 1] != 0)
	{
		j = 1;
		while (map[i][j + 1] != '\0') 
		{
			if ((map[0][j] == '9') &&
			(((map[1][j] != '1') && (map[1][j] != '9'))
			|| ((map[0][j + 1] != '1') && (map[0][j + 1] != '9'))
			|| ((map[0][j - 1] != '1') && (map[0][j - 1] != '9'))))
			{
				printf("Coordenadas: %d-%d \n", i, j);
				print_error("Mapa abierto\n");
			}
			else if ((map[i][j] == '9') &&
			(((map[i - 1][j] != '1') && (map[i - 1][j] != '9')) ||
			((map[i + 1][j] != '1') && (map[i + 1][j] != '9')) ||
			((map[i][j + 1] != '1') && (map[i][j + 1] != '9')) ||
			((map[i][j - 1] != '1') && (map[i][j - 1] != '9'))))
			{
				printf("Coordenadas: %d-%d \n", i, j);
				print_error("Mapa abierto\n");
			}
			j++;
		}
		if ((map[i][j] == '9') &&
		(((map[i - 1][j] != '1') && (map[i - 1][j] != '9')) ||
		((map[i + 1][j] != '1') && (map[i + 1][j] != '9')) ||
		((map[i][j - 1] != '1') && (map[i][j - 1] != '9'))))
			print_error("Mapa abierto\n");
		i++;
	}
	valid_map3(map, i);
	printf("| El mapa es VALIDO |\n");
}

void		valid_map3(char **map, int i)
{
	int		j;

	j = 1;
	while (map[i][j] != '\0')
	{
		if (map[i][j] != '9')
			print_error("Mapa abierto en la ultima linea.");
		if ((map[i-1][j] != '9') && (map[i-1][j] != '1'))
			print_error("Mapa abierto en la ultima linea.");
		j++;
	}
}

int			who_needs_a_map(char *line, char *chain2)
{
	int		i;
	int		j;
	int		coincide;

	coincide = 0;
	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		coincide = 0;
		j = 0;
		while (chain2[j] != '\0')
		{
			if (line[i] == chain2[j])
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

char 		*fill_me(char c, int lenght, char **map)
{
	char 	*finally;
	int 	i;
	
	if(!(finally = ((char *)malloc(sizeof(char) * lenght + 2))))
		printf("Malloc ha fallado en: get_map_reads.c");
	if (map)
	{
		i = 0;
		while(i <= lenght)
		{
			finally[i] = c;
			i++;
		}
		finally[i] = '\0';
	}
	return (finally);
}

void		check_map(t_config *config, char **map)
{
	int i;
	int j;

	i = 0;

	while(map[i] != 0)
	{
		j = 0;
		while (map[i][j] != '\0') /*i2*/
		{	//COMPRUEBO PRIMERAS POSICIONES DEL MAPA Y QUE SOLO HAYA UNA POSICION DE JUGADOR
			if (((i == 0) && ((map[i][j] != '9') && (map[i][j] != '1'))) ||
				((j == 0) && ((map[i][j] != '9') && (map[i][j] != '1'))))
				print_error("Mapa malamente Cerrao.");
			if (((map[i][j] == 'N') || (map[i][j] == 'S') ||
				(map[i][j] == 'E') || (map[i][j] == 'W')) &&
				(config->player_begin[0] == 0 && config->player_begin[1] == 0))
			{
				config->player_begin[0] = i;
				config->player_begin[1] = j;
				map[i][j] = '0';
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
	while(map[i] != 0)
	{
		printf("%s\n", map[i]);
		i++;
	}
}