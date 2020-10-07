#include "../header/cub3d.h"

t_config check_R(char *line, t_config config, int i)
{
	while (line[i] != '\0')
	{
		while(line[i] == ' ' || line[i] == 'R')
			i++;
		if(((line[i] >= '0') && (line[i] <= '9')) && ((line[i+1] >= '0') && (line[i+1] <= '9')) &&
		((line[i+2] >= '0') && (line[i+2] <= '9')) && (((line[i+3] >= '0') && (line[i+3] <= '9')) || (line[i+3] <= ' ')) &&
		(config.width == 0 && config.height == 0))
			config.width = get_width(line, i, config.width); /******/
		else if(((line[i] >= '0') && (line[i] <= '9')) && ((line[i+1] >= '0') && (line[i+1] <= '9')) &&
		((line[i+2] >= '0') && (line[i+2] <= '9')) && (((line[i+3] >= '0') && (line[i+3] <= '9')) || (line[i+3] <= ' ')) &&
		config.width != 0 && config.height == 0)
			config.height = get_height(line, i, config.width, config.height); /*******/
		else
		{
			printf("ERROR: Ponga una sola resolucion correcta");
			exit(-1);
		}
		i++;
	}
	return(config);
}

t_config check_path(char *line, t_config config, int i)
{
	while (line[i] != '\0')
	{
		while(line[i] == ' ')
			i++;
		if(((line[i] >= '0') && (line[i] <= '9')) && ((line[i+1] >= '0') && (line[i+1] <= '9')) &&
		((line[i+2] >= '0') && (line[i+2] <= '9')) && (((line[i+3] >= '0') && (line[i+3] <= '9')) || (line[i+3] <= ' ')) &&
		config.width == 0)
			config.width = get_width(line, i, config.width);
		else if(((line[i] >= '0') && (line[i] <= '9')) && ((line[i+1] >= '0') && (line[i+1] <= '9')) &&
		((line[i+2] >= '0') && (line[i+2] <= '9')) && (((line[i+3] >= '0') && (line[i+3] <= '9')) || (line[i+3] <= ' ')) &&
		config.width != 0 && config.height == 0)
			config.height = get_height(line, i, config.width, config.height);
		else
		{
			printf("ERROR: Ponga una sola resolucion correcta");
			exit(-1);
		}
		i++;
	}
	return (config);
}

/*
t_config check_ceil_floor(char *line, t_config config, int i)
{

}

t_config check_map(char *line, t_config config, int i)
{

}*/
