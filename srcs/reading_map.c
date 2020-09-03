#include "includes/cub3d.h"

int				copy_map(t_info *info, char *line)
{
	t_lstbuff	*tmp;
	char 		*newstr;

	newstr = ft_strdup(line);
	tmp = ft_lstbuff_new(newstr);
	ft_lstbuffadd_back(&(info->map.buff),tmp);
	//free(tmp);
	return (0);
}

int				get_size_map(t_info *info, char *line)
{
	int i;

	i = 1;
	info->map.max_height++;
	while (((line[i] >= 48 && line[i] <= 57) || line[i] == ' ' ||
			line[i] == 'N' || line[i] == 'S' || line[i] == 'W' ||
			line[i] == 'E') &&
			line[i])
		i++;
	if (i > info->map.max_widht)
		info->map.max_widht = i;
	return 1;
}

void			allocate_map(t_info  *info)
{
	int		i;

	i = 0;
	info->map.map = ft_calloc(sizeof(int*), info->map.max_height);
	while (i < info->map.max_height)
	{
		info->map.map[i] = ft_calloc(sizeof(int), info->map.max_widht);
		i++;
	}
}


