#ifndef CUB3D_H
# define CUB3D_H

#include "../get_next_line/get_next_line.h"
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
	int		maxR;
	int		i;
	int		player_begin[2];
}				t_config;

/* Arrancamos */
void		file_procesator(t_config *config, char *file);
void		load_file(char *file, t_config *config);
void		check_file(char *line, t_config *config);
void		reset_t_config();

/* funciones para guardar los datos en la estructura - PRIMERA LECTURA*/
void		check_R(char *file, t_config *config);
void		check_path(char *file, t_config *config);
char		*give_me_a_path(char *line);
void		check_ceil_floor(char *line, t_config *config);
void		check_ceil_floor2(char conmut, char **splitter, t_config *config);

/*	funciones para guardar, checkear y parsear el mapa - SEGUNDA LECTURA*/
void		read_map(char *file, t_config *config); //segunda lectura para sacar el mapa
int			who_needs_a_map(char *line, char *chain2); //devuelve 1 si encontro caracteres de mapa '210 nswe'
void		check_map(t_config *config, char **map); //checkeo de primeras posiciones de mapa y guardo NWSE que no se repita en el mapa

/*	VALIDANDO EL PU;ETERO MAPA*/
void		valid_last_line(int i, char **map);
void		valid_map(char **map); //valido que los 9 no toquen ningun 0
int         valid_map2(char **map, int i, int j);
void		print_map(char **map); // pintamos el mapa y ya

char		*change_char(char *line, char a, char b); //cambia todos los char-a de line por char-b
char 		*fill_me(char c, int lenght, char **map);
int			check_me_baby(char c, char *str);

#endif
