#ifndef CUB3D_H
# define CUB3D_H

#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct	s_config
{
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
	int		mapR;
}				t_config;


/* Arrancamos */
t_config 	file_procesator(char *file);
t_config 	load_file(char *file, t_config config);
t_config 	check_file(char *line, t_config config);
t_config 	reset_t_config();

/* funciones para guardar los datos en la estructura*/
t_config 	check_R(char *file, t_config config, int i);
//t_config 	check_path(char *file, t_config config, int i);
//t_config 	check_ceil_floor(char *file, t_config config, int i);
//t_config 	check_map(char *file, t_config config, int i);
int			get_width(char *line, int i, int width);
int			get_height(char *line, int i, int width, int height);
int			my_strlen(char *str);
char		*my_strjoin(char *str, char c);
char 		*my_strdup(char *str);

#endif
