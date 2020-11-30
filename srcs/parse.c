#include "../header/cub3d.h"

t_mapi			parserico(char **map, t_config *config)
{ /*PARSEAMOS EL MAPA EN CHAR A MAPA EN INTS*/
	int		i;
	int		j;

	config->mapa.hexaceil = 0;	//inicializo para evitar errorees
	config->mapa.hexafloor = 0;
	i = 0;
	config->mapa.worldMap = (int **)malloc(sizeof(int *) * config->map_max_lines);
	while (config->map_max_lines > i)
	{
		config->mapa.worldMap[i] = (int *)malloc(sizeof(int) * config->map_max_rows);
		j = 0;
		while (j < config->map_max_rows)
		{
			config->mapa.worldMap[i][j] = (int)(map[i][j] - '0');
			printf("%d", config->mapa.worldMap[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	hexa_ceil_floor_parsing(&config->mapa, config);
	return (config->mapa);
}

void	hexa_ceil_floor_parsing(t_mapi	*mapa, t_config *config)
{
	//CONVERTIR config.ceil y config.floor a hexadecimal y
	//GUARDARLO en mapa.hexaceil y mapa.hexafloor
}