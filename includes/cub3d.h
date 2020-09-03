#ifndef CUB3D_H
# define CUB3D_H

#include "../libft/libft.h"
#include "map.h"
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>
#include <math.h>

# define FOV	0.66

# define WIN_NAME "CUB3D"

# define KEY_W
# define KEY_A
# define KEY_S
# define KEY_D
# define KEY_F
# define KEY_LEFT
# define KEY_RIGHT
# define KEY_ESC

# define MOV_SPEED
# define ROT_SPEED

typedef struct		s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct		s_dir
{
	int				x;
	int				y;
}					t_dir;


typedef struct		s_player
{
	float			posx;
	float			posy;
	float			angle;
	struct s_pos	pos;
	struct s_dir	dir;
}					t_player;

typedef struct		s_maperror
{
	int				firstline;
}					t_maperror;

typedef struct 		s_lstbuff
{
	char				*line;
	struct s_lstbuff	*next;
}					t_lstbuff;

typedef struct		s_map
{
	float			map_size;
	int				**map;
	int				max_height;
	int				max_widht;
	t_lstbuff		*buff;
	t_maperror		errors;

}					t_map;

typedef struct		s_flags
{
	int				resolution;
	int				floor;
	int				cealing;
	int				texturenorth;
	int				texturesouth;
	int				texturewest;
	int				textureeast;
	int				texturesprite;
	int				readingmap;
	int				initpos;
}					t_flags;

typedef struct	s_info
{
	int			lastline;
	int			res_x;
	int			res_y;
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	char		*sp;
	int			floor_color[3];
	int			ceiling_color[3];
	char		init_dir;

	t_map			map;
	t_flags			flags;
	t_dir			init_pos;
}				t_info;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	t_info			*info;
	t_player		*player;
}					t_mlx;

/*reading.c*/
int				read_line(t_info *info, char *line);
int				get_key(char *spline);
int				ft_iswhitespace(int c);
int				ft_strisnum(char *string);
int				find_char_str(char c, char const *string);

/*reading2.c*/
int				fill_resolution(t_info *info, char **spline);
void			fill_texture(t_info *info, char **spline, int key);
int				select_ambient(t_info *info, char *line, char **spline, int key);
int				ft_cmpstr(char *string1, char *string2);
int				fill_ambientcolor(int *color, char **spline);

/*reading3.c*/
void			get_init_position(t_info *config, int widht, int height);
t_lstbuff		*ft_lstbuff_new(char const *content);
void			ft_lstbuffadd_back(t_lstbuff **lst, t_lstbuff *new);
char 			*ft_lstpop_first(t_lstbuff **lst);
int				map_fill_with(t_info *info, char c);
int				check_map_walls(t_info *info);

/*reading_map.c EN MAP.H
int					read_map(t_info *info, char	*line);
int					copy_map(t_info *info, char *line);
int					get_size_map(t_info *info, char *line);
void				allocate_map(t_info *info);
int					fill_map(t_info *info);

reading_map2.c EN MAP.H
t_lstbuff	*ft_lstbufflast(t_lstbuff *lst); */


#endif
