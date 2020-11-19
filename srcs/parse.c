#include "../header/cub3d.h"

t_mapi			parserico(char **map, t_config *config)
{ /*CONTINUAR DESDE AQUI*/
	t_mapi	mapa;
	int		i;
	int		j;

	mapa.hexaceil = 0;	//inicializo para evitar errorees
	mapa.hexafloor = 0;
	i = 0;
	mapa.worldMap = (int **)malloc(sizeof(int *) * config->map_max_lines);
	while (config->map_max_lines > i)
	{
		mapa.worldMap[i] = (int *)malloc(sizeof(int) * config->map_max_rows);
		j = 0;
		while (j < config->map_max_rows)
		{
			mapa.worldMap[i][j] = (int)(map[i][j] - '0');
			printf("%d", mapa.worldMap[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	hexa_ceil_floor_parsing(&mapa, config);
	return (mapa);
}

void	hexa_ceil_floor_parsing(t_mapi	*mapa, t_config *config)
{
	//CONVERTIR config.ceil y config.floor a hexadecimal y
	//GUARDARLO en mapa.hexaceil y mapa.hexafloor
}