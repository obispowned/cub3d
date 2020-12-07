#ifndef GAME_H
# define GAME_H

#include "cub3d.h"
#include <math.h>

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

typedef struct		s_bitmap
{
	unsigned int	filesize;
	unsigned short	reserved1;
	unsigned short	reserved2;
	unsigned int	pixeldataoffset;
	unsigned int	headersize;
	unsigned int	imagewidth;
	unsigned int	imageheight;
	unsigned short	planes;
	unsigned short	bitsperpixel;
	unsigned int	compression;
	unsigned int	imagesize;
	unsigned int	xpixelspermeter;
	unsigned int	ypixelspermeter;
	unsigned int	totalcolors;
	unsigned int	importantcolors;
}					t_bitmap;

typedef struct		s_img
{
	void			*img; //puntero de imagen que pasaremos a la ventana
	char			*addr; //dirección que representa el comienzo del área de memoria donde se almacena la imagen.
	int				linesize; //número de bytes utilizados para almacenar una línea de la imagen en la memoria. Esto es necesario para moverse de una línea a otra en la imagen.
	int				endian; //indica si el color de píxel en la imagen debe almacenarse en:pequeño (endian == 0)o grande (endian == 1).
	int				bpp;	//bits per pixel
}					t_img;

typedef struct		s_sprites
{
	double			x;
	double			y;
	double			distance;
	double			sprite_x;
	double			sprite_y;
	double			invdet;
	double			transform_x;
	double			transform_y;
	int				screen;
	int				height;
	int				width;
	int				drawstart_x;
	int				drawstart_y;
	int				drawend_x;
	int				drawend_y;
	int				stripe;
	t_img			tex;
}					t_sprites;

typedef	struct		s_raycasting
{
	double			player_pos_x; //vector de posicionamiento del jugador
	double			player_pos_y; //vector de posicionamiento del jugador
	double			player_dir_x; //direccion del jugador
	double			player_dir_y; //direccion del jugador
	double			player_plane_x; // plano de la camara. Debe ser perpendicular a la direccion
	double			player_plane_y; // La relacion entre la longitud de la direccion y el plano de la camara determina el FOV.
	char			player_dir;     // Comienzo del jugador NWES
	double			ray_dir_x;		// Direccion del rayo raycast X/Y
	double			ray_dir_y;
	double			dirx;			
	double			diry;
	double			camerax;
	double			wallx; 	//distancia al muro
	double			movespeed;
	int				hit;		// un flag que usamos para determinar si el rayo choco o no para finalizar el bucle o no.
	int				map_rows;
	int				map_lines;
	int				map_x;		//Coordenadas del cuadrado actual donde se encuentra el rayo
	int				map_y;
	double			side_dist_x; // La sidtancia que el rato tiene que viajar desde su pos inicial hasta el primer lado X/Y
	double			side_dist_y;
	double			delta_dist_x; //Distancia que debe recorrer el rayo para ir del lado X/Y al siguiente lado X/Y
	double			delta_dist_y; 
	int				step_x;
	int				step_y;
	int				side;
	int				draw_start;
	int				draw_end;
	double			perp_wall_dist; // longitud del rayo
	int				line_height;
	int				up;
	int				down;
	int				right;
	int				left;
	int				rot_right;
	int				rot_left;
	int				hexaceil;
	int				hexafloor;
	int				tex_height;
	int				tex_width;
	int				tex_x;
	int				tex_y;
	int				tex_id;		//indice para moverme en el array de estructura
	int				tex_side;
	double			*spr_buffer;
	int				drawstartx;
	int				drawendx;
	int				sprtexx;
	int				sprtexy;
	int				spritescreenx;
	int				spriteheight;
	double			spritex;
	double			spritey;
	int				drawstarty;
	int				drawendy;
	int				spritewidth;
	int				stripe;
	double			transformx;
	double			transformy;
	int				d;
	double			invdet;
	int	textnum;
	t_img			tex[12];
	t_sprites		sprite[255];
}					t_raycasting;

typedef	struct		s_mlx
{
	void			*ptr; //conecta el software
	void			*win; //administra ventanas
	int				win_height; //height de config
	int				win_width; //width de config
	int				**finalMap;
	t_img			image;
	t_raycasting	rc;
}					t_mlx;

/* INICIALIZACION */
void		init_raycast_params3(t_mlx *mlx, t_config *config);
void		init_raycast_params2(t_mlx *mlx, t_config *config);
void		init_raycast_params(t_mlx *mlx, t_config *config);
void		init_player(t_mlx *mlx, t_config *config);

/* PREPARANDO GRAFICOS*/
void	create_window(t_mlx *mlx, t_config config);
int		exit_game(t_mlx *mlx);
int		close_win(int keycode, t_mlx *mlx);
void	reset_mlx(t_mlx *mlx, t_config config);

/* Conversiones */
float	radians_to_grads(float radians);
float	grads_to_radians(float grads);

/*	GRAPHIC */
void 	draw_player(t_mlx *mlx, int num);
void 	draw_map(t_mlx *mlx);
void	sky_draw(t_mlx *mlx, int x);
void	floor_draw(t_mlx *mlx, int x);
/**/
void 	init_raycast_params(t_mlx *mlx, t_config *config);
int 	raycasting(int key, t_mlx *mlx);
int 	handle_events(int key, t_mlx *mlx);
static void motionless_2(t_mlx *mlx, int x);
static void motionless_3(t_mlx *mlx);
static void dda(t_mlx *mlx);
static void motionless_4(t_mlx *mlx);
void 	calcule_wall(t_mlx *mlx);
void 	draw_wall(t_mlx *mlx, int x);
void 	load_textures(t_mlx *mlx);
static void load_textures_2(t_mlx *mlx);

#endif