/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 11:56:19 by agutierr          #+#    #+#             */
/*   Updated: 2020/12/18 13:17:08 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"
# include <math.h>

# define PI		3.14159265359
# define SPEED 0.06
# define ROT_SPEED 0.0336
# define AMB_LIGHT 7
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define BLUESKY 0X9DF6FF
# define BROWN 0xB8761C

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
	void			*img;
	char			*addr;
	int				linesize;
	int				endian;
	int				bpp;
}					t_img;

typedef struct		s_sprite
{
	int				id;
	double			x;
	double			y;
	double			dist;
	t_img			tex;
}					t_sprite;

typedef	struct		s_raycasting
{
	double			player_pos_x;
	double			player_pos_y;
	double			player_dir_x;
	double			player_dir_y;
	double			player_plane_x;
	double			player_plane_y;
	char			player_dir;
	double			ray_dir_x;
	double			ray_dir_y;
	double			dirx;
	double			diry;
	double			camerax;
	double			wallx;
	double			movespeed;
	int				hit;
	int				map_rows;
	int				map_lines;
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
	int				line_height;
	int				up;
	int				down;
	int				right;
	int				left;
	int				run;
	int				rot_right;
	int				rot_left;
	int				hexaceil;
	int				hexafloor;
	int				tex_height;
	int				tex_width;
	int				tex_x;
	int				tex_y;
	int				tex_id;
	int				tex_side;
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
	int				savebpm;
	double			invdet;
	int				sprites_count;
	double			*spr_buffer;
	int				textnum;
	t_sprite		*sprite;
	t_img			tex[12];
}					t_raycasting;

typedef	struct		s_mlx
{
	void			*ptr;
	void			*win;
	int				win_height;
	int				win_width;
	int				flag_bmp;
	unsigned long	hexa_ceil;
	unsigned long	hexa_floor;
	int				**finalmap;
	t_img			image;
	t_raycasting	rc;
}					t_mlx;

void				init_raycast_params3(t_config *config, t_mlx *mlx);
void				init_raycast_params2(t_config *config, t_mlx *mlx);
void				init_raycast_params(t_mlx *mlx, t_config *config);
void				init_player(t_mlx *mlx, t_config *config);
int					key_press(int key, t_mlx *mlx);
int					key_release(int key, t_mlx *mlx);
void				move_right(t_mlx *mlx);
void				move_left(t_mlx *mlx);
int					handle_events(t_mlx *mlx);
void				handle_events2(t_mlx *mlx);
void				handle_events3(t_mlx *mlx);
void				handle_events4(t_mlx *mlx,
					double olddirx, double oldplanex);
void				create_window(t_mlx *mlx, t_config config);
int					exit_game(t_mlx *mlx);
int					close_win(int keycode, t_mlx *mlx);
void				reset_mlx(t_mlx *mlx, t_config config);
float				radians_to_grads(float radians);
float				grads_to_radians(float grads);
void				draw_player(t_mlx *mlx, int num);
void				draw_map(t_mlx *mlx);
void				sky_draw(t_mlx *mlx, int x);
void				floor_draw(t_mlx *mlx, int x);
void				init_raycast_params(t_mlx *mlx, t_config *config);
int					raycasting(t_mlx *mlx);
void				raycasting2(t_mlx *mlx, int x);
void				sprite_drawing2(t_mlx *mlx, int i, int y);
void				motionless_2(t_mlx *mlx, int x);
void				motionless_3(t_mlx *mlx);
void				dda(t_mlx *mlx);
void				motionless_4(t_mlx *mlx);
void				calcule_wall(t_mlx *mlx);
void				draw_wall(t_mlx *mlx, int x);
void				load_textures(t_mlx *mlx, t_config *config);
void				save_sprites_position(t_mlx *mlx);
void				sprite_casting(t_mlx *mlx);
void				sprite_casting2(t_mlx *mlx);
void				sprite_drawing(t_mlx *mlx, int i, int y);
void				sprite_order(t_mlx *mlx);
void				sprite_preorder(t_mlx *mlx);
int					save_bmp(t_mlx *mlx);

#endif
