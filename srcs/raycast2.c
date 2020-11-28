#include <mlx.h>
#include "../header/game.h"
/*
void	dda(t_raycaster *rc)
{
	while (rc->hit == 0)
	{
		if (rc->side_dist_x < rc->side_dist_y)
		{
			rc->side_dist_x += rc->delta_dist_x;
			rc->map_x += rc->stepx;
			rc->side = 0;
		}
		else
		{
			rc->side_dist_y += rc->delta_dist_y;
			rc->map_y += rc->stepy;
			rc->side = 1;
		}
		if (rc->world_map[rc->map_x][rc->map_y] > 0)
			rc->hit = 1;
	}
}

void	sky_draw(t_raycaster *rc, int x)
{
	int y;
	int pixel;
	int color;

	y = 0;
	color = rc->c_color;
	while (y < rc->draw_start)
	{
		pixel = (y * rc->win_x + x) * 4;
		if (rc->endian == 1)
		{
			rc->img_data[pixel + 0] = (color >> 24);
			rc->img_data[pixel + 1] = (color >> 16) & 0xFF;
			rc->img_data[pixel + 2] = (color >> 8) & 0xFF;
			rc->img_data[pixel + 3] = (color) & 0xFF;
		}
		else if (rc->endian == 0)
		{
			rc->img_data[pixel + 0] = (color) & 0xFF;
			rc->img_data[pixel + 1] = (color >> 8) & 0xFF;
			rc->img_data[pixel + 2] = (color >> 16) & 0xFF;
			rc->img_data[pixel + 3] = (color >> 24);
		}
		y++;
	}
}

void	floor_draw(t_raycaster *rc, int x)
{
	int y;
	int pixel;
	int color;

	color = rc->f_color;
	y = rc->draw_start;
	while (y < rc->win_y)
	{
		pixel = (y * rc->win_x + x) * 4;
		if (rc->endian == 1)
		{
			rc->img_data[pixel + 0] = (color >> 24);
			rc->img_data[pixel + 1] = (color >> 16) & 0xFF;
			rc->img_data[pixel + 2] = (color >> 8) & 0xFF;
			rc->img_data[pixel + 3] = (color) & 0xFF;
		}
		else if (rc->endian == 0)
		{
			rc->img_data[pixel + 0] = (color) & 0xFF;
			rc->img_data[pixel + 1] = (color >> 8) & 0xFF;
			rc->img_data[pixel + 2] = (color >> 16) & 0xFF;
			rc->img_data[pixel + 3] = (color >> 24);
		}
		y++;
	}
}

void	draw_wall(t_raycaster *rc, int x)
{
	while (rc->draw_start <= rc->draw_end)
	{
		rc->tex_y = abs((((rc->draw_start * 256 - rc->win_y * 128 +
						rc->line_height * 128) *
						64) /
						rc->line_height) /
						256);
		ft_memcpy(rc->img_data + 4 * rc->win_x * rc->draw_start + x * 4,
					&rc->tex[rc->tex_id].data[rc->tex_y % rc->tex_height *
					rc->tex[rc->tex_id].size_l + rc->tex_x % rc->tex_width *
					rc->tex[rc->tex_id].bpp / 8], sizeof(int));
		rc->draw_start++;
	}
}

void	calcule_wall(t_raycaster *rc)
{
	rc->tex_id = rc->world_map[rc->map_x][rc->map_y] + rc->tex_side;
	if (rc->side == 0)
		rc->wallx = rc->player_pos_y + rc->perp_wall_dist * rc->ray_dir_y;
	else
		rc->wallx = rc->player_pos_x + rc->perp_wall_dist * rc->ray_dir_x;
	rc->wallx -= floor(rc->wallx);
	rc->tex_x = abs((int)(rc->wallx * (double)(64)));
	if (rc->side == 0 && rc->ray_dir_x > 0)
		rc->tex_side = 1;
	else if (rc->side == 0 && rc->ray_dir_x < 0)
		rc->tex_side = 0;
	else if (rc->side == 1 && rc->ray_dir_y > 0)
		rc->tex_side = 2;
	else
		rc->tex_side = 3;
	if (rc->draw_end < 0)
		rc->draw_end = rc->win_y;
}*/