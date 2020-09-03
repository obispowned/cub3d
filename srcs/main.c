#include "includes/cub3d.h"

int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_info	*info;
	t_mlx	mlx;

	int		lastline;
	fd = open(argv[1], O_RDONLY);

	info =  (t_info *)calloc(1, sizeof(t_info));
	while ((info->lastline = get_next_line(fd, &line)) > EOF)
	{
		read_line(info, line);
		if (!info->lastline)
			break;
	}

	printf("hasta aqui funciona\n");
	printf("El valor del width es:  -%i-\n", info->res_x);
	printf("El valor del height es: -%i-\n", info->res_y);
	printf("Los colores del suelo son: -%i- -%i- -%i-\n", info->floor_color[0], info->floor_color[1], info->floor_color[2]);
	printf("Los colores del techo son: -%i- -%i- -%i-\n", info->ceiling_color[0], info->ceiling_color[1], info->ceiling_color[2]);
	printf("La textura del norte es  : %s\n", info->no);
	printf("La textura del sur es    : %s\n", info->so);
	printf("La textura del este es   : %s\n", info->ea);
	printf("La textura del oeste es  : %s\n", info->we);
	printf("La textura del sprinte es: %s\n", info->sp);
	printf("El tamaño del mapa es    : |%ix%i|\n", info->map.max_widht, info->map.max_height);
	printf("La posicion  inicial es  : |%ix%i|\n", info->init_pos.x, info->init_pos.y);
	printf("\nChecks----------:\n\n");
	return(0);
}
