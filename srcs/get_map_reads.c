/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_reads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:05:06 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/18 11:24:15 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

t_mapi			read_map(char *file, t_config *config)
{
	int			fd;
	char		**map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_err("Fallo al intentar abrir el archivo .cub");
	config->maxr = (what_is_higher(config->map_max_lines,
	config->map_max_rows)) + 2;
	map = read_map2(fd, config, 0);
	check_map(config, map);
	valid_map(map);
	config->mapa = parserico(map, config);
	close(fd);
	double_kill(map);
	return (config->mapa);
}

char			**read_map2(int fd, t_config *config, int count_sprites)
{
	char		*line;
	char		**map;
	int			i;

	i = 0;
	if (!(map = (char **)ft_calloc(sizeof(char *) * config->maxr + 1, 1)))
		printf("Malloc ha fallado en: get_map_reads.c");
	while (((get_next_line(fd, &line)) > 0))
	{
		if (who_needs_a_map(line, "102 NSWE\t", 0, 0) == 1)
		{
			map[i] = ft_strdup2(line, ' ', config->maxr, &count_sprites);
			i++;
		}
		kill(line);
	}
	if (who_needs_a_map(line, "102 NSWE\t", 0, 0) == 1)
		map[i++] = ft_strdup2(line, ' ', config->maxr, &count_sprites);
	kill(line);
	while (i < config->maxr)
		map[i++] = fill_me('9', config->maxr);
	map[i] = NULL;
	config->numsprites = count_sprites;
	return (map);
}

void			check_map(t_config *config, char **map)
{
	int			i;
	int			j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			check_map2(config, map, i, j);
			j++;
		}
		i++;
	}
}

void			check_map2(t_config *config, char **map, int i, int j)
{
	if (((map[i][j] == 'N') || (map[i][j] == 'S') ||
	(map[i][j] == 'E') || (map[i][j] == 'W')) &&
	(config->player_begin[0] == 0 && config->player_begin[1] == 0))
	{
		check_wall(config, map, i, j);
		config->player_begin[0] = j;
		config->player_begin[1] = i;
		config->player_pos_begin = map[i][j];
		map[i][j] = '0';
	}
	else if (((map[i][j] == 'N') || (map[i][j] == 'S') ||
	(map[i][j] == 'E') || (map[i][j] == 'W')) &&
	(config->player_begin[0] != 0 && config->player_begin[1] != 0))
		print_err("Ya existe otra posicion para el jugador");
}

void			check_wall(t_config *config, char **map, int i, int j)
{
	if ((i != 0) && map[i - 1][j] == 1)
		config->muro_arriba_abajo = 1;
	else if (map[i + 1][j] == 1)
		config->muro_arriba_abajo = -1;
	if (map[i][j - 1] == 1)
		config->muro_izq_dcha = 1;
	else if (map[i][j + 1] == 1)
		config->muro_arriba_abajo = -1;
}
