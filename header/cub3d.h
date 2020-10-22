#ifndef CUB3D_H
# define CUB3D_H

#include "get_next_line.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct	s_config
{
	int		flag;
	int 	height;
	int		width;
	char 	*NO;
	char 	*SO;
	char 	*EA;
	char 	*WE;
	char 	*S;
	int 	ceil[3];
	int		floor[3];
	int		**map;
	int		map_max_lines;
	int		map_max_rows;
	int		i;
}				t_config;


/* Arrancamos */
t_config 	file_procesator(char *file);
t_config 	load_file(char *file, t_config config);
t_config 	check_file(char *line, t_config config);
t_config 	reset_t_config();

/* funciones para guardar los datos en la estructura - PRIMERA LECTURA*/
t_config 	check_R(char *file, t_config config);
t_config 	check_path(char *file, t_config config);
t_config 	check_ceil_floor(char *line, t_config config);
/*	funciones para guardar, checkear y parsear el mapa - SEGUNDA LECTURA*/
t_config	read_map(char *file, t_config config);
int			who_needs_a_map(char *line);
void		check_map(char **map);
char 		*fill_me(char c, int lenght);
//int			check_me_baby(char c, char *str);

#endif
