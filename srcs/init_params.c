#include <mlx.h>
#include "../header/game.h"
#include "../header/cub3d.h"

t_config reset_t_config()
{
	t_config config;
	
	config.flag = 0;
	config.i = 0;
	config.height = -1;
	config.width = -1;
	config.NO = NULL;
	config.SO = NULL;
	config.EA = NULL;
	config.WE = NULL;
	config.S = NULL;
	config.map_max_lines = 0;
	config.map_max_rows = 0;
	config.maxR = 0;
	config.player_begin[0] = 0;
	config.player_begin[1] = 0;
	config.numsprites = 0;
	init_config(&config);
	return (config);
}

void	init_config(t_config *config)
{
	int	i;

	i = 0;
	config->player_pos_begin = '\0';
	while (i < 3)
	{
		config->ceil[i] = -1;
		config->floor[i] = -1;
		i++;
	}
	config->hexaceil = 0;
	config->hexafloor = 0;
}



/*
void	init_initialparams(t_validmap *map)
{
	int i;

	i = 0;
	map->m_top = 0;
	map->m_bot = 0;
	map->m_line = 0;
	map->prev_line = "";
	map->map_width = 0;
	map->player_dir = '\0';
	map->colum_spaces = (int *)malloc(sizeof(int) * 255);
	map->colum_nums = (int *)malloc(sizeof(int) * 255);
	map->last_0 = 0;
	while (i < 255)
	{
		map->colum_spaces[i] = 0;
		map->colum_nums[i] = 0;
		i++;
	}
}*/