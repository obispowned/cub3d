#include "includes/cub3d.h"

void			get_init_position(t_info *config, int widht, int height)
{
	config->init_pos.x = widht;
	config->init_pos.y = height;
	config->flags.initpos += 1;
}

t_lstbuff	*ft_lstbuff_new(char const *content)
{
	t_lstbuff	*new;

	if (!(new = (t_lstbuff*)malloc(sizeof(content))))
		return (NULL);
	new->line = (char *)content;
	new->next = NULL;
	return (new);
}

void		ft_lstbuffadd_back(t_lstbuff **lst, t_lstbuff *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstbufflast(*lst)->next = new;
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

int			map_fill_with(t_info *info, char c)
{
	int j;
	int i;

	i = 0;
	j = 0;

	while (j < info->map.max_height)
	{
		while (i < info->map.max_widht)
			{
				info->map.map[j][i] = c - '0';
				i++;
			}
		j++;
		i = 0;
	}
	return (0);
}

int			check_map_walls(t_info *info)
{
	int i;
	int j;
	int width;
	int heigh;
	int temp;

	i = 1;
	j = 1;
	width = info->map.max_widht - 1;
	heigh = info->map.max_height -1;

	while (j < heigh)
	{
		while (i < width)
		{
			if (info->map.map[j][i] == 4)
			{
				if (info->map.map[j+1][i] == 0)
					return(printf("mapa abierto\n"));
				if (info->map.map[j][i+1] == 0)
					return(printf("mapa abierto\n"));
				if (info->map.map[j-1][i] == 0)
					return(printf("mapa abierto\n"));
				if (info->map.map[j][i-1] == 0)
					return(printf("mapa abierto\n"));
			}
			i++;
		}
		j++;
		i = 0;
	}
	return (0);
}
