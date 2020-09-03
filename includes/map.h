#ifndef MAP_H
# define MAP_H
# include "cub3d.h"

# define K_R 	1
# define K_NO	2
# define K_SO	3
# define K_WE	4
# define K_EA	5
# define K_S	6
# define K_F	7
# define K_C	8
# define K_MAP	9

# define MAX_WIDHT 2560
# define MAX_HEIGHT 1395
# define MAX_COLOR_RANGE 255

# define VALID_CHAR_MAP " 012NSEW" //Esto no lo utilizo por ahora

int					read_map(t_info *info, char	*line);
int					copy_map(t_info *info, char *line);
int					get_size_map(t_info *info, char *line);
void				allocate_map(t_info *info);
int					fill_map(t_info *info);

t_lstbuff			*ft_lstbufflast(t_lstbuff *lst);
#endif
