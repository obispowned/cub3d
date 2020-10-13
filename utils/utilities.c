#include "../header/utils.h"

void		double_kill(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int 		what_is_higher(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
