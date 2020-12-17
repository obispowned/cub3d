/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 12:07:16 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/17 13:35:06 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "utils.h"
# include "detect_so.h"

typedef struct		s_mapi
{
	int				**worldmap;
}					t_mapi;

typedef struct		s_config
{
	int				flag;
	int				flag_path;
	int				height;
	int				width;
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
	char			*s;
	int				ceil[3];
	int				floor[3];
	int				**map;
	int				map_max_lines;
	int				map_max_rows;
	int				maxr;
	int				i;
	int				player_begin[2];
	char			player_pos_begin;
	int				save;
	int				numsprites;
	int				muro_arriba_abajo;
	int				muro_izq_dcha;
	unsigned long	hexaceil;
	unsigned long	hexafloor;
	t_mapi			mapa;
}					t_config;

void				final_check(t_config *config);
void				print_values(t_config config);
t_config			file_procesator(char *file, int argc);
t_config			load_file(char *file, t_config config);
t_config			check_file(char *line, t_config config);
void				check_arg(char *argum);
void				reset_t_config(t_config *config);
void				init_config(t_config *config);
t_config			check_r(char *file, t_config config);
t_config			check_path(char *file, t_config config);
char				*give_me_a_path(char *line, int i);
t_config			check_ceil_floor(char *line, t_config config);
void				check_cf(char conmut, char **splitter, t_config *config);
void				error_xpm(char *final);
char				*change_char(char *line, char a, char b);
t_mapi				read_map(char *file, t_config *config);
char				**read_map2(int fd, t_config *config);
int					who_needs_a_map(char *line, char *chain2,
					int tab, int coincide);
int					who_needs_a_map2(int tab, int coincide);
void				check_map(t_config *config, char **map);
void				check_map2(t_config *config, char **map, int i, int j);
void				valid_map(char **map);
void				valid_map2(char **map, int i, int j);
void				print_map(char **map);
char				*change_char(char *line, char a, char b);
char				*fill_me(char c, int lenght);
t_mapi				parserico(char **map, t_config *config);
void				ceil_floor_parsing(t_mapi	*mapa, t_config *config);
unsigned long		creatergb(int r, int g, int b);
int					check_lines(char *line, char *chars);
void				check_params(t_config config);
void				drifting_r_path(char *line, t_config *config);
int					only_this_chars(char *line, char *chars);
void				check_wall(t_config *config, char **map, int i, int j);

#endif
