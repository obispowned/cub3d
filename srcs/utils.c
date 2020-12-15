#include "../header/cub3d.h"

char			*change_char(char *line, char a, char b)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] == a)
			line[i] = b;
		i++;
	}
	return (line);
}

void			error_xpm(char *final)
{
	if ((final[ft_strlen(final) - 1] != 'm') &&
	(final[ft_strlen(final) - 2] != 'p') &&
	(final[ft_strlen(final) - 3] != 'x') &&
	(final[ft_strlen(final) - 4] != '.'))
		print_error("Formato de texturas incorrecto.");
}