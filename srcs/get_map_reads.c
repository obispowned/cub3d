/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_reads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:05:06 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/07 13:21:28 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

t_mapi		read_map(char *file, t_config *config)
{	//segunda lectura de mapa para guardarlo para posteriormente checkearlos
	int			fd;
	char		**map;
	
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("Fallo al intentar abrir el archivo .cub");
	config->maxR = (what_is_higher(config->map_max_lines, config->map_max_rows)) + 2;
	map = read_map2(fd, config); //Guardo map con 9 dibujados
	check_map(config, map);	//validar mapa1
	valid_map(map);			//validar mapa2
	config->mapa = parserico(map, config); //pasar a int el mapa y guardar en la estructura
	close(fd);
 	double_kill(map);
	return (config->mapa);
}

char		**read_map2(int fd, t_config *config)
{
	char	*line;
	char	**map;
	int 	count_sprites;
	int		i;

	count_sprites = 0;
	i = 0;
	if (!(map = (char **)calloc(sizeof(char *) * config->maxR + 1, 1)))
		printf("Malloc ha fallado en: get_map_reads.c");
	
	while (((get_next_line(fd, &line)) > 0))
	{
		if (who_needs_a_map(line) == 1)
		{
			map[i] = ft_strdup_sustitute_char(line, ' ', '9', config->maxR, &count_sprites);
			i++;
		}
		kill(line);
	}
	if (who_needs_a_map(line) == 1)
		map[i++] = ft_strdup_sustitute_char(line, ' ', '9', config->maxR, &count_sprites);
	kill(line);
	while (i < config->maxR)
		map[i++] = fill_me('9', config->maxR);
	config->numsprites = count_sprites;
	return (map);
}

void		check_map(t_config *config, char **map)
{
	int i;
	int j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while (map[i][j])
		{	//COMPRUEBO PRIMERAS POSICIONES DEL MAPA Y QUE SOLO HAYA UNA POSICION DE JUGADOR
			if (((map[i][j] == 'N') || (map[i][j] == 'S') ||
				(map[i][j] == 'E') || (map[i][j] == 'W')) &&
				(config->player_begin[0] == 0 && config->player_begin[1] == 0))
			{
				comprobar_muros_cerca(config, map, i, j); //necesario para evitar seg fault en parte grafica
				config->player_begin[0] = i;
				config->player_begin[1] = j;
				config->player_pos_begin = map[i][j];
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

void	comprobar_muros_cerca(t_config *config, char **map, int i, int j)
{
	if (map[i-1][j] == 1)
		config->muro_arriba_abajo = 1; //hay muro arriba
	else if (map[i+1][j] == 1)
		config->muro_arriba_abajo = -1; //hay muro abajo
	if (map[i][j-1] == 1)
		config->muro_izq_dcha = 1; //hay muro izq
	else if (map[i][j+1] == 1)
		config->muro_arriba_abajo = -1; //hay muro dcha
}

void		valid_map(char **map)
{ //validamos que en todos los 9 del mapa no haya al lado un 0
	int		i;
	int		j;

	i = 1;
	while (map[i + 1])
	{
		j = 1;
		while (map[i][j + 1]) 
		{
			if ((map[0][j] != '9' && map[0][j] != '1') ||
			(map[i][0] != '9' && map[i][0] != '1') ||
			(map[0][0] != '9' && map[0][0] != '1'))
				print_error("Mapa abierto en primeras lineas\n");
			if ((map[0][j] == '9') &&
			(((map[1][j] != '1') && (map[1][j] != '9')) ||
			((map[0][j + 1] != '1') && (map[0][j + 1] != '9')) ||
			((map[0][j - 1] != '1') && (map[0][j - 1] != '9'))))
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
	printf("| El mapa es VALIDO |\n");
}

int			who_needs_a_map(char *line)
{
	int		i;
	int		j;
	int		coincide;
	char	*chain2;
	int		tab;

	coincide = 0;
	tab = 0;
	chain2 = "102 NSWE\t";
	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		coincide = 0;
		j = 0;
		while (chain2[j] != '\0')
		{
			while (line[i] == '\t')
			{
				tab = 1;
				i++;
			}
			if (line[i] == chain2[j])
				coincide = 1;
			j++;
		}
		if (coincide != 1)
			return(0);
		i++;
	}
	if (coincide == 1)
	{
		if (tab == 1)
			print_error("No tabs en el mapa");
		return (1);
	}
	else
		return (0);
}

char 		*fill_me(char c, int lenght)
{
	char 	*finally;
	int 	i;

	i = 0;
	if(!(finally = ((char *)malloc(sizeof(char) * lenght + 2))))
		printf("Malloc ha fallado en: get_map_reads.c");
	while(i <= lenght)
	{
		finally[i] = c;
		i++;
	}
	finally[i] = '\0';
	return (finally);
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