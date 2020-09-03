#include "includes/cub3d.h"

t_lstbuff	*ft_lstbufflast(t_lstbuff *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
