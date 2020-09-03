#include "includes/cub3d.h"

int				fill_resolution(t_info *info, char **spline)
{
	int			i;
	int			resolution[3];

	i = 1;
	if (spline[3] != NULL)
		return (1);
	while (i < 3)
	{
		if (!spline[i])
			resolution[i] = -1;
		else if (!ft_strisnum(spline[i]))
			resolution[i] = 0;
		else
			resolution[i] = atoi(spline[i]);
		i++;
	}
	info->res_x = resolution[1];
	info->res_y = resolution[2];
	info->flags.resolution += 1;
	return (0);
}

void			fill_texture(t_info *info, char **spline, int key)
{
	if (key == K_NO)
	{
		info->no = spline[1];
		info->flags.texturenorth += 1;
	}
	else if (key == K_SO)
	{
		info->so = spline[1];
		info->flags.texturesouth += 1;
	}
	else if (key == K_WE)
	{
		info->we = spline[1];
		info->flags.texturewest += 1;
	}
	else if (key == K_EA)
	{
		info->ea = spline[1];
		info->flags.textureeast += 1;
	}
	else if (key == K_S)
	{
		info->sp = spline[1];
		info->flags.texturesprite += 1;
	}
}

int				select_ambient(t_info *info, char *line, char **spline, int key)
{
	if (key == K_F)
	{
		info->flags.floor += 1;
		return (fill_ambientcolor(info->floor_color, spline));
	}
	else if (key == K_C)
	{
		info->flags.cealing += 1;
		return (fill_ambientcolor(info->ceiling_color, spline));
	}
	else
		return (0);
}


int		ft_cmpstr(char *string1, char *string2)
{
	int i;

	i = 0;
	if (!string1 || !string2)
		return (0);
	while (string1[i] != '\0' || string2[i] != '\0')
	{
		if (string1[i] != string2[i])
			return (0);
		i++;
	}
	return (1);
}

int				fill_ambientcolor(int *color, char **spline)
{
	int			rgb[3];
	int			i;
	char		**numbers;

	i = 0;
	numbers = ft_split(spline[1], ',');
	while (i < 3)
	{
		rgb[i] = ft_atoi(numbers[i]);
		i++;
	}
	i = -1;
	while (i++ < 3)
		color[i] = rgb[i];
	free(numbers);
	return (0);
}
