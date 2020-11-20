#ifndef GAME_H
# define GAME_H

#include "cub3d.h"

/***/
# define PI		3.14159265359
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

typedef	struct		s_mlx
{
	void			*ptr; //conecta el software
	void			*win; //administra ventanas
	void			*img; //puntero de imagen que pasaremos a la ventana
	char			*addr; //dirección que representa el comienzo del área de memoria donde se almacena la imagen.
	int				linesize; //número de bytes utilizados para almacenar una línea de la imagen en la memoria. Esto es necesario para moverse de una línea a otra en la imagen.
	int				endian; //indica si el color de píxel en la imagen debe almacenarse en:pequeño (endian == 0)o grande (endian == 1).
	int				bpp;	//bits per pixel
	int				win_height; //height de config
	int				win_width; //width de config
//	t_raycasting	rc;
}					t_mlx;

typedef	struct		s_raycasting
{
	double			player_pos_x;
	double			player_pos_y;
	double			player_dir_x;
	double			player_dir_y;
	double			player_plane_x;
	double			player_plane_y;
	double			ray_dir_x;
	double			ray_dir_y;
	double			camerax;
	int				hit;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				step_x;
	int				step_y;
	int				side;
	int				draw_start;
	int				draw_end;
	double			perp_wall_dist;
}					t_raycasting;

/* PREPARANDO GRAFICOS*/
void	game_loading(t_config config);
void	create_window(t_config config);
int		exit_game(t_mlx *mlx);
int		close_win(int keycode, t_mlx *mlx);
void	reset_rc(t_mlx *mlx, t_config config);

/* Conversiones */
float	radians_to_grads(float radians);
float	grads_to_radians(float grads);

/*	RAYCASTEO*/
/*int		raycast(t_mlx *mlx);
int		screenshot(t_mlx *mlx);
void	raycast_2(t_mlx *mlx, int x);
void	raycast_3(t_mlx *mlx);*/



#endif