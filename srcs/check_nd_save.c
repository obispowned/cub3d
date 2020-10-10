#include "../header/cub3d.h"

t_config check_R(char *line, t_config config)
{
	char **splitter;
	int i;

	i = 0;
	splitter = ft_split(line, ' ');
	double_kill(splitter);
	return (config);
}
