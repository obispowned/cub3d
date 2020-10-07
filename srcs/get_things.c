#include "../header/cub3d.h"

int		get_width(char *line, int i, int width)
{
	char *width_char;
	int width_int;

	width_char = my_strdup("");
	while(line[i] == ' ' || line[i] == 'R')
		i++;
	if(((line[i] >= '0') && (line[i] <= '9')) && ((line[i+1] >= '0') && (line[i+1] <= '9')) &&
	((line[i+2] >= '0') && (line[i+2] <= '9')) && (((line[i+3] >= '0') && (line[i+3] <= '9')) || (line[i+3] <= ' ')) &&
	(width == 0))
	{
		while((line[i] >= '0') && (line[i] <= '9'))
		{
			width_char = my_strjoin(width_char, line[i]);
			i++;
		}
		width_int = atoi(width_char);
		free(width_char);
		return(width_int);
	}
	return(99999);
}

int		get_height(char *line, int i, int width, int height)
{
	char *height_char;
	int height_int;

	height_char = my_strdup("");
	while(line[i] == ' ')
		i++;
	if(((line[i] >= '0') && (line[i] <= '9')) && ((line[i+1] >= '0') && (line[i+1] <= '9')) &&
	((line[i+2] >= '0') && (line[i+2] <= '9')) && (((line[i+3] >= '0') && (line[i+3] <= '9')) || (line[i+3] <= ' ')) &&
	(width != 0 && height == 0))
	{
		while((line[i] >= '0') && (line[i] <= '9'))
		{
			height_char = my_strjoin(height_char, line[i]);
			i++;
		}
		height_int = atoi(height_char);
		free(height_char);
		return(height_int);
	}
	return(99999);
}
