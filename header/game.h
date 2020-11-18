#ifndef GAME_H
# define GAME_H

# define PI		3.14159265359

#include "cub3d.h"


typedef struct	s_pos
{
	double	x;
	double	y;
}				t_pos;

typedef	struct		s_mlx
{
	void			*ptr;
	void			*win;
	void			*img;
	char			*addr;
	int				linesize;
	int				endian;
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

#endif