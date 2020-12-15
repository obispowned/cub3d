/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_reads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 13:05:06 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/15 13:46:03 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

t_mapi			read_map(char *file, t_config *config)
{
	int			fd;
	char		**map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error("Fallo al intentar abrir el archivo .cub");
	config->maxR = (what_is_higher(config->map_max_lines,
	config->map_max_rows)) + 2;
	map = read_map2(fd, config);
	check_map(config, map);
	valid_map(map);
	config->mapa = parserico(map, config);
	close(fd);
	double_kill(map);
	return (config->mapa);
}

char			**read_map2(int fd, t_config *config)
{
	char		*line;
	char		**map;
	int			count_sprites;
	int			i;

	count_sprites = 0;
	i = 0;
	if (!(map = (char **)calloc(sizeof(char *) * config->maxR + 1, 1)))
		printf("Malloc ha fallado en: get_map_reads.c");
	while (((get_next_line(fd, &line)) > 0))
	{
		if (who_needs_a_map(line) == 1)
		{
			map[i] = ft_strdup2(line, ' ', '9', config->maxR, &count_sprites);
			i++;
		}
		kill(line);
	}
	if (who_needs_a_map(line) == 1)
		map[i++] = ft_strdup2(line, ' ', '9', config->maxR, &count_sprites);
	kill(line);
	while (i < config->maxR)
		map[i++] = fill_me('9', config->maxR);
	config->numsprites = count_sprites;
	return (map);
}

void			check_map(t_config *config, char **map)
{
	int			i;
	int			j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
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
				print_error("Ya existe otra posicion para el jugador");
			j++;
		}
		i++;
	}
}

void			valid_map(char **map)
{
	int			i;
	int			j;

	i = 1;
	while (map[i + 1])
	{
		j = 1;
		while (map[i][j + 1])
		{
			valid_map2(map, i, j);
			j++;
		}
		if ((map[i][j] == '9') &&
			(((map[i - 1][j] != '1') && (map[i - 1][j] != '9')) ||
			((map[i + 1][j] != '1') && (map[i + 1][j] != '9')) ||
			((map[i][j - 1] != '1') && (map[i][j - 1] != '9'))))
			print_error("Mapa abierto\n");
		i++;
	}
}

void			valid_map2(char **map, int i, int j)
{
	if ((map[0][j] != '9' && map[0][j] != '1') ||
	(map[i][0] != '9' && map[i][0] != '1') ||
	(map[0][0] != '9' && map[0][0] != '1'))
		print_error("Mapa abierto en primeras lineas\n");
	if ((map[0][j] == '9') &&
	(((map[1][j] != '1') && (map[1][j] != '9')) ||
	((map[0][j + 1] != '1') && (map[0][j + 1] != '9')) ||
	((map[0][j - 1] != '1') && (map[0][j - 1] != '9'))))
		print_error("Mapa abierto\n");
	else if ((map[i][j] == '9') &&
	(((map[i - 1][j] != '1') && (map[i - 1][j] != '9')) ||
	((map[i + 1][j] != '1') && (map[i + 1][j] != '9')) ||
	((map[i][j + 1] != '1') && (map[i][j + 1] != '9')) ||
	((map[i][j - 1] != '1') && (map[i][j - 1] != '9'))))
		print_error("Mapa abierto\n");
}
