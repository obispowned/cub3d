#include "includes/cub3d.h"

int				read_line(t_info *info, char *line)
{
	int		i;
	char	**spline;
	int		key;

	i = 0;
	spline = ft_split(line, ' ');
	key = get_key(*spline);
	if (*spline == NULL)
		return (0);
	while (ft_iswhitespace(line[i]))
		i++;
	if (ft_isdigit(line[i]))
		read_map(info, line);
	if (key == K_R)
		fill_resolution(info, spline);
	else if (key >= K_NO && key <= K_S)
		fill_texture(info, spline, key);
	else if (key == K_F || key == K_C)
		select_ambient(info, line, spline, key);
	free(line);
	line = NULL;
	free(spline);
	return (0);
}

int		get_key(char *spline)
{
	if (ft_cmpstr(spline, "R"))
		return (K_R);
	if (ft_cmpstr(spline, "NO"))
		return (K_NO);
	if (ft_cmpstr(spline, "SO"))
		return (K_SO);
	if (ft_cmpstr(spline, "WE"))
		return (K_WE);
	if (ft_cmpstr(spline, "EA"))
		return (K_EA);
	if (ft_cmpstr(spline, "S"))
		return (K_S);
	if (ft_cmpstr(spline, "F"))
		return (K_F);
	if (ft_cmpstr(spline, "C"))
		return (K_C);
	return (0);
}

int		ft_iswhitespace(int c)
{
	if ((c == ' ') || (c == '\t') || (c == '\n')
			|| (c == '\r') || (c == '\v') || (c == '\f'))
		return (1);
	return (0);
}

int		ft_strisnum(char *string)
{
	int i;

	i = 0;
	while (string[i] != '\0')
	{
		if (!(string[i] >= '0' && string[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int			find_char_str(char c, char const *string)
{
	int		i;

	i = 0;
	while(string[i] != '\0')
		{
			if (string[i] == c)
				return (c);
			i++;
		}
	return (0);
}

/*


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




int			fill_map(t_info *info)
{
	int		row;
	int		column;
	char	*temp;
	int		i;
	int		j;
	int		firstwhitespaces;

	firstwhitespaces = 0;
	row = 0;
	temp = 0;
	map_fill_with(info, '4');
	while(row < info->map.max_height)
	{
		temp = ft_lstpop_first(&info->map.buff);
		i = 0;
		firstwhitespaces = 0;
		while(temp[i] != '\0')
			{
				if(ft_iswhitespace(temp[i]))
					info->map.map[row][i] = 4;
				else if (ft_isdigit(temp[i]))
				{
					info->map.map[row][i] = temp[i] - '0';
					firstwhitespaces = 1;
				}
				else if (ft_isascii(temp[i]))
				{
					get_init_position(info, i, row);
					info->map.map[row][i] = 0;
				}
				else
					info->map.map[row][i] = 4;
				i++;
			}
		j++;
		row++;
		temp = NULL;
	}
//	check_map_walls(config);
	free(temp);
	return(0);
}



void		ft_lstbuffadd_back(t_lstbuff **lst, t_lstbuff *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstbufflast(*lst)->next = new;
}

t_lstbuff	*ft_lstbufflast(t_lstbuff *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
char 		*ft_lstpop_first(t_lstbuff **lst)
{
	char *string;
    t_lstbuff *next;

	next = NULL;
    if (*lst == NULL) {
        return NULL;
    }
    next = (*lst)->next;
    string = (*lst)->line;
    free(*lst);
    *lst = next;
    return (string);
}


int			fill_map(t_info *info)
{
	int		row;
	int		column;
	char	*temp;
	int		i;
	int		j;
	int		firstwhitespaces;

	firstwhitespaces = 0;
	row = 0;
	temp = 0;
	map_fill_with(info, '4');
	while(row < info->map.max_height)
	{
		temp = ft_lstpop_first(&info->map.buff);
		i = 0;
		firstwhitespaces = 0;
		while(temp[i] != '\0')
			{
				if(ft_iswhitespace(temp[i]))
					info->map.map[row][i] = 4;
				else if (ft_isdigit(temp[i]))
				{
					info->map.map[row][i] = temp[i] - '0';
					firstwhitespaces = 1;
				}
				else if (ft_isascii(temp[i]))
				{
					get_init_position(info, i, row);
					info->map.map[row][i] = 0;
				}
				else
					info->map.map[row][i] = 4;
				i++;
			}
		j++;
		row++;
		temp = NULL;
	}
//	check_map_walls(config);
	free(temp);
	return(0);
}

t_lstbuff	*ft_lstbufflast(t_lstbuff *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}


*/
