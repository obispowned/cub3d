#ifndef GAME_H
# define GAME_H

#include "cub3d.h"

/***/
# define PI		3.14159265359
# define INIT_P_PLANE_X 0
# define INIT_P_PLANE_Y 0.66
# define MV_SPEED 0.200
# define ROT_SPEED 0.1345
# define AMB_LIGHT 7

# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define BLUESKY 0X9DF6FF
# define BROWN 0xB8761C
/***/


typedef struct	s_pos
{
	double	x;
	double	y;
}				t_pos;

typedef	struct		s_mlx
{
	void			*ptr; //conecta el software
	void			*win; //administra ventanas
	void			*img; //puntero de imagen que pasaremos a la ventana
	char			*addr; //dirección que representa el comienzo del área de memoria donde se almacena la imagen.
	int				linesize; //número de bytes utilizados para almacenar una línea de la imagen en la memoria. Esto es necesario para moverse de una línea a otra en la imagen.
	int				endian; //indica si el color de píxel en la imagen debe almacenarse en:pequeño (endian == 0)o grande (endian == 1).
	int				bpp;	//bits per pixel
}					t_mlx;

typedef	struct		s_player
{
	t_pos			player_position;
	int				x_grid;
	int				y_grid;
	int				dir_x;
	int				dir_y;
	char			orientation;

}					t_player;

typedef	struct		s_raycasting
{
	int					line;
	int					row;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	int					line_height;
	int					draw_start;
	int					draw_end;
	int					celing_color;
	int					wall_color;
	int					floor_color;
	int					move_up;
	int					move_down;
	int					move_right;
	int					move_left;
	int					textures_on;
	int					current_texture;
	double				movement_speed;
	double				rotation_speed;
	double				pos_x;
	double     			pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	double				time;
	double				old_time;
	double				camera_x;
	double				ray_dir_x;
	double				ray_dir_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double 				side_dist_x;
	double 				side_dist_y;
	double 				perp_wall_dist;
	double				old_dir;
	double				old_plane;
	int					text_orient;
	int					text_x;
	int					text_y;
	double				wall_x;
	double				wall_y;

}					t_raycasting;

void	game_loading(t_config config);
void	create_window(t_config config);


/* Conversiones */
float	radians_to_grads(float radians);
float	grads_to_radians(float grads);

#endif